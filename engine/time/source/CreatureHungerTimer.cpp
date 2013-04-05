#include "Conversion.hpp"
#include "CreatureHungerTimer.hpp"
#include "CombatManager.hpp"
#include "FoodAction.hpp"
#include "MessageManager.hpp"
#include "StringConstants.hpp"

using namespace std;

// If the creature requires food, then reduce the hunger clock by 1 per
// every minute this tick.
void CreatureHungerTimer::tick(CreaturePtr creature, const ulonglong minutes_this_tick, const ulonglong total_minutes_elapsed)
{
  if (creature)
  {
    HungerClock& hunger_clock = creature->get_hunger_clock_ref();

    if (hunger_clock.get_requires_food())
    {
      int old_hunger = hunger_clock.get_hunger();
      int new_hunger = old_hunger - 1;
      hunger_clock.set_hunger(new_hunger);

      FoodAction fa;
      fa.add_hunger_level_message_if_necessary(creature, old_hunger, new_hunger);
      apply_hunger_damage_if_appropriate(creature, minutes_this_tick);
    }
  }
}

// If the creature is in HUNGER_LEVEL_DEAD, start killing the creature with hunger damage
void CreatureHungerTimer::apply_hunger_damage_if_appropriate(CreaturePtr creature, const ulonglong minutes_this_tick)
{
  if (creature)
  {
    HungerClock& hunger_clock = creature->get_hunger_clock_ref();

    if (hunger_clock.is_dying())
    {
      string hunger_message_sid = ActionTextKeys::ACTION_PLAYER_STARVING_TO_DEATH;

      CombatManager cm;
      CreaturePtr no_attacker;
      cm.deal_damage(no_attacker, creature, hdc.calculate_hunger_damage(creature, minutes_this_tick), hunger_message_sid);
    }
  }
}
