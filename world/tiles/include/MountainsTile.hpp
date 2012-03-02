#pragma once
#include "WorldMapTile.hpp"

class MountainsTile : public WorldMapTile
{
  public:
    TileType get_tile_type() const;
    
    std::string get_tile_description_sid() const;
};

