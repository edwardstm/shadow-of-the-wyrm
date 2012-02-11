#pragma once
#include "Creature.hpp"
#include "Directions.hpp"
#include "ItemManager.hpp"
#include "MovementManager.hpp"

enum ItemAction
{
  ITEM_ACTION_EQUIP = 0,
  ITEM_ACTION_PICK_UP = 1,
  ITEM_ACTION_DROP = 2
};

class ActionManager
{
  public:
    ActionManager();
    ~ActionManager();

    void version();
    void dump_character(CreaturePtr creature);
    void search(CreaturePtr creature);
    bool move(CreaturePtr creature, const Direction d);
    bool ascend(CreaturePtr creature);
    bool descend(CreaturePtr creature);

    // Pick up/drop check the map type before proceeding.
    void pick_up(CreaturePtr creature);
    void drop(CreaturePtr creature);
    void inventory(CreaturePtr creature);
    
    // Unlike pick up/drop, handle item has no checks.
    void handle_item(CreaturePtr creature, const ItemAction, ItemPtr item);

  protected:
    MovementManager movement_manager;
    ItemManager item_manager;
};
