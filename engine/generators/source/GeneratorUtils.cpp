#include "CoordUtils.hpp"
#include "FeatureGenerator.hpp"
#include "GeneratorUtils.hpp"
#include "Game.hpp"
#include "ItemGenerationManager.hpp"
#include "Log.hpp"
#include "MapUtils.hpp"
#include "RNG.hpp"
#include "SettlementGeneratorUtils.hpp"
#include "ShopGenerator.hpp"
#include "SpringsGenerator.hpp"
#include "StreamGenerator.hpp"
#include "TileGenerator.hpp"
#include "WildflowerGardenGenerator.hpp"

using namespace std;

// Implicit is an extra padding tile - when creating a shop/bazaar, there's
// an "interior".  It's assumed that the bazaar coordinates define the exterior,
// so the interior (where the items are laid out) will be slightly smaller.
const int GeneratorUtils::STRUCTURE_MIN_WIDTH = 4;
const int GeneratorUtils::STRUCTURE_MAX_WIDTH = 8;
const int GeneratorUtils::STRUCTURE_MIN_HEIGHT = 3;
const int GeneratorUtils::STRUCTURE_MAX_HEIGHT = 7;

// Hidden away by protected access
GeneratorUtils::GeneratorUtils()
{
}

GeneratorUtils::~GeneratorUtils()
{
}

// Create a circle.  Check to ensure that the radius won't take us off
// the boundaries.
void GeneratorUtils::generate_circle(MapPtr map, const int row_centre, const int col_centre, const int radius, const TileType tile_type)
{
  Dimensions dim = map->size();
  int rows = dim.get_y();
  int cols = dim.get_x();
  bool generate = true;

  vector<Coordinate> circle_coords = CoordUtils::get_circle_coordinates(row_centre, col_centre, radius);

  // Circle in range?
  for (const Coordinate& c : circle_coords)
  {
    if (!(c.first >= 0 && c.first <= rows - 1 && c.second >= 0 && c.second <= cols - 1))
    {
      generate = false;
      break;
    }
  }

  // If the circle's in range, generate it.
  if (generate)
  {
    for (const Coordinate& c : circle_coords)
    {
      generate_tile(map, c.first, c.second, tile_type);
    }
  }
}

bool GeneratorUtils::position_in_range(const int min, const int max, const int actual)
{
  return (actual >= min) && (actual <= max);
}

// I was using this sort of thing a lot, so I'm moving it here...
// Generates a building without any additional feature - useful for generating
// an empty building when you don't want house features like beds, pots, etc
void GeneratorUtils::generate_building(const MapPtr map, const int start_row, const int start_col, const int height, const int width, const TileType wall_tile_type)
{
  TileGenerator tg;

  int end_row = start_row + height;
  int end_col = start_col + width;

  TilePtr current_tile;

  for (int row = start_row; row < end_row; row++)
  {
    for (int col = start_col; col < end_col; col++)
    {
      // Generate a wall at the borders, floor otherwise.
      if ((row == start_row) || (row == (end_row - 1))
       || (col == start_col) || (col == (end_col - 1)))
      {
        current_tile = tg.generate(wall_tile_type);
      }
      else
      {
        current_tile = tg.generate(TileType::TILE_TYPE_DUNGEON);
      }

      map->insert(row, col, current_tile);
    }
  }
}

vector<pair<Coordinate, Coordinate>> GeneratorUtils::generate_rectangles(const MapPtr map, const int start_row, const int start_col, const int end_row, const int end_col, const int num_rectangles, const TileType rect_fill_type)
{
  vector<pair<Coordinate, Coordinate>> rectangles;

  if (map != nullptr)
  {
    int rect_gen = 0;
    int attempts = 0;
    int max_attempts = num_rectangles * 10;

    while (rect_gen < num_rectangles && attempts < max_attempts)
    {
      attempts++;

      int rect_height = RNG::range(3, 6);
      int rect_width = RNG::range(3, 16);

      // Guard against the squares being larger than the generatable area.
      if (((end_row - rect_height) < start_row) || ((end_col - rect_width) < start_col))
      {
        continue;
      }
      else
      {
        Coordinate rect_tl = make_pair(0,0);
        Coordinate rect_br = make_pair(0,0);

        rect_tl = make_pair(RNG::range(start_row, end_row - rect_height - 1), RNG::range(start_col, end_col - rect_width - 1));
        rect_br = {rect_tl.first + rect_height, rect_tl.second + rect_width};

        fill(map, rect_tl, rect_br, rect_fill_type);
        rectangles.push_back(make_pair(rect_tl, rect_br));

        rect_gen++;
      }
    }
  }

  return rectangles;
}

void GeneratorUtils::generate_door(const MapPtr map, const int row, const int col)
{
  TileGenerator tg;

  TilePtr floor = tg.generate(TileType::TILE_TYPE_DUNGEON);
  FeaturePtr door = FeatureGenerator::generate_door();

  if (floor && map)
  {
    floor->set_feature(door);
    map->insert(row, col, floor);
  }
}

// Generate a tile of a given type at a given location on a given map (that's a given).
void GeneratorUtils::generate_tile(const MapPtr map, const int row, const int col, const TileType tile_type)
{
  TileGenerator tg;
  TilePtr tile = tg.generate(tile_type);
  if (tile && map)
  {
    map->insert(row, col, tile);
  }
}

void GeneratorUtils::generate_fire_pillar(const MapPtr map, const int row, const int col)
{
  FeaturePtr fire_pillar = FeatureGenerator::generate_fire_pillar();
  TilePtr tile = map->at(row, col);

  if (tile)
  {
    tile->set_feature(fire_pillar);
  }
}

TilePtr GeneratorUtils::generate_grave_or_barrow()
{
  TilePtr generated_tile;
  TileGenerator tg;

  if (RNG::percent_chance(35))
  {
    generated_tile = tg.generate(TileType::TILE_TYPE_BARROW);
  }
  else
  {
    generated_tile = tg.generate(TileType::TILE_TYPE_GRAVE);
  }

  return generated_tile;
}

void GeneratorUtils::generate_fountain(const MapPtr map, const int row, const int col)
{
  FeaturePtr fountain = FeatureGenerator::generate_fountain();
  TilePtr tile = map->at(row, col);

  if (tile)
  {
    tile->set_feature(fountain);
  }
}

// Generate a number of random traps.  Only consider tiles that do not already
// have a feature, and exclude those tiles with movement multipliers of 0.
// Return value is the number of traps generated.
int GeneratorUtils::generate_traps(const MapPtr map, const int num_traps)
{
  int num_gen = 0;

  int trap_y = 0, trap_x = 0;

  Game& game = Game::instance();
  vector<TrapPtr> traps = game.get_trap_info_ref();

  Dimensions dim = map->size();
  int max_y = dim.get_y() - 1;
  int max_x = dim.get_x() - 1;

  for (int i = 0; i < num_traps; i++)
  {
    // Try a few attempts each
    for (int j = 0; j < 2; j++)
    {
      trap_y = RNG::range(0, max_y);
      trap_x = RNG::range(0, max_x);

      TilePtr tile = map->at(trap_y, trap_x);

      if ((tile != nullptr) && (tile->get_movement_multiplier() > 0) && !tile->has_feature())
      {
        GeneratorUtils::generate_trap(map, trap_y, trap_x, traps);
        break;
      }
    }
  }

  return num_gen;
}

// Generate a trap with a given ID and place it at the given coordinates.
// Don't generate the trap if it's in a shop.
void GeneratorUtils::generate_trap(const MapPtr map, const int row, const int col, const vector<TrapPtr>& traps, const string& trap_id, const bool trap_triggered)
{
  if (map == nullptr)
  {
    Log::instance().error("Cannot generate traps on a null map.");
  }

  if (!traps.empty())
  {
    TrapPtr selected_trap;

    for (TrapPtr trap : traps)
    {
      if (trap && trap->get_id() == trap_id)
      {
        selected_trap = trap;
        break;
      }
    }

    if (selected_trap != nullptr)
    {
      const auto& shops = map->get_shops_ref();

      if (!shops.empty())
      {
        for (auto s_it : shops)
        {
          if (CoordUtils::is_contained(s_it.second.get_start(), s_it.second.get_end(), { row, col }))
          {
            return;
          }
        }
      }

      // Make a copy of the one provided.
      TrapPtr new_trap = TrapPtr(selected_trap->clone_and_randomize_uses());
      new_trap->set_triggered(trap_triggered);

      // Set the new copy on to the tile.
      TilePtr tile = map->at(row, col);

      if (tile != nullptr)
      {
        tile->set_feature(new_trap);

        ostringstream ss;
        ss << "GeneratorUtils::generate_trap - trap generated at (" << row << "," << col << ").";
        Log::instance().debug(ss.str());
      }
    }
  }
}

// Generate a random trap from the list and place it at the given coordinates.
void GeneratorUtils::generate_trap(const MapPtr map, const int row, const int col, const vector<TrapPtr>& traps, const bool trap_triggered)
{
  if (!traps.empty())
  {
    size_t trap_size = traps.size();

    uint idx = RNG::range(0, trap_size - 1);
    TrapPtr trap = traps.at(idx);

    if (trap != nullptr)
    {
      const auto& shops = map->get_shops_ref();

      if (!shops.empty())
      {
        for (auto s_it : shops)
        {
          if (CoordUtils::is_contained(s_it.second.get_start(), s_it.second.get_end(), { row, col }))
          {
            return;
          }
        }
      }

      // Make a copy of the one provided.
      trap = TrapPtr(trap->clone_and_randomize_uses());
      trap->set_triggered(trap_triggered);

      // Set the new copy on to the tile.
      TilePtr tile = map->at(row, col);

      if (tile != nullptr)
      {
        tile->set_feature(trap);

        ostringstream ss;
        ss << "GeneratorUtils::generate_trap - trap generated at (" << row << "," << col << ").";
        Log::instance().debug(ss.str());
      }
    }
  }
}

void GeneratorUtils::generate_bazaar_if_necessary(const MapPtr map, const string& bazaar_property)
{
  if (map != nullptr && !bazaar_property.empty())
  {
    Dimensions d = map->size();
    int max_attempts = 15;

    for (int i = 0; i < max_attempts; i++)
    {
      int width = RNG::range(STRUCTURE_MIN_WIDTH, STRUCTURE_MAX_WIDTH);
      int height = RNG::range(STRUCTURE_MIN_HEIGHT, STRUCTURE_MAX_HEIGHT);

      // Try to place the bazaar somewhere on the map.
      int y_start = RNG::range(0, d.get_y() - height - 1);
      int x_start = RNG::range(0, d.get_x() - width - 1);

      if (are_tiles_ok_for_structure(map, y_start, x_start, height, width))
      {
        Building bazaar({ y_start, x_start }, { y_start + height, x_start + width }, { y_start, x_start });
        ShopGenerator sg;

        sg.generate_shop(map, bazaar);
        map->set_permanent(true);

        break;
      }
    }
  }
}

void GeneratorUtils::generate_hermitage_if_necessary(MapPtr map, const string& hermitage_property)
{
  if (map != nullptr && !hermitage_property.empty())
  {
    Dimensions d = map->size();
    int max_attempts = 15;

    for (int i = 0; i < max_attempts; i++)
    {
      int width = RNG::range(STRUCTURE_MIN_WIDTH, STRUCTURE_MAX_WIDTH);
      int height = RNG::range(STRUCTURE_MIN_HEIGHT, STRUCTURE_MAX_HEIGHT);

      // Try to place the bazaar somewhere on the map.
      int y_start = RNG::range(0, d.get_y() - height - 1);
      int x_start = RNG::range(0, d.get_x() - width - 1);

      if (are_tiles_ok_for_structure(map, y_start, x_start, height, width))
      {
        int offset = RNG::range(1, 3);
        Coordinate wildfl_start = { y_start - offset, x_start - offset };
        Coordinate wildfl_end = { y_start + height + offset, x_start + width + offset };
        WildflowerGardenGenerator wgg;
        wgg.generate(map, wildfl_start, wildfl_end);

        Coordinate st_coord = { y_start, x_start };
        Coordinate end_coord = { y_start + height, x_start + width };
        vector<CardinalDirection> door_dirs = MapUtils::get_unblocked_door_dirs(map, st_coord, end_coord);

        if (!door_dirs.empty())
        {
          vector<string> creatures = {};
          vector<string> items = {};
          vector<ClassIdentifier> features = { ClassIdentifier::CLASS_ID_BED };
          vector<ClassIdentifier> potential_features = { ClassIdentifier::CLASS_ID_WHEEL_AND_LOOM, ClassIdentifier::CLASS_ID_TABLE };

          for (const auto& pf : potential_features)
          {
            if (RNG::percent_chance(50))
            {
              features.push_back(pf);
            }
          }

          // Hermit's long dead
          if (RNG::percent_chance(50))
          {
            items.push_back(ItemIdKeys::ITEM_ID_INTACT_SKELETON);
          }
          else
          {
            creatures.push_back(CreatureID::CREATURE_ID_HERMIT);
          }

          ItemGenerationConstraints igc;
          igc.set_item_type_restrictions({ ItemType::ITEM_TYPE_SPELLBOOK, ItemType::ITEM_TYPE_SCROLL });
          igc.set_min_danger_level(1);
          igc.set_max_danger_level(map->get_danger());
          ItemGenerationManager igm;
          vector<string> potential_items = igm.get_item_ids(igm.generate_item_generation_map(igc));

          if (!potential_items.empty())
          {
            int num_readables = RNG::range(2, 4);
            for (int i = 0; i < num_readables; i++)
            {
              items.push_back(potential_items[RNG::range(0, potential_items.size() - 1)]);
            }
          }

          BuildingGenerationParameters bgp(y_start, y_start + height, x_start, x_start + width, door_dirs[RNG::range(0, door_dirs.size()-1)], false, features, creatures, items, TileType::TILE_TYPE_EARTH);
          SettlementGeneratorUtils::generate_building_if_possible(map, bgp, vector<Building>(), 100, false);

          map->set_permanent(true);
          break;
        }
      }
    }
  }
}

bool GeneratorUtils::are_tiles_ok_for_structure(MapPtr map, const int y_start, const int x_start, const int height, const int width)
{
  bool bzr_ok = true;

  if (map != nullptr)
  {
    for (int y = y_start; y < y_start + height; y++)
    {
      for (int x = x_start; x < x_start + width; x++)
      {
        TilePtr tile = map->at(y, x);

        if (!(tile && tile->get_tile_super_type() == TileSuperType::TILE_SUPER_TYPE_GROUND && tile->get_movement_multiplier() > 0))
        {
          bzr_ok = false;
          break;
        }
      }
    }
  }

  return bzr_ok;
}

void GeneratorUtils::fill(MapPtr map, const Coordinate& start_coord, const Coordinate& end_coord, const TileType tile_type)
{
  TileGenerator tg;

  if (map != nullptr)
  {
    for (int row = start_coord.first; row <= end_coord.first; row++)
    {
      for (int col = start_coord.second; col <= end_coord.second; col++)
      {
        TilePtr tile = tg.generate(tile_type);
        map->insert(row, col, tile);
      }
    }
  }
}

void GeneratorUtils::add_random_stream_or_springs(MapPtr result_map, const int pct_chance_stream, const int pct_chance_springs)
{
  int additional_random_feature = RNG::range(1, 100);

  if (additional_random_feature < pct_chance_stream)
  {
    add_random_stream(result_map);
  }
  else
  {
    additional_random_feature = RNG::range(1, 100);

    if (additional_random_feature < pct_chance_springs)
    {
      add_random_springs(result_map);
    }
  }
}

void GeneratorUtils::add_random_springs(MapPtr result_map)
{
  Dimensions dim = result_map->size();
  int springs_size = RNG::dice(3, 2); // min size should be 3.
  int start_y = RNG::range(1, (dim.get_y() - springs_size - 1));
  int start_x = RNG::range(1, (dim.get_x() - springs_size - 1));
  int rand_type = RNG::dice(1, 2);
  SpringsType springs_type = SpringsType::SPRINGS_TYPE_TALL;

  if (rand_type == 2)
  {
    springs_type = SpringsType::SPRINGS_TYPE_WIDE;
  }

  SpringsGenerator::generate(result_map, start_y, start_x, springs_size, springs_type);
}

void GeneratorUtils::add_random_stream(MapPtr map)
{
  StreamGenerator::generate(map);
}

