#include <boost/make_shared.hpp>
#include "Ammunition.hpp"
#include "CombatConstants.hpp"
#include "WeaponDifficultyCalculator.hpp"
#include "WeaponManager.hpp"

using boost::make_shared;
using boost::dynamic_pointer_cast;

// Get the weapon for the given attack type.  The returned pointer
// WILL BE NULL if there is nothing equipped in the appropriate slot.
WeaponPtr WeaponManager::get_weapon(CreaturePtr creature, const AttackType attack_type)
{
  WeaponPtr weapon;
  
  if (creature)
  {
    switch(attack_type)
    {
      case ATTACK_TYPE_RANGED:
      case ATTACK_TYPE_MELEE_PRIMARY:
        weapon = dynamic_pointer_cast<Weapon>(creature->get_equipment().get_item(static_cast<EquipmentWornLocation>(creature->get_handedness())));
        break;
      case ATTACK_TYPE_MELEE_SECONDARY:
        weapon = dynamic_pointer_cast<Weapon>(creature->get_equipment().get_item(static_cast<EquipmentWornLocation>(creature->get_off_handedness())));
        break;
      case ATTACK_TYPE_MAGICAL:
      default:
        break;
    }
  }
  
  return weapon;
}

// Get the damage for the given attack type
Damage WeaponManager::get_damage(CreaturePtr creature, const AttackType attack_type)
{
  Damage weapon_damage;
  
  switch(attack_type)
  {
    case ATTACK_TYPE_MELEE_PRIMARY:
    case ATTACK_TYPE_MELEE_SECONDARY:
      return get_melee_weapon_damage(creature, attack_type);
      break;
    case ATTACK_TYPE_RANGED:
      return get_ranged_weapon_damage(creature);
      break;
    case ATTACK_TYPE_MAGICAL:
    default:
      break;
  }
  
  return weapon_damage;
}

Damage WeaponManager::get_melee_weapon_damage(CreaturePtr creature, const AttackType attack_type)
{
  WeaponPtr weapon = get_weapon(creature, attack_type);
  
  if (weapon)
  {
    return weapon->get_damage();
  }
  else
  {
    return creature->get_base_damage();
  }
}

Damage WeaponManager::get_ranged_weapon_damage(CreaturePtr creature)
{
  Damage d;
  
  Equipment& equipment = creature->get_equipment();
  WeaponPtr ranged_weapon = dynamic_pointer_cast<Weapon>(equipment.get_item(EQUIPMENT_WORN_RANGED_WEAPON));
  WeaponPtr ammunition = dynamic_pointer_cast<Weapon>(equipment.get_item(EQUIPMENT_WORN_AMMUNITION));
  
  if (ranged_weapon)
  {
    d = ranged_weapon->get_damage();
  }

  if (ammunition)
  {
    Damage ammunition_damage = ammunition->get_damage();

    if (!ranged_weapon)
    {
      d = ammunition_damage; 
    }
    else
    {
      // Set the additional damage based on the ammunition
      DamagePtr additional_damage = make_shared<Damage>(ammunition_damage);
      d.set_additional_damage(additional_damage);
    }
  }
  
  return d;
}

WeaponStyle WeaponManager::get_style(const AttackType attack_type)
{
  if (attack_type == ATTACK_TYPE_RANGED)
  {
    return WEAPON_STYLE_RANGED;
  }
  
  return WEAPON_STYLE_MELEE;
}

int WeaponManager::get_difficulty(WeaponPtr weapon)
{
  WeaponDifficultyCalculator wdc;
  return wdc.get_difficulty_for_weapon(weapon);
}

// Get the skill type for a given attack type (it will be based on the weapon used)
SkillType WeaponManager::get_skill_type(CreaturePtr creature, const AttackType attack_type)
{
  WeaponPtr weapon = get_weapon(creature, attack_type);
  SkillType skill_type = get_appropriate_trained_skill(weapon, attack_type);
  
  return skill_type;
}
 
// Get the damage type for the given attack type.
DamageType WeaponManager::get_damage_type(CreaturePtr creature, const AttackType attack_type)
{
  Damage damage = get_damage(creature, attack_type);
  return damage.get_damage_type();
}

// Get the trained skill from the weapon based on the type of attack being done (ranged or not)
SkillType WeaponManager::get_appropriate_trained_skill(WeaponPtr weapon, const AttackType attack_type)
{
  SkillType skill = SKILL_MELEE_UNARMED;
  
  if (weapon)
  {
    if (attack_type == ATTACK_TYPE_RANGED)
    {
      skill = weapon->get_trained_ranged_skill();
    }
    else
    {
      skill = weapon->get_trained_skill();
    }
  }
  
  return skill;
}

// Is the ranged weapon's trained ranged skill compatible with that of the provided ammunition?
bool WeaponManager::is_ranged_weapon_skill_type_compatible_with_ammunition(WeaponPtr ranged_weapon, WeaponPtr ammunition)
{
  bool weapon_match = false;

  if (ammunition)
  { 
    if (ammunition->get_requires_ranged_weapon())
    {
      if (ranged_weapon)
      {
        SkillType ranged_trained_skill = ranged_weapon->get_trained_ranged_skill();
        SkillType ammo_trained_skill = ammunition->get_trained_ranged_skill();
        
        if (((ammo_trained_skill == SKILL_RANGED_ROCKS) && (ranged_trained_skill == SKILL_RANGED_SLINGS))
          || (ammo_trained_skill == ranged_trained_skill))
        {
          weapon_match = true;
        }
      }
    }
    else
    {
      weapon_match = true;
    }
  }

  return weapon_match;
}
