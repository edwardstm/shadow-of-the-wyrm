#pragma once
#include "Directions.hpp"
#include "Creature.hpp"
#include "IActionManager.hpp"
#include "MapExit.hpp"
#include "Map.hpp"

class MessageManager;

class MovementManager : public IActionManager
{
  public:
    MovementManager();
    ~MovementManager();

    bool move(CreaturePtr creature, const Direction d);
    bool ascend(CreaturePtr creature);
    bool descend(CreaturePtr creature);

  protected:
    uint get_current_action_cost() const;

    bool move_off_map(CreaturePtr creature, MapPtr map, TilePtr old_tile);
    bool move_within_map(CreaturePtr creature, MapPtr map, TilePtr creatures_old_tile, TilePtr creatures_new_tile, const Coordinate& new_coords);
    
    void add_tile_related_messages(const CreaturePtr& creature, MessageManager* manager, TilePtr tile);
    void add_message_about_tile_if_necessary(const CreaturePtr& creature, MessageManager* manager, TilePtr tile);
    void add_message_about_items_on_tile_if_necessary(const CreaturePtr& creature, MessageManager* manager, TilePtr tile);
    void move_to_new_map(MapPtr new_map);
    void move_to_new_map(MapExitPtr map_exit);
};
