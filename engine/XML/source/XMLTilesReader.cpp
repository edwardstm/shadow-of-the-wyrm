#include <boost/assert.hpp>
#include "XMLTilesReader.hpp"
#include "DisplayTile.hpp"
#include "tiles.hpp"

using namespace std;

vector<DisplayTile> XMLTilesReader::get_tiles(const XMLNode& xml_configuration_tiles_node, const bool force_ascii)
{
  static_assert(TileType::TILE_TYPE_LAST == static_cast<TileType>(55), "Unexpected TileType::TILE_TYPE_LAST value.");

  vector<DisplayTile> tiles;
  vector<string> tile_names = {"FieldTile", "ScrubTile", "WheatTile", "CairnTile", "TreeTile", "DesertTile", "RoadTile",
                               "RiverTile", "SeaTile", "ShoalsTile", "DungeonTile", "RockTile", "GraveTile", "MarshTile",
                               "ReedsTile", "HillsTile", "MountainsTile", "BeachTile", "BushTile", "WeedsTile", "SpringsTile",
                               "ForestTile", "UpStaircaseTile", "DownStaircaseTile", "CavernTile", "VillageTile", "DungeonComplexTile",
                               "BarracksTile", "CastleTile", "ChurchTile", "GraveyardTile", "KeepTile", "LibraryTile", "SiteOfDeathTile",
                               "TempleTile", "DaisTile", "PierTile", "BarrowTile", "WildOrchardTile", "FruitTreeTile", "EvergreenTreeTile",
                               "RockyEarthTile", "MineTile", "WellTile", "CryptTile", "AirTile", "EarthTile", "SewerComplexTile",
                               "SewerTile", "ShrineTile", "SeabedTile", "AquaticVegetationTile", "FloatingTowerTile", "VoidTile",
                               "MagicalTreeTile"};
  
  vector<XMLNode> tile_nodes;
  tiles.reserve(static_cast<int>(TileType::TILE_TYPE_LAST));

  if (!xml_configuration_tiles_node.is_null())
  {
    // These push back items into the tile details in order, so if you're defining
    // a new tile type, add at appropriate place in the vector above!
    for (const string& tile_n : tile_names)
    {
      tile_nodes.push_back(XMLUtils::get_next_element_by_local_name(xml_configuration_tiles_node, tile_n));
    }

    BOOST_ASSERT(tile_nodes.size() == XMLUtils::get_child_nodes(xml_configuration_tiles_node).size());

    for (const auto& xml_tile : tile_nodes)
    {
      parse_tile_text_details(tiles, xml_tile, force_ascii);
    }
  }

  return tiles;
}

// Takes in the "Text" node of a particular tile, as well as a shared pointer to some
// data structure I haven't defined, yet.
void XMLTilesReader::parse_tile_text_details(vector<DisplayTile>& tile_info, const XMLNode& tile_node, const bool force_ascii)
{
  if (!tile_node.is_null())
  {
    XMLNode symbol_node = XMLUtils::get_next_element_by_local_name(tile_node, "Symbol");
    Symbol s('?', Colour::COLOUR_WHITE);
    parse_symbol(s, symbol_node, force_ascii);

    SeasonTileColourMap tile_colours;

    // May be null, if seasonal colours are provided for the tile type.
    XMLNode colour_node = XMLUtils::get_next_element_by_local_name(symbol_node, "Colour");

    if (!colour_node.is_null())
    {
      int colour = XMLUtils::get_node_int_value(colour_node, 0);

      for (int i = static_cast<int>(Season::SEASON_SPRING); i < static_cast<int>(Season::SEASON_LAST); i++)
      {
        Season season = static_cast<Season>(i);
        tile_colours[season] = colour;
      }
    }

    XMLNode colours_node = XMLUtils::get_next_element_by_local_name(symbol_node, "Colours");

    if (!colours_node.is_null())
    {
      tile_colours.clear();

      int spring_colour = XMLUtils::get_child_node_int_value(colours_node, "Spring");
      int summer_colour = XMLUtils::get_child_node_int_value(colours_node, "Summer");
      int autumn_colour = XMLUtils::get_child_node_int_value(colours_node, "Autumn");
      int winter_colour = XMLUtils::get_child_node_int_value(colours_node, "Winter");

      tile_colours[Season::SEASON_SPRING] = spring_colour;
      tile_colours[Season::SEASON_SUMMER] = summer_colour;
      tile_colours[Season::SEASON_AUTUMN] = autumn_colour;
      tile_colours[Season::SEASON_WINTER] = winter_colour;
    }

    XMLNode weather_colours_node = XMLUtils::get_next_element_by_local_name(symbol_node, "WeatherColours");
    vector<Colour> weather_colours;

    if (!weather_colours_node.is_null())
    {
      vector<XMLNode> weather_colours_nodes = XMLUtils::get_elements_by_local_name(weather_colours_node, "WeatherColour");

      for (const auto& wc_node : weather_colours_nodes)
      {
        Colour weather_colour = static_cast<Colour>(XMLUtils::get_node_int_value(wc_node));
        weather_colours.push_back(weather_colour);
      }
    }

    DisplayTile current_tile_info(s, tile_colours);
    current_tile_info.set_weather_colours(weather_colours);

    tile_info.push_back(current_tile_info);
  }
}
