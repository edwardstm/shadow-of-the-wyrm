#include <vector>
#include "Conversion.hpp"
#include "SpellShapeFactory.hpp"
#include "Modifier.hpp"
#include "XMLSpellsReader.hpp"
#include "XMLDataStructures.hpp"

using namespace std;

class SpellAdditionalPropertiesNames
{
  public:
    static std::string PROPERTY_STATISTIC_MODIFIER_STR;
    static std::string PROPERTY_STATISTIC_MODIFIER_DEX;
    static std::string PROPERTY_STATISTIC_MODIFIER_AGI;
    static std::string PROPERTY_STATISTIC_MODIFIER_HEA;
    static std::string PROPERTY_STATISTIC_MODIFIER_INT;
    static std::string PROPERTY_STATISTIC_MODIFIER_WIL;
    static std::string PROPERTY_STATISTIC_MODIFIER_CHA;
    static std::string PROPERTY_STATISTIC_MODIFIER_EVADE;
    static std::string PROPERTY_STATISTIC_MODIFIER_SOAK;

    // Note that status effects are intentionally not included here.
    // Even though in the game status effects are modelled as a Modifier
    // that has a list of status effects, it isn't intended that spells
    // set status effects directly - rather, they should set status effects
    // by doing the appropriate type of damage, or by doing damage with a
    // certain list of effects.
};

string SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_STR = "STATISTIC_MODIFIER_STR";
string SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_DEX = "STATISTIC_MODIFIER_DEX";
string SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_AGI = "STATISTIC_MODIFIER_AGI";
string SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_HEA = "STATISTIC_MODIFIER_HEA";
string SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_INT = "STATISTIC_MODIFIER_INT";
string SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_WIL = "STATISTIC_MODIFIER_WIL";
string SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_CHA = "STATISTIC_MODIFIER_CHA";
string SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_EVADE = "STATISTIC_MODIFIER_EVADE";
string SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_SOAK = "STATISTIC_MODIFIER_SOAK";

XMLSpellsReader::XMLSpellsReader()
{
}

XMLSpellsReader::~XMLSpellsReader()
{
}

SpellMap XMLSpellsReader::get_spells(const XMLNode& spells_node)
{
  SpellMap spells;

  if (!spells_node.is_null())
  {
    vector<XMLNode> spell_nodes = XMLUtils::get_elements_by_local_name(spells_node, "Spell");

    for (const XMLNode& spell_node : spell_nodes)
    {
      Spell spell = parse(spell_node);
      spells.insert(make_pair(spell.get_spell_id(), spell));
    }
  }

  return spells;
}

Spell XMLSpellsReader::parse(const XMLNode& spell_node)
{
  Spell spell;

  if (!spell_node.is_null())
  {
    string spell_id = XMLUtils::get_attribute_value(spell_node, "id");
    string spell_name_sid = XMLUtils::get_child_node_value(spell_node, "NameSID");
    string player_cast_sid = XMLUtils::get_child_node_value(spell_node, "PlayerCastMessageSID");
    string monster_cast_sid = XMLUtils::get_child_node_value(spell_node, "MonsterCastMessageSID");
    SkillType magic_category = static_cast<SkillType>(XMLUtils::get_child_node_int_value(spell_node, "MagicCategory", static_cast<int>(SkillType::SKILL_MAGIC_ARCANE)));
    Colour spell_colour = static_cast<Colour>(XMLUtils::get_child_node_int_value(spell_node, "Colour"));
    uint ap_cost = XMLUtils::get_child_node_int_value(spell_node, "APCost");
    int speed = XMLUtils::get_child_node_int_value(spell_node, "Speed");
    uint range = XMLUtils::get_child_node_int_value(spell_node, "Range");
    SpellShapeType shape_type = static_cast<SpellShapeType>(XMLUtils::get_child_node_int_value(spell_node, "Shape"));
    SpellShape spell_shape = SpellShapeFactory::create_spell_shape(shape_type);
    XMLNode damage_node = XMLUtils::get_next_element_by_local_name(spell_node, "Damage");
    EffectType effect = static_cast<EffectType>(XMLUtils::get_child_node_int_value(spell_node, "Effect"));
    XMLNode properties_node = XMLUtils::get_next_element_by_local_name(spell_node, "Properties");
    map<string, string> properties;

    spell.set_spell_id(spell_id);
    spell.set_spell_name_sid(spell_name_sid);
    spell.set_player_cast_message_sid(player_cast_sid);
    spell.set_monster_cast_message_sid(monster_cast_sid);
    spell.set_magic_category(magic_category);
    spell.set_colour(spell_colour);
    spell.set_ap_cost(ap_cost);
    spell.set_speed(speed);
    spell.set_range(range);
    spell.set_shape(spell_shape);

    if (!damage_node.is_null())
    {
      Damage dmg;
      parse_damage(dmg, damage_node);

      spell.set_has_damage(true);
      spell.set_damage(dmg);
    }

    parse_spell_properties(properties_node, spell, properties);

    spell.set_effect(effect);
  }

  return spell;
}

void XMLSpellsReader::parse_spell_properties(const XMLNode& properties_node, Spell& spell, map<string, string>& properties)
{
  if (!properties_node.is_null())
  {
    parse_properties(properties, properties_node);
    create_modifiers_if_necessary(spell, properties);
  }
}

void XMLSpellsReader::create_modifiers_if_necessary(Spell& spell, const map<string, string>& properties)
{
  bool create_modifier = false;
  vector<int> sm_constructor_arg;

  vector<string> keys = { SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_STR,
                          SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_DEX,
                          SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_AGI,
                          SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_HEA,
                          SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_INT,
                          SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_WIL,
                          SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_CHA,
                          SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_EVADE,
                          SpellAdditionalPropertiesNames::PROPERTY_STATISTIC_MODIFIER_SOAK };

  for (const auto& key : keys)
  {
    auto prop_it = properties.find(key);

    if (prop_it != properties.end())
    {
      create_modifier = true;
      sm_constructor_arg.push_back(String::to_int(prop_it->second));
    }
    else
    {
      sm_constructor_arg.push_back(0);
    }
  }

  if (create_modifier)
  {
    Modifier m(sm_constructor_arg);
    spell.set_modifier(m);
  }
}