#pragma once
#include "Tile.hpp"

class RiverTile : public Tile
{
  public:
    TileType get_tile_type() const;
    
    std::string get_tile_description_sid() const;
};

