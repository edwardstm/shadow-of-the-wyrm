#pragma once
#include "IActionManager.hpp"
#include "IMessageManager.hpp"

class OrderAction : public IActionManager
{
  public:
    ActionCostValue order(CreaturePtr creature);
    ActionCostValue get_action_cost_value(CreaturePtr creature) const override;

    ActionCostValue order_attack(CreaturePtr creature);
    ActionCostValue order_follow(CreaturePtr creature);
    ActionCostValue order_guard(CreaturePtr creature);
    ActionCostValue order_freeze(CreaturePtr creature);

  protected:
    bool check_for_skills(CreaturePtr creature, IMessageManager& manager);
    bool check_for_followers(CreaturePtr creature, IMessageManager& manager);
    void set_order(CreaturePtr creature, const std::string& order_property);

    ActionCostValue order_followers(CreaturePtr creature, IMessageManager& manager);
};

