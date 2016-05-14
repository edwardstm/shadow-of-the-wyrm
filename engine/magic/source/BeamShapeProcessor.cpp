#include "AnimationTranslator.hpp"
#include "BeamShapeProcessor.hpp"
#include "BeamSpellTranslator.hpp"
#include "CoordUtils.hpp"
#include "CurrentCreatureAbilities.hpp"
#include "DirectionUtils.hpp"
#include "Game.hpp"
#include "MapUtils.hpp"
#include "TileMagicChecker.hpp"

using namespace std;

map<Direction, Direction> BeamShapeProcessor::cardinal_reflection_map;

BeamShapeProcessor::BeamShapeProcessor()
{
  if (cardinal_reflection_map.empty())
  {
    initialize_reflection_maps();
  }
}

// Set up the directions for the reflection direction lookup maps.
void BeamShapeProcessor::initialize_reflection_maps()
{
  cardinal_reflection_map.clear();

  initialize_cardinal_reflection_map();
}

// Set up the reflection directions when striking a corner tile.
void BeamShapeProcessor::initialize_cardinal_reflection_map()
{
  cardinal_reflection_map = std::map<Direction, Direction>{{Direction::DIRECTION_NORTH, Direction::DIRECTION_SOUTH},
                                                           {Direction::DIRECTION_EAST, Direction::DIRECTION_WEST},
                                                           {Direction::DIRECTION_WEST, Direction::DIRECTION_EAST},
                                                           {Direction::DIRECTION_SOUTH, Direction::DIRECTION_NORTH}};
}

pair<vector<TilePtr>, Animation> BeamShapeProcessor::get_affected_tiles_and_animation_for_spell(MapPtr map, const Coordinate& caster_coord, const Direction d, const Spell& spell)
{
  Animation animation;

  uint radius = spell.get_shape().get_radius();
  Coordinate current_coord = caster_coord;  
  vector<Coordinate> beam_coords = CoordUtils::get_beam_coordinates(current_coord, d, radius);

  // Element 0, 1, ... in each of these vectors is for a particular beam.
  vector<vector<TilePtr>> per_beam_affected_tiles;
  vector<vector<pair<DisplayTile, vector<Coordinate>>>> per_beam_movement_paths;

  for (const Coordinate& beam_start_coord : beam_coords)
  {
    auto beam_pair = create_beam(map, spell, beam_start_coord, caster_coord, d);

    per_beam_affected_tiles.push_back(beam_pair.first);
    per_beam_movement_paths.push_back(beam_pair.second);
  }

  size_t largest_at = 0;
  size_t largest_mp = 0;

  for (const auto& at : per_beam_affected_tiles)
  {
    size_t cur_size = at.size();

    if (cur_size > largest_at)
    {
      largest_at = cur_size;
    }
  }

  for (const auto& mp : per_beam_movement_paths)
  {
    size_t cur_size = per_beam_affected_tiles.size();

    if (cur_size > largest_mp)
    {
      largest_mp = cur_size;
    }
  }

  // Now that the largest number of affected tiles/movement path has been
  // determined, loop through the collections.  For 0 to the largest_size-1,
  // create a combined list of affected tiles and movement paths.
  auto multi_beam_pair = create_multi_beam(per_beam_affected_tiles, per_beam_movement_paths, largest_at, largest_mp);

  // JCD TODO: For each coord in coords, create the beam, then combine them to
  // make a reasonable animation...

  // For regular beams, the current direction will always be the passed-in
  // direction (the beam will "fizzle out" if it hits a blocking tile).  For
  // reflective beams (a subclass), the current direction will change as the
  // beam bounces.
  auto beam_pair = create_beam(map, spell, current_coord, caster_coord, d);

  // Create the animation using the default movement animation mechanism.
  CreaturePtr caster = map->at(caster_coord)->get_creature();
  // JCD FIXME uncomment when done!
  // return create_affected_tiles_and_animation(caster, map, multi_beam_pair.first, multi_beam_pair.second);
  return create_affected_tiles_and_animation(caster, map, beam_pair.first, beam_pair.second);
}

pair<vector<TilePtr>, vector<pair<DisplayTile, vector<Coordinate>>>> BeamShapeProcessor::create_beam(MapPtr map, const Spell& spell, const Coordinate& coord, const Coordinate& caster_coord, const Direction d)
{
  pair<vector<TilePtr>, vector<pair<DisplayTile, vector<Coordinate>>>> results;
  vector<TilePtr> affected_tiles;
  vector<pair<DisplayTile, vector<Coordinate>>> movement_path;
  TileMagicChecker tmc;
  BeamSpellTranslator bst;

  Coordinate current_coord = coord;
  Direction current_direction = d;
  uint range = spell.get_range();
  DisplayTile dt = bst.create_display_tile(spell.get_range(), current_direction, spell.get_colour());

  uint count = 0;

  while (count < range)
  {
    Coordinate c = CoordUtils::get_new_coordinate(current_coord, current_direction);

    TilePtr tile = map->at(c);

    // If casting a reflective spell around the corners of an open map, handle
    // that appropriately (by not looping infinitely).
    if (tile == nullptr)
    {
      break;
    }

    // Check to see if the tile blocks the spell.
    if (tmc.does_tile_block_spell(tile))
    {
      if (should_beam_reflect())
      {
        // The beam is reflective. Update the direction based on the the
        // incoming direction and map characteristics.
        current_direction = get_new_beam_direction_after_impact(current_direction, c, map);

        // Ensure that each reflection also takes one off the range (again,
        // to prevent looping indefinitely).
        count++;

        // Edge case: caster is standing by the wall.
        if (current_coord == caster_coord)
        {
          current_coord = c;
        }

        // Update the symbol for the display
        dt = bst.create_display_tile(spell.get_range(), current_direction, spell.get_colour());

        // The beam bounces off this tile, but it does not affect it - exclude it from
        // the animation and from processing.
        continue;
      }
      else
      {
        // The beam dissipates after striking the obstacle.
        break;
      }
    }

    // Update the current coordinate in the beam, and add the tile to the
    // list of affected tiles.
    current_coord = c;
    affected_tiles.push_back(tile);
    vector<Coordinate> beam_vec;
    beam_vec.push_back(current_coord);
    movement_path.push_back(make_pair(dt, beam_vec));
    count++; // Didn't bounce - update the spell range counter.
  }

  results.first = affected_tiles;
  results.second = movement_path;

  return results;
}

pair<vector<TilePtr>, vector<pair<DisplayTile, vector<Coordinate>>>> BeamShapeProcessor::create_multi_beam(const vector<vector<TilePtr>>& per_beam_affected_tiles, const vector<vector<pair<DisplayTile, vector<Coordinate>>>>& per_beam_movement_paths, const size_t largest_at, const size_t largest_mp)
{
  pair<vector<TilePtr>, vector<pair<DisplayTile, vector<Coordinate>>>> result;

  // ...

  return result;
}


// By default, beams do not reflect - only instances of ReflectiveBeam should.
bool BeamShapeProcessor::should_beam_reflect() const
{
  return false;
}

// Get the new beam direction after an impact.
Direction BeamShapeProcessor::get_new_beam_direction_after_impact(const Direction old_direction, const Coordinate& current_coord, MapPtr map)
{
  if (DirectionUtils::is_cardinal(old_direction))
  {
    return cardinal_reflection_map[old_direction];
  }

  // It's not cardinal, so we're dealing with an ordinal direction
  // (NW, SE, etc).  Figure out the correct reflection direction.
  if (old_direction == Direction::DIRECTION_NORTH_EAST)
  {
    return get_ne_reflection(current_coord, map);
  }
  else if (old_direction == Direction::DIRECTION_NORTH_WEST)
  {
    return get_nw_reflection(current_coord, map);
  }
  else if (old_direction == Direction::DIRECTION_SOUTH_EAST)
  {
    return get_se_reflection(current_coord, map);
  }
  else if (old_direction == Direction::DIRECTION_SOUTH_WEST)
  {
    return get_sw_reflection(current_coord, map);
  }

  // Should never actually get to this, based on the above logic:
  return old_direction;
}

Direction BeamShapeProcessor::get_ne_reflection(const Coordinate& current_coord, MapPtr map)
{
  TileMagicChecker tmc;

  Direction reflection;

  // Inside/outside the corner
  if (MapUtils::is_corner(current_coord, Direction::DIRECTION_NORTH_EAST, map) || (MapUtils::is_corner(current_coord, Direction::DIRECTION_SOUTH_WEST, map)))
  {
    reflection = Direction::DIRECTION_SOUTH_WEST;
  }
  else
  {
    // Are we firing at a northern wall?  Reflect south-east.
    TilePtr north_wall_tile = map->at(CoordUtils::get_new_coordinate(current_coord, Direction::DIRECTION_WEST));

    if (north_wall_tile && tmc.does_tile_block_spell(north_wall_tile))
    {
      reflection = Direction::DIRECTION_SOUTH_EAST;
    }
    else
    {
      reflection = Direction::DIRECTION_NORTH_WEST;
    }
  }

  return reflection;
}

Direction BeamShapeProcessor::get_nw_reflection(const Coordinate& current_coord, MapPtr map)
{
  TileMagicChecker tmc;

  Direction reflection;

  // Inside/outside the corner
  if (MapUtils::is_corner(current_coord, Direction::DIRECTION_NORTH_WEST, map) || MapUtils::is_corner(current_coord, Direction::DIRECTION_SOUTH_EAST, map))
  {
    reflection = Direction::DIRECTION_SOUTH_EAST;
  }
  else
  {
    // Are we firing at a northern wall?  Reflect south-west.
    TilePtr north_wall_tile = map->at(CoordUtils::get_new_coordinate(current_coord, Direction::DIRECTION_EAST));

    if (north_wall_tile && tmc.does_tile_block_spell(north_wall_tile))
    {
      reflection = Direction::DIRECTION_SOUTH_WEST;
    }
    else
    {
      reflection = Direction::DIRECTION_NORTH_EAST;
    }
  }

  return reflection;
}

Direction BeamShapeProcessor::get_se_reflection(const Coordinate& current_coord, MapPtr map)
{
  TileMagicChecker tmc;
  
  Direction reflection;

  // Inside/outside the corner
  if (MapUtils::is_corner(current_coord, Direction::DIRECTION_SOUTH_EAST, map) || MapUtils::is_corner(current_coord, Direction::DIRECTION_NORTH_WEST, map))
  {
    reflection = Direction::DIRECTION_NORTH_WEST;
  }
  else
  {
    // Are we firing at a southern wall?  Reflect north-east.
    TilePtr south_wall_tile = map->at(CoordUtils::get_new_coordinate(current_coord, Direction::DIRECTION_WEST));

    if (south_wall_tile && tmc.does_tile_block_spell(south_wall_tile))
    {
      reflection = Direction::DIRECTION_NORTH_EAST;
    }
    else
    {
      reflection = Direction::DIRECTION_SOUTH_WEST;
    }
  }

  return reflection;
}

Direction BeamShapeProcessor::get_sw_reflection(const Coordinate& current_coord, MapPtr map)
{
  TileMagicChecker tmc;

  Direction reflection;

  // Inside or outside the corner
  if (MapUtils::is_corner(current_coord, Direction::DIRECTION_SOUTH_WEST, map) || MapUtils::is_corner(current_coord, Direction::DIRECTION_NORTH_EAST, map))
  {
    reflection = Direction::DIRECTION_NORTH_EAST;
  }
  else
  {
    // Are we firing at a southern wall?  Reflect north-east.
    TilePtr south_wall_tile = map->at(CoordUtils::get_new_coordinate(current_coord, Direction::DIRECTION_EAST));

    if (south_wall_tile && tmc.does_tile_block_spell(south_wall_tile))
    {
      reflection = Direction::DIRECTION_NORTH_WEST;
    }
    else
    {
      reflection = Direction::DIRECTION_SOUTH_EAST;
    }
  }

  return reflection;
}