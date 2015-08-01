#pragma once
#include "ITileManipulator.hpp"

// Default tile manipulator.  Defines manipulation operations that do
// very little - if there's any tile-specific behaviour, the factory
// will instantiate a different class.
class DefaultTileManipulator : public ITileManipulator
{
  public:
    DefaultTileManipulator();

    bool dig(CreaturePtr creature, MapPtr map, TilePtr tile) override;

  protected:
    void add_undead_if_necessary(CreaturePtr creature, MapPtr map, TilePtr tile);
    void add_item_if_necessary(CreaturePtr creature, MapPtr map, TilePtr tile);

    std::map<TileSuperType, std::string> super_type_message_sids;
};

