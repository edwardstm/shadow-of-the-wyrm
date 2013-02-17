#include <sstream>
#include <boost/algorithm/string/replace.hpp>
#include "Conversion.hpp"
#include "ItemDescriber.hpp"
#include "StringTable.hpp"
#include "StringConstants.hpp"

using namespace std;

FileConstants::FileConstants()
{
}

FileConstants::~FileConstants()
{
}

const string FileConstants::XML_CONFIGURATION_FILE = "data/SavageLands.xml";
const string FileConstants::SAVEFILE_PATTERN = ".(sls)$"; // Savefile regex pattern required by boost::filesystem
const string FileConstants::CUSTOM_MAPS_DIRECTORY = "data/maps/";
const string FileConstants::CUSTOM_MAPS_PATTERN = ".(xml)$";

PlayerConstants::PlayerConstants()
{
}

PlayerConstants::~PlayerConstants()
{
}

const string PlayerConstants::PLAYER_CREATURE_ID = "player";

TextKeys::TextKeys()
{
}

TextKeys::~TextKeys()
{
}

const string TextKeys::SL_TITLE    = "SL_TITLE";
const string TextKeys::SL_TITLE_POEM = "SL_TITLE_POEM";
const string TextKeys::COPYRIGHT_NOTICE = "COPYRIGHT_NOTICE";
const string TextKeys::SL_TITLE_NEW_GAME = "SL_TITLE_NEW_GAME";
const string TextKeys::CHARACTER_ALREADY_EXISTS = "CHARACTER_ALREADY_EXISTS";
const string TextKeys::SL_TITLE_LOAD_GAME = "SL_TITLE_LOAD_GAME";
const string TextKeys::SL_TITLE_QUIT_GAME = "SL_TITLE_QUIT_GAME";
const string TextKeys::EXIT = "EXIT";
const string TextKeys::DEATH_MESSAGE = "DEATH_MESSAGE";
const string TextKeys::DEFAULT_PLAYER_NAME = "DEFAULT_PLAYER_NAME";
const string TextKeys::YOU = "YOU";
const string TextKeys::NPC_ESCAPES_MESSAGE = "NPC_ESCAPES_MESSAGE";
const string TextKeys::SELECT_RACE = "SELECT_RACE";
const string TextKeys::SELECT_CLASS = "SELECT_CLASS";
const string TextKeys::SELECT_DEITY = "SELECT_DEITY";
const string TextKeys::SELECT_SAVED_GAME = "SELECT_SAVED_GAME";
const string TextKeys::DEITY = "DEITY";
const string TextKeys::AGE = "AGE";
const string TextKeys::SEX = "SEX";
const string TextKeys::HAIR_COLOUR = "HAIR_COLOUR";
const string TextKeys::EYE_COLOUR = "EYE_COLOUR";
const string TextKeys::SELECT_SEX = "SELECT_SEX";
const string TextKeys::SEX_MALE = "SEX_MALE";
const string TextKeys::SEX_FEMALE = "SEX_FEMALE";

const string TextKeys::RACE_1_NAME = "RACE_1_NAME";
const string TextKeys::RACE_1_SHORT_DESC = "RACE_1_SHORT_DESC";
const string TextKeys::RACE_1_DESC = "RACE_1_DESC";
const string TextKeys::RACE_2_NAME = "RACE_2_NAME";
const string TextKeys::RACE_2_SHORT_DESC = "RACE_2_SHORT_DESC";
const string TextKeys::RACE_2_DESC = "RACE_2_DESC";
const string TextKeys::RACE_3_NAME = "RACE_3_NAME";
const string TextKeys::RACE_3_SHORT_DESC = "RACE_3_SHORT_DESC";
const string TextKeys::RACE_3_DESC = "RACE_3_DESC";
const string TextKeys::RACE_4_NAME = "RACE_4_NAME";
const string TextKeys::RACE_4_SHORT_DESC = "RACE_4_SHORT_DESC";
const string TextKeys::RACE_4_DESC = "RACE_4_DESC";
const string TextKeys::RACE_5_NAME = "RACE_5_NAME";
const string TextKeys::RACE_5_SHORT_DESC = "RACE_5_SHORT_DESC";
const string TextKeys::RACE_5_DESC = "RACE_5_DESC";
const string TextKeys::RACE_6_NAME = "RACE_6_NAME";
const string TextKeys::RACE_6_SHORT_DESC = "RACE_6_SHORT_DESC";
const string TextKeys::RACE_6_DESC = "RACE_6_DESC";
const string TextKeys::RACE_7_NAME = "RACE_7_NAME";
const string TextKeys::RACE_7_SHORT_DESC = "RACE_7_SHORT_DESC";
const string TextKeys::RACE_7_DESC = "RACE_7_DESC";
const string TextKeys::RACE_8_NAME = "RACE_8_NAME";
const string TextKeys::RACE_8_SHORT_DESC = "RACE_8_SHORT_DESC";
const string TextKeys::RACE_8_DESC = "RACE_8_DESC";
const string TextKeys::RACE_9_NAME = "RACE_9_NAME";
const string TextKeys::RACE_9_SHORT_DESC = "RACE_9_SHORT_DESC";
const string TextKeys::RACE_9_DESC = "RACE_8_DESC";
const string TextKeys::RACE_10_NAME = "RACE_10_NAME";
const string TextKeys::RACE_10_SHORT_DESC = "RACE_10_SHORT_DESC";
const string TextKeys::RACE_10_DESC = "RACE_10_DESC";

const string TextKeys::STRENGTH          = "STRENGTH";
const string TextKeys::STRENGTH_ABRV     = "STRENGTH_ABRV";
const string TextKeys::DEXTERITY         = "DEXTERITY";
const string TextKeys::DEXTERITY_ABRV    = "DEXTERITY_ABRV";
const string TextKeys::AGILITY           = "AGILITY";
const string TextKeys::AGILITY_ABRV      = "AGILITY_ABRV";
const string TextKeys::HEALTH            = "HEALTH";
const string TextKeys::HEALTH_ABRV       = "HEALTH_ABRV";
const string TextKeys::INTELLIGENCE      = "INTELLIGENCE";
const string TextKeys::INTELLIGENCE_ABRV = "INTELLIGENCE_ABRV";
const string TextKeys::WILLPOWER         = "WILLPOWER";
const string TextKeys::WILLPOWER_ABRV    = "WILLPOWER_ABRV";
const string TextKeys::CHARISMA          = "CHARISMA";
const string TextKeys::CHARISMA_ABRV     = "CHARISMA_ABRV";

const string TextKeys::VALOUR            = "VALOUR";
const string TextKeys::VALOUR_ABRV       = "VALOUR_ABRV";
const string TextKeys::SPIRIT            = "SPIRIT";
const string TextKeys::SPIRIT_ABRV       = "SPIRIT_ABRV";
const string TextKeys::SPEED             = "SPEED";
const string TextKeys::SPEED_ABRV        = "SPEED_ABRV";

const string TextKeys::HIT_POINTS        = "HIT_POINTS";
const string TextKeys::HIT_POINTS_ABRV   = "HIT_POINTS_ABRV";
const string TextKeys::ARCANA_POINTS     = "ARCANA_POINTS";
const string TextKeys::ARCANA_POINTS_ABRV = "ARCANA_POINTS_ABRV";

const string TextKeys::EVADE             = "EVADE";
const string TextKeys::EVADE_ABRV        = "EVADE_ABRV";
const string TextKeys::SOAK              = "SOAK";
const string TextKeys::SOAK_ABRV         = "SOAK_ABRV";

const string TextKeys::LEVEL             = "LEVEL";
const string TextKeys::LEVEL_ABRV        = "LEVEL_ABRV";

const string TextKeys::DAMAGE_MELEE      = "DAMAGE_MELEE";
const string TextKeys::DAMAGE_RANGED     = "DAMAGE_RANGED";

const string TextKeys::EQUIPMENT         = "EQUIPMENT";
const string TextKeys::EQUIPMENT_PROMPT  = "EQUIPMENT_PROMPT";
const string TextKeys::INVENTORY         = "INVENTORY";
const string TextKeys::INVENTORY_PROMPT  = "INVENTORY_PROMPT";

const string TextKeys::DECISION_CONFIRM_KEY = "DECISION_CONFIRM_KEY";
const string TextKeys::DECISION_DENY_KEY    = "DECISION_DENY_KEY";
const string TextKeys::DECISION_LEAVE_AREA  = "DECISION_LEAVE_AREA";
const string TextKeys::DECISION_QUIT_GAME   = "DECISION_QUIT_GAME";
const string TextKeys::DECISION_JUMP_INTO_WATER = "DECISION_JUMP_INTO_WATER";
const string TextKeys::DECISION_SAVE_GAME = "DECISION_SAVE_GAME";

const string TextKeys::GAIN_LEVEL = "GAIN_LEVEL";

const string TextKeys::UNARMED = "UNARMED";

// Materials
MaterialTextKeys::MaterialTextKeys()
{
}

MaterialTextKeys::~MaterialTextKeys()
{
}

const string MaterialTextKeys::MATERIAL_CLOTH        = "MATERIAL_CLOTH";
const string MaterialTextKeys::MATERIAL_DRAGON_SCALE = "MATERIAL_DRAGON_SCALE";
const string MaterialTextKeys::MATERIAL_GLASS        = "MATERIAL_GLASS";
const string MaterialTextKeys::MATERIAL_IRON         = "MATERIAL_IRON";
const string MaterialTextKeys::MATERIAL_LEATHER      = "MATERIAL_LEATHER";
const string MaterialTextKeys::MATERIAL_PAPER        = "MATERIAL_PAPER";
const string MaterialTextKeys::MATERIAL_STEEL        = "MATERIAL_STEEL";
const string MaterialTextKeys::MATERIAL_STONE        = "MATERIAL_STONE";
const string MaterialTextKeys::MATERIAL_WOOD         = "MATERIAL_WOOD";
const string MaterialTextKeys::MATERIAL_MARBLE       = "MATERIAL_MARBLE";
const string MaterialTextKeys::MATERIAL_ONYX         = "MATERIAL_ONYX";
const string MaterialTextKeys::MATERIAL_IVORY        = "MATERIAL_IVORY";

// Date/time
DateTextKeys::DateTextKeys()
{
}

DateTextKeys::~DateTextKeys()
{
}

const string DateTextKeys::DATE_TIME_MESSAGE = "DATE_TIME_MESSAGE";

string DateTextKeys::get_date_time_message(const Date& date, const string& season_sid)
{
  string date_time_message = StringTable::get(DateTextKeys::DATE_TIME_MESSAGE);
  string season = StringTable::get(season_sid);
  
  string time = DateTextKeys::get_time(date);
  string day_of_week = StringTable::get(date.get_day_of_week_sid());
  string month = StringTable::get(date.get_month_sid());  

  boost::replace_first(date_time_message, "%s", time);
  boost::replace_first(date_time_message, "%s", day_of_week);
  boost::replace_first(date_time_message, "%s", Integer::to_string(date.get_day_of_month()));
  boost::replace_first(date_time_message, "%s", month);
  boost::replace_first(date_time_message, "%s", Integer::to_string(date.get_year()));
  boost::replace_first(date_time_message, "%s", season);
  
  return date_time_message;
}

string DateTextKeys::get_time(const Date& date)
{
  uint hours = date.get_hours();
  uint minutes = date.get_minutes();
  uint seconds = static_cast<uint>(date.get_seconds());
  
  ostringstream ss;
  
  if (hours < 10)
  {
    ss << "0";
  }
  
  ss << hours << ":";
  
  if (minutes < 10)
  {
    ss << "0";
  }
  
  ss << minutes << ":";
  
  if (seconds < 10)
  {
    ss << "0";
  }
  
  ss << seconds;
  
  return ss.str();
}

// Entrance
EntranceTextKeys::EntranceTextKeys()
{
}

EntranceTextKeys::~EntranceTextKeys()
{
}

const string EntranceTextKeys::ENTRANCE_FIELD           = "ENTRANCE_FIELD";
const string EntranceTextKeys::ENTRANCE_SCRUB           = "ENTRANCE_SCRUB";
const string EntranceTextKeys::ENTRANCE_DESERT          = "ENTRANCE_DESERT";
const string EntranceTextKeys::ENTRANCE_MOUNTAINS       = "ENTRANCE_MOUNTAINS";
const string EntranceTextKeys::ENTRANCE_SEA             = "ENTRANCE_SEA";
const string EntranceTextKeys::ENTRANCE_FOREST          = "ENTRANCE_FOREST";
const string EntranceTextKeys::ENTRANCE_MARSH           = "ENTRANCE_MARSH";
const string EntranceTextKeys::ENTRANCE_HILLS           = "ENTRANCE_HILLS";
const string EntranceTextKeys::ENTRANCE_CAVERN          = "ENTRANCE_CAVERN";
const string EntranceTextKeys::ENTRANCE_VILLAGE         = "ENTRANCE_VILLAGE";
const string EntranceTextKeys::ENTRANCE_DUNGEON_COMPLEX = "ENTRANCE_DUNGEON_COMPLEX";
const string EntranceTextKeys::ENTRANCE_BARRACKS        = "ENTRANCE_BARRACKS";
const string EntranceTextKeys::ENTRANCE_CASTLE          = "ENTRANCE_CASTLE";
const string EntranceTextKeys::ENTRANCE_CHURCH          = "ENTRANCE_CHURCH";
const string EntranceTextKeys::ENTRANCE_GRAVEYARD       = "ENTRANCE_GRAVEYARD";
const string EntranceTextKeys::ENTRANCE_KEEP            = "ENTRANCE_KEEP";
const string EntranceTextKeys::ENTRANCE_LIBRARY         = "ENTRANCE_LIBRARY";
const string EntranceTextKeys::ENTRANCE_SITE_OF_DEATH   = "ENTRANCE_SITE_OF_DEATH";
const string EntranceTextKeys::ENTRANCE_TEMPLE          = "ENTRANCE_TEMPLE";

// Equipment
EquipmentTextKeys::EquipmentTextKeys()
{
}

const string EquipmentTextKeys::EQUIPMENT_HEAD         = "EQUIPMENT_HEAD";
const string EquipmentTextKeys::EQUIPMENT_NECK         = "EQUIPMENT_NECK";
const string EquipmentTextKeys::EQUIPMENT_RIGHT_FINGER = "EQUIPMENT_RIGHT_FINGER";
const string EquipmentTextKeys::EQUIPMENT_LEFT_FINGER  = "EQUIPMENT_LEFT_FINGER";
const string EquipmentTextKeys::EQUIPMENT_WIELDED   = "EQUIPMENT_WIELDED";
const string EquipmentTextKeys::EQUIPMENT_OFF_HAND    = "EQUIPMENT_OFF_HAND";
const string EquipmentTextKeys::EQUIPMENT_BODY         = "EQUIPMENT_BODY";
const string EquipmentTextKeys::EQUIPMENT_ABOUT_BODY   = "EQUIPMENT_ABOUT_BODY";
const string EquipmentTextKeys::EQUIPMENT_FEET         = "EQUIPMENT_FEET";
const string EquipmentTextKeys::EQUIPMENT_RANGED       = "EQUIPMENT_RANGED";
const string EquipmentTextKeys::EQUIPMENT_AMMUNITION   = "EQUIPMENT_AMMUNITION";
const string EquipmentTextKeys::EQUIPMENT_RANGED_SYNOPSIS = "EQUIPMENT_RANGED_SYNOPSIS";
const string EquipmentTextKeys::EQUIPMENT_WEAPON_DIFFICULTY_SPEED_AND_DAMAGE_SYNOPSIS = "EQUIPMENT_WEAPON_DIFFICULTY_SPEED_AND_DAMAGE_SYNOPSIS";
const string EquipmentTextKeys::EQUIPMENT_PRIMARY_MELEE_DIFFICULTY_SPEED_AND_DAMAGE_SYNOPSIS = "EQUIPMENT_PRIMARY_MELEE_DIFFICULTY_SPEED_AND_DAMAGE_SYNOPSIS";
const string EquipmentTextKeys::EQUIPMENT_SECONDARY_MELEE_DIFFICULTY_SPEED_AND_DAMAGE_SYNOPSIS = "EQUIPMENT_SECONDARY_MELEE_DIFFICULTY_SPEED_AND_DAMAGE_SYNOPSIS";

string EquipmentTextKeys::get_equipment_text_from_given_worn_location(const EquipmentWornLocation& worn_location)
{
  string equipment_text;
  string equipment_text_sid;
  
  switch(worn_location)
  {
    case EQUIPMENT_WORN_HEAD:
      equipment_text_sid = EQUIPMENT_HEAD;
      break;
    case EQUIPMENT_WORN_NECK:
      equipment_text_sid = EQUIPMENT_NECK;
      break;
    case EQUIPMENT_WORN_RIGHT_FINGER:
      equipment_text_sid = EQUIPMENT_RIGHT_FINGER;
      break;
    case EQUIPMENT_WORN_LEFT_FINGER:
      equipment_text_sid = EQUIPMENT_LEFT_FINGER;
      break;
    case EQUIPMENT_WORN_WIELDED:
      equipment_text_sid = EQUIPMENT_WIELDED;
      break;
    case EQUIPMENT_WORN_OFF_HAND:
      equipment_text_sid = EQUIPMENT_OFF_HAND;
      break;
    case EQUIPMENT_WORN_BODY:
      equipment_text_sid = EQUIPMENT_BODY;
      break;
    case EQUIPMENT_WORN_ABOUT_BODY:
      equipment_text_sid = EQUIPMENT_ABOUT_BODY;
      break;
    case EQUIPMENT_WORN_FEET:
      equipment_text_sid = EQUIPMENT_FEET;
      break;
    case EQUIPMENT_WORN_RANGED_WEAPON:
      equipment_text_sid = EQUIPMENT_RANGED;
      break;
    case EQUIPMENT_WORN_AMMUNITION:
      equipment_text_sid = EQUIPMENT_AMMUNITION;
      break;
    case EQUIPMENT_WORN_NONE:
    case EQUIPMENT_WORN_LAST:
    default:
      break;
  }
  
  equipment_text = StringTable::get(equipment_text_sid);
  return equipment_text;
}

string EquipmentTextKeys::get_ranged_weapon_synopsis(WeaponPtr ranged_weapon, WeaponPtr ammunition, const string& difficulty_speed_and_damage_synopsis)
{
  string ranged_synopsis = StringTable::get(EQUIPMENT_RANGED_SYNOPSIS);
  string weapon_string = "/";
  string ammunition_string = "/";
  
  if (ranged_weapon)
  {
    weapon_string = StringTable::get(ranged_weapon->get_description_sid());
  }
  
  if (ammunition)
  {
    ammunition_string = StringTable::get(ammunition->get_description_sid());
  }
  
  boost::replace_first(ranged_synopsis, "%s", weapon_string);
  boost::replace_first(ranged_synopsis, "%s", ammunition_string);
  boost::replace_first(ranged_synopsis, "%s", difficulty_speed_and_damage_synopsis);
  
  return ranged_synopsis;
}

string EquipmentTextKeys::get_weapon_difficulty_speed_and_damage_synopsis(const int difficulty, const int speed, const Damage& damage)
{
  string synopsis = StringTable::get(EQUIPMENT_WEAPON_DIFFICULTY_SPEED_AND_DAMAGE_SYNOPSIS);

  boost::replace_first(synopsis, "%s", Integer::to_string(difficulty));
  boost::replace_first(synopsis, "%s", Integer::to_string(speed));
  boost::replace_first(synopsis, "%s", damage.str());
  
  return synopsis;
}

string EquipmentTextKeys::get_melee_weapon_synopsis(const AttackType attack_type, WeaponPtr weapon, const int difficulty, const int speed, const Damage& damage)
{
  string synopsis;
  
  if (attack_type == ATTACK_TYPE_MELEE_PRIMARY)
  {
    synopsis = StringTable::get(EQUIPMENT_PRIMARY_MELEE_DIFFICULTY_SPEED_AND_DAMAGE_SYNOPSIS);
  }
  else if (attack_type == ATTACK_TYPE_MELEE_SECONDARY)
  {
    synopsis = StringTable::get(EQUIPMENT_SECONDARY_MELEE_DIFFICULTY_SPEED_AND_DAMAGE_SYNOPSIS);
  }
  
  string weapon_description_sid = TextKeys::UNARMED;
  
  if (weapon)
  {
    weapon_description_sid = weapon->get_description_sid();
  }
  
  boost::replace_first(synopsis, "%s", StringTable::get(weapon_description_sid));
  boost::replace_first(synopsis, "%s", Integer::to_string(difficulty));
  boost::replace_first(synopsis, "%s", Integer::to_string(speed));
  boost::replace_first(synopsis, "%s", damage.str());
  
  return synopsis;
}

// Colours
ColourTextKeys::ColourTextKeys()
{
}

ColourTextKeys::~ColourTextKeys()
{
}

string ColourTextKeys::get_colour_sid_from_hair_colour(const HairColour hair_colour)
{
  string colour_sid;
  
  switch(hair_colour)
  {
    case HAIR_COLOUR_BLACK:
      colour_sid = COLOUR_BLACK;
      break;
    case HAIR_COLOUR_BROWN:
      colour_sid = COLOUR_BROWN;
      break;
    case HAIR_COLOUR_BLONDE:
      colour_sid = COLOUR_BLONDE;
      break;
    case HAIR_COLOUR_RED:
      colour_sid = COLOUR_RED;
      break;
    case HAIR_COLOUR_GREY:
      colour_sid = COLOUR_GREY;
      break;
    case HAIR_COLOUR_WHITE:
      colour_sid = COLOUR_WHITE;
      break;
    default:
      break;
  }
  
  return colour_sid;
}

string ColourTextKeys::get_colour_sid_from_eye_colour(const EyeColour eye_colour)
{
  string colour_sid;
  
  switch(eye_colour)
  {
    case EYE_COLOUR_BROWN:
      colour_sid = COLOUR_BROWN;
      break;
    case EYE_COLOUR_BLUE:
      colour_sid = COLOUR_BLUE;
      break;
    case EYE_COLOUR_GREEN:
      colour_sid = COLOUR_GREEN;
      break;
    case EYE_COLOUR_HAZEL:
      colour_sid = COLOUR_HAZEL;
      break;
    case EYE_COLOUR_GREY:
      colour_sid = COLOUR_GREY;
      break;
    default:
      break;
  }
  
  return colour_sid;
}

const string ColourTextKeys::COLOUR_BLACK = "COLOUR_BLACK";
const string ColourTextKeys::COLOUR_BROWN = "COLOUR_BROWN";
const string ColourTextKeys::COLOUR_BLONDE = "COLOUR_BLONDE";
const string ColourTextKeys::COLOUR_RED = "COLOUR_RED";
const string ColourTextKeys::COLOUR_GREEN = "COLOUR_GREEN";
const string ColourTextKeys::COLOUR_HAZEL = "COLOUR_HAZEL";
const string ColourTextKeys::COLOUR_BLUE = "COLOUR_BLUE";
const string ColourTextKeys::COLOUR_GREY = "COLOUR_GREY";
const string ColourTextKeys::COLOUR_WHITE = "COLOUR_WHITE";


SizeTextKeys::SizeTextKeys()
{
}

SizeTextKeys::~SizeTextKeys()
{
}

string SizeTextKeys::get_size_sid_from_creature_size(const CreatureSize size)
{
  string size_sid;
  
  switch(size)
  {
    case CREATURE_SIZE_TINY:
      size_sid = SIZE_TINY;
      break;
    case CREATURE_SIZE_SMALL:
      size_sid = SIZE_SMALL;
      break;
    case CREATURE_SIZE_MEDIUM:
      size_sid = SIZE_MEDIUM;
      break;
    case CREATURE_SIZE_LARGE:
      size_sid = SIZE_LARGE;
      break;
    case CREATURE_SIZE_HUGE:
      size_sid = SIZE_HUGE;
      break;
    case CREATURE_SIZE_BEHEMOTH: 
      size_sid = SIZE_BEHEMOTH;
      break;
    default:
      break;
  }
  
  return size_sid;
}

const string SizeTextKeys::SIZE = "SIZE";
const string SizeTextKeys::SIZE_TINY = "SIZE_TINY";
const string SizeTextKeys::SIZE_SMALL = "SIZE_SMALL";
const string SizeTextKeys::SIZE_MEDIUM = "SIZE_MEDIUM";
const string SizeTextKeys::SIZE_LARGE = "SIZE_LARGE";
const string SizeTextKeys::SIZE_HUGE = "SIZE_HUGE";
const string SizeTextKeys::SIZE_BEHEMOTH = "SIZE_BEHEMOTH";

SkillTextKeys::SkillTextKeys()
{
}

SkillTextKeys::~SkillTextKeys()
{
}

// SkillTextKeys
// General (NWP)
const string SkillTextKeys::SKILLS_GENERAL = "SKILLS_GENERAL";
const string SkillTextKeys::SKILL_GENERAL_ARCHERY = "SKILL_GENERAL_ARCHERY";
const string SkillTextKeys::SKILL_GENERAL_ARCHERY_INCREMENT = "SKILL_GENERAL_ARCHERY_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_AWARENESS = "SKILL_GENERAL_AWARENESS";
const string SkillTextKeys::SKILL_GENERAL_AWARENESS_INCREMENT = "SKILL_GENERAL_AWARENESS_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_BARGAINING = "SKILL_GENERAL_BARGAINING";
const string SkillTextKeys::SKILL_GENERAL_BARGAINING_INCREMENT = "SKILL_GENERAL_BARGAINING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_BEASTMASTERY = "SKILL_GENERAL_BEASTMASTERY";
const string SkillTextKeys::SKILL_GENERAL_BEASTMASTERY_INCREMENT = "SKILL_GENERAL_BEASTMASTERY_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_BLIND_FIGHTING = "SKILL_GENERAL_BLIND_FIGHTING";
const string SkillTextKeys::SKILL_GENERAL_BLIND_FIGHTING_INCREMENT = "SKILL_GENERAL_BLIND_FIGHTING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_BOATING = "SKILL_GENERAL_BOATING";
const string SkillTextKeys::SKILL_GENERAL_BOATING_INCREMENT = "SKILL_GENERAL_BOATING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_BOWYER = "SKILL_GENERAL_BOWYER";
const string SkillTextKeys::SKILL_GENERAL_BOWYER_INCREMENT = "SKILL_GENERAL_BOWYER_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_BREWING = "SKILL_GENERAL_BREWING";
const string SkillTextKeys::SKILL_GENERAL_BREWING_INCREMENT = "SKILL_GENERAL_BREWING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_CANTRIPS = "SKILL_GENERAL_CANTRIPS";
const string SkillTextKeys::SKILL_GENERAL_CANTRIPS_INCREMENT = "SKILL_GENERAL_CANTRIPS_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_CARRYING = "SKILL_GENERAL_CARRYING";
const string SkillTextKeys::SKILL_GENERAL_CARRYING_INCREMENT = "SKILL_GENERAL_CARRYING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_COMBAT = "SKILL_GENERAL_COMBAT";
const string SkillTextKeys::SKILL_GENERAL_COMBAT_INCREMENT = "SKILL_GENERAL_COMBAT_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_CRAFTING = "SKILL_GENERAL_CRAFTING";
const string SkillTextKeys::SKILL_GENERAL_CRAFTING_INCREMENT = "SKILL_GENERAL_CRAFTING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_DESERT_LORE = "SKILL_GENERAL_DESERT_LORE";
const string SkillTextKeys::SKILL_GENERAL_DESERT_LORE_INCREMENT = "SKILL_GENERAL_DESERT_LORE_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_DETECTION = "SKILL_GENERAL_DETECTION";
const string SkillTextKeys::SKILL_GENERAL_DETECTION_INCREMENT = "SKILL_GENERAL_DETECTION_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_DISARM_TRAPS = "SKILL_GENERAL_DISARM_TRAPS";
const string SkillTextKeys::SKILL_GENERAL_DISARM_TRAPS_INCREMENT = "SKILL_GENERAL_TRAPS_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_DUAL_WIELD = "SKILL_GENERAL_DUAL_WIELD";
const string SkillTextKeys::SKILL_GENERAL_DUAL_WIELD_INCREMENT = "SKILL_GENERAL_DUAL_WIELD_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_DUNGEONEERING = "SKILL_GENERAL_DUNGEONEERING";
const string SkillTextKeys::SKILL_GENERAL_DUNGEONEERING_INCREMENT = "SKILL_GENERAL_DUNGEONEERING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_ESCAPE = "SKILL_GENERAL_ESCAPE";
const string SkillTextKeys::SKILL_GENERAL_ESCAPE_INCREMENT = "SKILL_GENERAL_ESCAPE_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_FORAGING = "SKILL_GENERAL_ESCAPE";
const string SkillTextKeys::SKILL_GENERAL_FORAGING_INCREMENT = "SKILL_GENERAL_FORAGING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_FOREST_LORE = "SKILL_GENERAL_FOREST_LORE";
const string SkillTextKeys::SKILL_GENERAL_FOREST_LORE_INCREMENT = "SKILL_GENERAL_FOREST_LORE_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_FISHING = "SKILL_GENERAL_FISHING";
const string SkillTextKeys::SKILL_GENERAL_FISHING_INCREMENT = "SKILL_GENERAL_FISHING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_FLETCHERY = "SKILL_GENERAL_FLETCHERY";
const string SkillTextKeys::SKILL_GENERAL_FLETCHERY_INCREMENT = "SKILL_GENERAL_FLETCHERY_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_HERBALISM = "SKILL_GENERAL_HERBALISM";
const string SkillTextKeys::SKILL_GENERAL_HERBALISM_INCREMENT = "SKILL_GENERAL_HERBALISM_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_HIDING = "SKILL_GENERAL_HIDING";
const string SkillTextKeys::SKILL_GENERAL_HIDING_INCREMENT = "SKILL_GENERAL_HIDING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_HUNTING = "SKILL_GENERAL_HUNTING";
const string SkillTextKeys::SKILL_GENERAL_HUNTING_INCREMENT = "SKILL_GENERAL_HUNTING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_INTIMIDATION = "SKILL_GENERAL_INTIMIDATION";
const string SkillTextKeys::SKILL_GENERAL_INTIMIDATION_INCREMENT = "SKILL_GENERAL_INTIMIDATION_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_JEWELER = "SKILL_GENERAL_JEWELER";
const string SkillTextKeys::SKILL_GENERAL_JEWELER_INCREMENT = "SKILL_GENERAL_JEWELER_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_JUMPING = "SKILL_GENERAL_JUMPING";
const string SkillTextKeys::SKILL_GENERAL_JUMPING_INCREMENT = "SKILL_GENERAL_JUMPING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_LEADERSHIP = "SKILL_GENERAL_LEADERSHIP";
const string SkillTextKeys::SKILL_GENERAL_LEADERSHIP_INCREMENT = "SKILL_GENERAL_LEADERSHIP_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_LITERACY = "SKILL_GENERAL_LITERACY";
const string SkillTextKeys::SKILL_GENERAL_LITERACY_INCREMENT = "SKILL_GENERAL_LITERACY_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_LORE = "SKILL_GENERAL_LORE";
const string SkillTextKeys::SKILL_GENERAL_LORE_INCREMENT = "SKILL_GENERAL_LORE_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_MAGIC = "SKILL_GENERAL_MAGIC";
const string SkillTextKeys::SKILL_GENERAL_MAGIC_INCREMENT = "SKILL_GENERAL_MAGIC_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_MARSH_LORE = "SKILL_GENERAL_MARSH_LORE";
const string SkillTextKeys::SKILL_GENERAL_MARSH_LORE_INCREMENT = "SKILL_GENERAL_LORE_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_MEDICINE = "SKILL_GENERAL_MEDICINE";
const string SkillTextKeys::SKILL_GENERAL_MEDICINE_INCREMENT = "SKILL_GENERAL_MEDICINE_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_MOUNTAIN_LORE = "SKILL_GENERAL_MOUNTAIN_LORE";
const string SkillTextKeys::SKILL_GENERAL_MOUNTAIN_LORE_INCREMENT = "SKILL_GENERAL_MOUNTAIN_LORE_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_MOUNTAINEERING = "SKILL_GENERAL_MOUNTAINEERING";
const string SkillTextKeys::SKILL_GENERAL_MOUNTAINEERING_INCREMENT = "SKILL_GENERAL_MOUNTAINEERING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_MUSIC = "SKILL_GENERAL_MUSIC";
const string SkillTextKeys::SKILL_GENERAL_MUSIC_INCREMENT = "SKILL_GENERAL_MUSIC_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_NIGHT_SIGHT = "SKILL_GENERAL_NIGHT_SIGHT";
const string SkillTextKeys::SKILL_GENERAL_NIGHT_SIGHT_INCREMENT = "SKILL_GENERAL_NIGHT_SIGHT_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_OCEANOGRAPHY = "SKILL_GENERAL_OCEANOGRAPHY";
const string SkillTextKeys::SKILL_GENERAL_OCEANOGRAPHY_INCREMENT = "SKILL_GENERAL_OCEANOGRAPHY_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_PAPERCRAFT = "SKILL_GENERAL_PAPERCRAFT";
const string SkillTextKeys::SKILL_GENERAL_PAPERCRAFT_INCREMENT = "SKILL_GENERAL_PAPERCRAFT_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_RELIGION = "SKILL_GENERAL_RELIGION";
const string SkillTextKeys::SKILL_GENERAL_RELIGION_INCREMENT = "SKILL_GENERAL_RELIGION_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_SCRIBING = "SKILL_GENERAL_SCRIBING";
const string SkillTextKeys::SKILL_GENERAL_SCRIBING_INCREMENT = "SKILL_GENERAL_SCRIBING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_SKINNING = "SKILL_GENERAL_SKINNING";
const string SkillTextKeys::SKILL_GENERAL_SKINNING_INCREMENT = "SKILL_GENERAL_SKINNING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_SMITHING = "SKILL_GENERAL_SMITHING";
const string SkillTextKeys::SKILL_GENERAL_SMITHING_INCREMENT = "SKILL_GENERAL_SMITHING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_SPELUNKING = "SKILL_GENERAL_SPELUNKING";
const string SkillTextKeys::SKILL_GENERAL_SPELUNKING_INCREMENT = "SKILL_GENERAL_SPELUNKING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_STEALTH = "SKILL_GENERAL_STEALTH";
const string SkillTextKeys::SKILL_GENERAL_STEALTH_INCREMENT = "SKILL_GENERAL_STEALTH_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_SWIMMING = "SKILL_GENERAL_SWIMMING";
const string SkillTextKeys::SKILL_GENERAL_SWIMMING_INCREMENT = "SKILL_GENERAL_SWIMMING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_TANNING = "SKILL_GENERAL_TANNING";
const string SkillTextKeys::SKILL_GENERAL_TANNING_INCREMENT = "SKILL_GENERAL_TANNING_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_THIEVERY = "SKILL_GENERAL_THIEVERY";
const string SkillTextKeys::SKILL_GENERAL_THIEVERY_INCREMENT = "SKILL_GENERAL_THIEVERY_INCREMENT";
const string SkillTextKeys::SKILL_GENERAL_WEAVING = "SKILL_GENERAL_WEAVING";
const string SkillTextKeys::SKILL_GENERAL_WEAVING_INCREMENT = "SKILL_GENERAL_WEAVING_INCREMENT";

// Weapon (Melee)
const string SkillTextKeys::SKILLS_WEAPON = "SKILLS_WEAPON";
const string SkillTextKeys::SKILL_MELEE_AXES = "SKILL_MELEE_AXES";
const string SkillTextKeys::SKILL_MELEE_AXES_INCREMENT = "SKILL_MELEE_AXES_INCREMENT";
const string SkillTextKeys::SKILL_MELEE_SHORT_BLADES = "SKILL_MELEE_SHORT_BLADES";
const string SkillTextKeys::SKILL_MELEE_SHORT_BLADES_INCREMENT = "SKILL_MELEE_SHORT_BLADES_INCREMENT";
const string SkillTextKeys::SKILL_MELEE_LONG_BLADES = "SKILL_MELEE_LONG_BLADES";
const string SkillTextKeys::SKILL_MELEE_LONG_BLADES_INCREMENT = "SKILL_MELEE_LONG_BLADES_INCREMENT";
const string SkillTextKeys::SKILL_MELEE_BLUDGEONS = "SKILL_MELEE_BLUDGEONS";
const string SkillTextKeys::SKILL_MELEE_BLUDGEONS_INCREMENT = "SKILL_MELEE_BLUDGEONS_INCREMENT";
const string SkillTextKeys::SKILL_MELEE_DAGGERS = "SKILL_MELEE_DAGGERS";
const string SkillTextKeys::SKILL_MELEE_DAGGERS_INCREMENT = "SKILL_MELEE_DAGGERS_INCREMENT";
const string SkillTextKeys::SKILL_MELEE_RODS_AND_STAVES = "SKILL_MELEE_RODS_AND_STAVES";
const string SkillTextKeys::SKILL_MELEE_RODS_AND_STAVES_INCREMENT = "SKILL_MELEE_RODS_AND_STAVES_INCREMENT";
const string SkillTextKeys::SKILL_MELEE_SPEARS = "SKILL_MELEE_SPEARS";
const string SkillTextKeys::SKILL_MELEE_SPEARS_INCREMENT = "SKILL_MELEE_SPEARS_INCREMENT";
const string SkillTextKeys::SKILL_MELEE_UNARMED = "SKILL_MELEE_UNARMED";
const string SkillTextKeys::SKILL_MELEE_UNARMED_INCREMENT = "SKILL_MELEE_UNARMED_INCREMENT";
const string SkillTextKeys::SKILL_MELEE_WHIPS = "SKILL_MELEE_WHIPS";
const string SkillTextKeys::SKILL_MELEE_WHIPS_INCREMENT = "SKILL_MELEE_WHIPS_INCREMENT";
const string SkillTextKeys::SKILL_MELEE_EXOTIC = "SKILL_MELEE_EXOTIC";
const string SkillTextKeys::SKILL_MELEE_EXOTIC_INCREMENT = "SKILL_MELEE_EXOTIC_INCREMENT";

// Weapon (Ranged)
const string SkillTextKeys::SKILLS_RANGED_WEAPON = "SKILLS_RANGED_WEAPON";
const string SkillTextKeys::SKILL_RANGED_AXES = "SKILL_RANGED_AXES";
const string SkillTextKeys::SKILL_RANGED_AXES_INCREMENT = "SKILL_RANGED_AXES_INCREMENT";
const string SkillTextKeys::SKILL_RANGED_BLADES = "SKILL_RANGED_BLADES";
const string SkillTextKeys::SKILL_RANGED_BLADES_INCREMENT = "SKILL_RANGED_BLADES_INCREMENT";
const string SkillTextKeys::SKILL_RANGED_BLUDGEONS = "SKILL_RANGED_BLUDGEONS";
const string SkillTextKeys::SKILL_RANGED_BLUDGEONS_INCREMENT = "SKILL_RANGED_BLUDGEONS_INCREMENT";
const string SkillTextKeys::SKILL_RANGED_BOWS = "SKILL_RANGED_BOWS";
const string SkillTextKeys::SKILL_RANGED_BOWS_INCREMENT = "SKILL_RANGED_BOWS_INCREMENT";
const string SkillTextKeys::SKILL_RANGED_CROSSBOWS = "SKILL_RANGED_CROSSBOWS";
const string SkillTextKeys::SKILL_RANGED_CROSSBOWS_INCREMENT = "SKILL_RANGED_CROSSBOWS_INCREMENT";
const string SkillTextKeys::SKILL_RANGED_DAGGERS = "SKILL_RANGED_DAGGERS";
const string SkillTextKeys::SKILL_RANGED_DAGGERS_INCREMENT = "SKILL_RANGED_DAGGERS_INCREMENT";
const string SkillTextKeys::SKILL_RANGED_ROCKS = "SKILL_RANGED_ROCKS";
const string SkillTextKeys::SKILL_RANGED_ROCKS_INCREMENT = "SKILL_RANGED_ROCKS_INCREMENT";
const string SkillTextKeys::SKILL_RANGED_SLINGS = "SKILL_RANGED_SLINGS";
const string SkillTextKeys::SKILL_RANGED_SLINGS_INCREMENT = "SKILL_RANGED_SLINGS_INCREMENT";
const string SkillTextKeys::SKILL_RANGED_SPEARS = "SKILL_RANGED_SPEARS";
const string SkillTextKeys::SKILL_RANGED_SPEARS_INCREMENT = "SKILL_RANGED_SPEARS_INCREMENT";
const string SkillTextKeys::SKILL_RANGED_EXOTIC = "SKILL_RANGED_EXOTIC";
const string SkillTextKeys::SKILL_RANGED_EXOTIC_INCREMENT = "SKILL_RANGED_EXOTIC_INCREMENT";

// Magic
const string SkillTextKeys::SKILLS_MAGIC = "SKILLS_MAGIC";
const string SkillTextKeys::SKILL_MAGIC_ARCANE = "SKILL_MAGIC_ARCANE";
const string SkillTextKeys::SKILL_MAGIC_ARCANE_INCREMENT = "SKILL_MAGIC_ARCANE_INCREMENT";
const string SkillTextKeys::SKILL_MAGIC_DIVINE = "SKILL_MAGIC_DIVINE";
const string SkillTextKeys::SKILL_MAGIC_DIVINE_INCREMENT = "SKILL_MAGIC_DIVINE_INCREMENT";
const string SkillTextKeys::SKILL_MAGIC_MYSTIC = "SKILL_MAGIC_MYSTIC";
const string SkillTextKeys::SKILL_MAGIC_MYSTIC_INCREMENT = "SKILL_MAGIC_MYSTIC_INCREMENT";
const string SkillTextKeys::SKILL_MAGIC_PRIMORDIAL = "SKILL_MAGIC_PRIMORDIAL";
const string SkillTextKeys::SKILL_MAGIC_PRIMORDIAL_INCREMENT = "SKILL_MAGIC_PRIMORDIAL_INCREMENT";

// Item types
ItemTypeTextKeys::ItemTypeTextKeys()
{
}

ItemTypeTextKeys::~ItemTypeTextKeys()
{
}

const string ItemTypeTextKeys::ITEM_TYPE_MISC       = "ITEM_TYPE_MISC";
const string ItemTypeTextKeys::ITEM_TYPE_WEAPONS    = "ITEM_TYPE_WEAPONS";
const string ItemTypeTextKeys::ITEM_TYPE_ARMOURS    = "ITEM_TYPE_ARMOURS";
const string ItemTypeTextKeys::ITEM_TYPE_POTIONS    = "ITEM_TYPE_POTIONS";
const string ItemTypeTextKeys::ITEM_TYPE_BOOKS      = "ITEM_TYPE_BOOKS";
const string ItemTypeTextKeys::ITEM_TYPE_SCROLLS    = "ITEM_TYPE_SCROLLS";
const string ItemTypeTextKeys::ITEM_TYPE_WANDS      = "ITEM_TYPE_WANDS";
const string ItemTypeTextKeys::ITEM_TYPE_STAVES     = "ITEM_TYPE_STAVES";
const string ItemTypeTextKeys::ITEM_TYPE_RINGS      = "ITEM_TYPE_RINGS";
const string ItemTypeTextKeys::ITEM_TYPE_AMULETS    = "ITEM_TYPE_AMULETS";
const string ItemTypeTextKeys::ITEM_TYPE_FOOD       = "ITEM_TYPE_FOOD";
const string ItemTypeTextKeys::ITEM_TYPE_AMMUNITION = "ITEM_TYPE_AMMUNITION";
const string ItemTypeTextKeys::ITEM_TYPE_PLANTS     = "ITEM_TYPE_PLANTS";
const string ItemTypeTextKeys::ITEM_TYPE_BOATS      = "ITEM_TYPE_BOATS";
const string ItemTypeTextKeys::ITEM_TYPE_CURRENCY   = "ITEM_TYPE_CURRENCY";
const string ItemTypeTextKeys::ITEM_TYPE_TOOLS      = "ITEM_TYPE_TOOLS";

// Resistances
ResistanceTextKeys::ResistanceTextKeys()
{
}

ResistanceTextKeys::~ResistanceTextKeys()
{
}

const string ResistanceTextKeys::RESISTANCE_SLASH = "RESISTANCE_SLASH";
const string ResistanceTextKeys::RESISTANCE_POUND = "RESISTANCE_POUND";
const string ResistanceTextKeys::RESISTANCE_PIERCE = "RESISTANCE_PIERCE";
const string ResistanceTextKeys::RESISTANCE_HEAT = "RESISTANCE_HEAT";
const string ResistanceTextKeys::RESISTANCE_COLD = "RESISTANCE_COLD";
const string ResistanceTextKeys::RESISTANCE_ACID = "RESISTANCE_ACID";
const string ResistanceTextKeys::RESISTANCE_POISON = "RESISTANCE_POISON";
const string ResistanceTextKeys::RESISTANCE_HOLY = "RESISTANCE_HOLY";
const string ResistanceTextKeys::RESISTANCE_SHADOW = "RESISTANCE_SHADOW";
const string ResistanceTextKeys::RESISTANCE_ARCANE = "RESISTANCE_ARCANE";
const string ResistanceTextKeys::RESISTANCE_MENTAL = "RESISTANCE_MENTAL";
const string ResistanceTextKeys::RESISTANCE_SONIC = "RESISTANCE_SONIC";
const string ResistanceTextKeys::RESISTANCE_RADIANT = "RESISTANCE_RADIANT";
const string ResistanceTextKeys::RESISTANCE_LIGHTNING = "RESISTANCE_LIGHTNING";

// Menu titles
MenuTitleKeys::MenuTitleKeys()
{
}

MenuTitleKeys::~MenuTitleKeys()
{
}

const string MenuTitleKeys::MENU_TITLE_QUEST_LIST = "MENU_TITLE_QUEST_LIST";

// Prompts
PromptTextKeys::PromptTextKeys()
{
}

PromptTextKeys::~PromptTextKeys()
{
}

const string PromptTextKeys::PROMPT_ANY_KEY = "PROMPT_ANY_KEY";
const string PromptTextKeys::PROMPT_ENTER_YOUR_NAME = "PROMPT_ENTER_YOUR_NAME";

// Special locations on the world map
WorldMapLocationTextKeys::WorldMapLocationTextKeys()
{
}

WorldMapLocationTextKeys::~WorldMapLocationTextKeys()
{
}

const string WorldMapLocationTextKeys::STARTING_LOCATION = "STARTING_LOCATION";
const string WorldMapLocationTextKeys::CURRENT_PLAYER_LOCATION = "CURRENT_PLAYER_LOCATION";

// Text keys for text related to movement in some way.
MovementTextKeys::MovementTextKeys()
{
}

MovementTextKeys::~MovementTextKeys()
{
}

const string MovementTextKeys::ACTION_MOVE_NO_EXIT               = "ACTION_MOVE_NO_EXIT";
const string MovementTextKeys::ACTION_MOVE_ADJACENT_HOSTILE_CREATURE = "ACTION_MOVE_ADJACENT_HOSTILE_CREATURE";
const string MovementTextKeys::ACTION_MOVE_OFF_WORLD_MAP         = "ACTION_MOVE_OFF_WORLD_MAP";
const string MovementTextKeys::ACTION_NO_WAY_UP_WORLD_MAP        = "ACTION_NO_WAY_UP_WORLD_MAP";
const string MovementTextKeys::ACTION_MOVE_OFF_OVERWORLD_MAP     = "ACTION_MOVE_OFF_OVERWORLD_MAP";
const string MovementTextKeys::ACTION_MOVE_OFF_UNDERWORLD_MAP    = "ACTION_MOVE_OFF_UNDERWORLD_MAP";
const string MovementTextKeys::ITEMS_ON_TILE                     = "ITEMS_ON_TILE";

// Text keys for descriptions of tiles
TileTextKeys::TileTextKeys()
{
}

TileTextKeys::~TileTextKeys()
{
}

const string TileTextKeys::TILE_DESC_BARROW         = "TILE_DESC_BARROW";
const string TileTextKeys::TILE_DESC_BEACH          = "TILE_DESC_BEACH";
const string TileTextKeys::TILE_DESC_BUSH           = "TILE_DESC_BUSH";
const string TileTextKeys::TILE_DESC_CAIRN          = "TILE_DESC_CAIRN";
const string TileTextKeys::TILE_DESC_CAVERN         = "TILE_DESC_CAVERN";
const string TileTextKeys::TILE_DESC_DESERT         = "TILE_DESC_DESERT";
const string TileTextKeys::TILE_DESC_DUNGEON        = "TILE_DESC_DUNGEON";
const string TileTextKeys::TILE_DESC_DUNGEON_COMPLEX = "TILE_DESC_DUNGEON_COMPLEX";
const string TileTextKeys::TILE_DESC_FIELD          = "TILE_DESC_FIELD";
const string TileTextKeys::TILE_DESC_FOREST         = "TILE_DESC_FOREST";
const string TileTextKeys::TILE_DESC_GRAVE          = "TILE_DESC_GRAVE";
const string TileTextKeys::TILE_DESC_HILLS          = "TILE_DESC_HILLS";
const string TileTextKeys::TILE_DESC_MARSH          = "TILE_DESC_MARSH";
const string TileTextKeys::TILE_DESC_MOUNTAINS      = "TILE_DESC_MOUNTAINS";
const string TileTextKeys::TILE_DESC_PIER           = "TILE_DESC_PIER";
const string TileTextKeys::TILE_DESC_REEDS          = "TILE_DESC_REEDS";
const string TileTextKeys::TILE_DESC_RIVER          = "TILE_DESC_RIVER";
const string TileTextKeys::TILE_DESC_ROAD           = "TILE_DESC_ROAD";
const string TileTextKeys::TILE_DESC_ROCK           = "TILE_DESC_ROCK";
const string TileTextKeys::TILE_DESC_UP_STAIRCASE   = "TILE_DESC_UP_STAIRCASE";
const string TileTextKeys::TILE_DESC_DOWN_STAIRCASE = "TILE_DESC_DOWN_STAIRCASE"; 
const string TileTextKeys::TILE_DESC_SCRUB          = "TILE_DESC_SCRUB";
const string TileTextKeys::TILE_DESC_SEA            = "TILE_DESC_SEA";
const string TileTextKeys::TILE_DESC_SHOALS         = "TILE_DESC_SHOALS";
const string TileTextKeys::TILE_DESC_SPRINGS        = "TILE_DESC_SPRINGS";
const string TileTextKeys::TILE_DESC_TREE           = "TILE_DESC_TREE";
const string TileTextKeys::TILE_DESC_VILLAGE        = "TILE_DESC_VILLAGE";
const string TileTextKeys::TILE_DESC_WEEDS          = "TILE_DESC_WEEDS";
const string TileTextKeys::TILE_DESC_WHEAT          = "TILE_DESC_WHEAT";
const string TileTextKeys::TILE_DESC_BARRACKS       = "TILE_DESC_BARRACKS";
const string TileTextKeys::TILE_DESC_CASTLE         = "TILE_DESC_CASTLE";
const string TileTextKeys::TILE_DESC_CHURCH         = "TILE_DESC_CHURCH";
const string TileTextKeys::TILE_DESC_GRAVEYARD      = "TILE_DESC_GRAVEYARD";
const string TileTextKeys::TILE_DESC_KEEP           = "TILE_DESC_KEEP";
const string TileTextKeys::TILE_DESC_LIBRARY        = "TILE_DESC_LIBRARY";
const string TileTextKeys::TILE_DESC_SITE_OF_DEATH  = "TILE_DESC_SITE_OF_DEATH";
const string TileTextKeys::TILE_DESC_TEMPLE         = "TILE_DESC_TEMPLE";
const string TileTextKeys::TILE_DESC_DAIS           = "TILE_DESC_DAIS";

// Text keys for tile extra descriptions
TileExtraDescriptionKeys::TileExtraDescriptionKeys()
{
}

TileExtraDescriptionKeys::~TileExtraDescriptionKeys()
{
}

const string TileExtraDescriptionKeys::TILE_EXTRA_DESCRIPTION_ISEN_DUN           = "TILE_EXTRA_DESCRIPTION_ISEN_DUN";
const string TileExtraDescriptionKeys::TILE_EXTRA_DESCRIPTION_ISEN_DUN_GRAVEYARD = "TILE_EXTRA_DESCRIPTION_ISEN_DUN_GRAVEYARD";
const string TileExtraDescriptionKeys::TILE_EXTRA_DESCRIPTION_ISEN_DUN_DUNGEON   = "TILE_EXTRA_DESCRIPTION_ISEN_DUN_DUNGEON";
const string TileExtraDescriptionKeys::TILE_EXTRA_DESCRIPTION_LAST_ISLAND_LAIR   = "TILE_EXTRA_DESCRIPTION_LAST_ISLAND_LAIR";

// Text keys for player/creature actions
ActionTextKeys::ActionTextKeys()
{
}

ActionTextKeys::~ActionTextKeys()
{
}

string ActionTextKeys::get_general_action_message(const string& desc_sid, const string& item_desc_sid, const string& player_sid, const string& monster_sid, const bool is_player)
{
  string message = StringTable::get(player_sid);
  
  if (!is_player)
  {
    message = StringTable::get(monster_sid);
    // Replace the creature part
    boost::replace_first(message, "%s", StringTable::get(desc_sid));
    message[0] = toupper(message[0]);
  }
  
  // Replace the item part.
  boost::replace_first(message, "%s", StringTable::get(item_desc_sid));
  
  return message;
}

string ActionTextKeys::get_quaff_message(const string& desc_sid, const string& potion_desc_sid, const bool is_player)
{
  return get_general_action_message(desc_sid, potion_desc_sid, ACTION_QUAFF_PLAYER, ACTION_QUAFF_MONSTER, is_player);
}

string ActionTextKeys::get_read_message(const string& desc_sid, const string& readable_desc_sid, const bool is_player)
{
  return get_general_action_message(desc_sid, readable_desc_sid, ACTION_READ_PLAYER, ACTION_READ_MONSTER, is_player);
}

string ActionTextKeys::get_eat_message(const string& desc_sid, const string& consumable_desc_sid, const bool is_player)
{
  return get_general_action_message(desc_sid, consumable_desc_sid, ACTION_EAT_PLAYER, ACTION_EAT_MONSTER, is_player);
}

string ActionTextKeys::get_full_message(const string& desc_sid, const string& consumable_desc_sid, const bool is_player)
{
  return get_general_action_message(desc_sid, consumable_desc_sid, ACTION_FULL_PLAYER, ACTION_FULL_MONSTER, is_player);
}

const string ActionTextKeys::ACTION_NOT_FOUND                  = "ACTION_NOT_FOUND";
const string ActionTextKeys::ACTION_SEARCH                     = "ACTION_SEARCH";
const string ActionTextKeys::ACTION_PICK_UP_NOT_ALLOWED        = "ACTION_PICK_UP_NOT_ALLOWED";
const string ActionTextKeys::ACTION_DROP_NOT_ALLOWED           = "ACTION_DROP_NOT_ALLOWED";
const string ActionTextKeys::ACTION_DROP_NO_ITEM_SELECTED      = "ACTION_DROP_NO_ITEM_SELECTED";
const string ActionTextKeys::ACTION_DROP_QUANTITY_PROMPT       = "ACTION_DROP_QUANTITY_PROMPT";
const string ActionTextKeys::ACTION_DROP_INVALID_QUANTITY      = "ACTION_DROP_INVALID_QUANTITY";
const string ActionTextKeys::ACTION_PICK_UP_NOTHING_ON_GROUND  = "ACTION_PICK_UP_NOTHING_ON_GROUND";
const string ActionTextKeys::ACTION_MOVEMENT_BLOCKED           = "ACTION_MOVEMENT_BLOCKED";
const string ActionTextKeys::ACTION_PLAYER_DROWNING            = "ACTION_PLAYER_DROWNING";
const string ActionTextKeys::ACTION_PLAYER_FALL_FROM_MOUNTAIN  = "ACTION_PLAYER_FALL_FROM_MOUNTAIN";
const string ActionTextKeys::ACTION_PLAYER_STARVING_TO_DEATH   = "ACTION_PLAYER_STARVING_TO_DEATH";
const string ActionTextKeys::ACTION_DETECTED_HOSTILE_CREATURES = "ACTION_DETECTED_HOSTILE_CREATURES";
const string ActionTextKeys::ACTION_LOOK                       = "ACTION_LOOK";
const string ActionTextKeys::ACTION_LOOK_UNEXPLORED_TILE       = "ACTION_LOOK_UNEXPLORED_TILE";
const string ActionTextKeys::ACTION_LOOK_TILE_OUT_OF_RANGE     = "ACTION_LOOK_TILE_OUT_OF_RANGE";
const string ActionTextKeys::ACTION_FIRE                       = "ACTION_FIRE";
const string ActionTextKeys::ACTION_NOTHING_HAPPENS            = "ACTION_NOTHING_HAPPENS";
const string ActionTextKeys::ACTION_CHAT_NOBODY_NEARBY         = "ACTION_CHAT_NOBODY_NEARBY";
const string ActionTextKeys::ACTION_CHAT_NO_RESPONSE           = "ACTION_CHAT_NO_RESPONSE";
const string ActionTextKeys::ACTION_GET_DIRECTION              = "ACTION_GET_DIRECTION";
const string ActionTextKeys::ACTION_OPEN_DOOR                  = "ACTION_OPEN_DOOR";
const string ActionTextKeys::ACTION_CLOSE_DOOR                 = "ACTION_CLOSE_DOOR";
const string ActionTextKeys::ACTION_DOOR_DESTROYED             = "ACTION_DOOR_DESTROYED";
const string ActionTextKeys::ACTION_APPLY_NO_FEATURES_PRESENT  = "ACTION_APPLY_NO_FEATURES_PRESENT";
const string ActionTextKeys::ACTION_HANDLE_LOCK                = "ACTION_HANDLE_LOCK";
const string ActionTextKeys::ACTION_HANDLE_LOCK_NO_KEY         = "ACTION_HANDLE_LOCK_NO_KEY";

const string ActionTextKeys::ACTION_QUAFF_PLAYER               = "ACTION_QUAFF_PLAYER";
const string ActionTextKeys::ACTION_QUAFF_MONSTER              = "ACTION_QUAFF_MONSTER";
const string ActionTextKeys::ACTION_READ_PLAYER                = "ACTION_READ_PLAYER";
const string ActionTextKeys::ACTION_READ_MONSTER               = "ACTION_READ_MONSTER";
const string ActionTextKeys::ACTION_EAT_PLAYER                 = "ACTION_EAT_PLAYER";
const string ActionTextKeys::ACTION_EAT_MONSTER                = "ACTION_EAT_MONSTER";
const string ActionTextKeys::ACTION_FULL_PLAYER                = "ACTION_FULL_PLAYER";
const string ActionTextKeys::ACTION_FULL_MONSTER               = "ACTION_FULL_MONSTER";

// Strings for various magical effects
EffectTextKeys::EffectTextKeys()
{
}

EffectTextKeys::~EffectTextKeys()
{
}

string EffectTextKeys::get_healing_effect_message(const string& monster_desc_sid, const bool is_player)
{
  return get_general_effect_message(monster_desc_sid, is_player, EFFECT_HEALING_PLAYER, EFFECT_HEALING_MONSTER);
}

string EffectTextKeys::get_ether_effect_message(const string& monster_desc_sid, const bool is_player)
{
  return get_general_effect_message(monster_desc_sid, is_player, EFFECT_ETHER_PLAYER, EFFECT_ETHER_MONSTER);
}

string EffectTextKeys::get_general_effect_message(const string& monster_desc_sid, const bool is_player, const string& player_msg_sid, const string& monster_msg_sid)
{
  string message = StringTable::get(player_msg_sid);

  if (!is_player)
  {
    message = StringTable::get(monster_msg_sid);
    boost::replace_first(message, "%s", StringTable::get(monster_desc_sid));
    message[0] = toupper(message[0]);
  }
  
  return message;  
}

string EffectTextKeys::get_identify_individual_item_message(const string& unid_usage_desc_sid, const string& id_usage_desc_sid)
{
  string id_message = StringTable::get(EFFECT_IDENTIFY_ITEM);
  
  boost::replace_first(id_message, "%s", StringTable::get(unid_usage_desc_sid));
  boost::replace_first(id_message, "%s", StringTable::get(id_usage_desc_sid));
  
  return id_message;
}

const string EffectTextKeys::EFFECT_HEALING_PLAYER = "EFFECT_HEALING_PLAYER";
const string EffectTextKeys::EFFECT_HEALING_MONSTER = "EFFECT_HEALING_MONSTER";
const string EffectTextKeys::EFFECT_NULL = "EFFECT_NULL";
const string EffectTextKeys::EFFECT_SWEET_TASTE = "EFFECT_SWEET_TASTE";
const string EffectTextKeys::EFFECT_FRUIT_JUICE = "EFFECT_FRUIT_JUICE";
const string EffectTextKeys::EFFECT_IDENTIFY_ALL_ITEMS = "EFFECT_IDENTIFY_ALL_ITEMS";
const string EffectTextKeys::EFFECT_IDENTIFY_TYPE = "EFFECT_IDENTIFY_TYPE";
const string EffectTextKeys::EFFECT_IDENTIFY_ITEM = "EFFECT_IDENTIFY_ITEM";
const string EffectTextKeys::EFFECT_ETHER_PLAYER = "EFFECT_ETHER_PLAYER";
const string EffectTextKeys::EFFECT_ETHER_MONSTER = "EFFECT_ETHER_MONSTER";

// Strings for the various seasons
SeasonTextKeys::SeasonTextKeys()
{
}

SeasonTextKeys::~SeasonTextKeys()
{
}

const string SeasonTextKeys::SEASON_TEXT_SPRING = "SEASON_TEXT_SPRING";
const string SeasonTextKeys::SEASON_TEXT_SUMMER = "SEASON_TEXT_SUMMER";
const string SeasonTextKeys::SEASON_TEXT_AUTUMN = "SEASON_TEXT_AUTUMN";
const string SeasonTextKeys::SEASON_TEXT_WINTER = "SEASON_TEXT_WINTER";

const string SeasonTextKeys::SEASON_TRANSITION_SPRING = "SEASON_TRANSITION_SPRING";
const string SeasonTextKeys::SEASON_TRANSITION_SUMMER = "SEASON_TRANSITION_SUMMER";
const string SeasonTextKeys::SEASON_TRANSITION_AUTUMN = "SEASON_TRANSITION_AUTUMN";
const string SeasonTextKeys::SEASON_TRANSITION_WINTER = "SEASON_TRANSITION_WINTER";

// Confirmation messages for moving on to dangerous tiles
TileDangerConfirmationKeys::TileDangerConfirmationKeys()
{
}

TileDangerConfirmationKeys::~TileDangerConfirmationKeys()
{
}

const string TileDangerConfirmationKeys::TILE_DANGER_MOUNTAINS = "TILE_DANGER_MOUNTAINS";

// Messages that can be sent to the user in the message buffer
TextMessages::TextMessages()
{
}

TextMessages::~TextMessages()
{
}

const string TextMessages::WELCOME_MESSAGE                    = "WELCOME_MESSAGE";
const string TextMessages::WELCOME_BACK_MESSAGE               = "WELCOME_BACK_MESSAGE";
const string TextMessages::DUMPING_CHARACTER_MESSAGE          = "DUMPING_CHARACTER_MESSAGE";
const string TextMessages::ITEM_DROP_MESSAGE                  = "ITEM_DROP_MESSAGE";
const string TextMessages::ITEM_PICK_UP_MESSAGE               = "ITEM_PICK_UP_MESSAGE";
const string TextMessages::ITEM_PICK_UP_AND_MERGE_MESSAGE     = "ITEM_PICK_UP_AND_MERGE_MESSAGE";
const string TextMessages::ITEM_ON_GROUND_DESCRIPTION_MESSAGE = "ITEM_ON_GROUND_DESCRIPTION_MESSAGE";
const string TextMessages::CURRENCY_MESSAGE_SINGLE            = "CURRENCY_MESSAGE_SINGLE";
const string TextMessages::CURRENCY_MESSAGE_MULTIPLE          = "CURRENCY_MESSAGE_MULTIPLE";

// Public functions used to access protected members.  These are used to wrap any const strings
// that contain replaceable symbols.
string TextMessages::get_welcome_message(const string& player_name, const bool new_player)
{
  string welcome_message = StringTable::get(TextMessages::WELCOME_BACK_MESSAGE);

  if (new_player)
  {
    welcome_message = StringTable::get(TextMessages::WELCOME_MESSAGE);
  }

  boost::replace_first(welcome_message, "%s", player_name);
  return welcome_message;
}

// Gets the overall death message.  This is the deity's message plus
// "You die..." (or equivalent)
string TextMessages::get_death_message(const string& deity_death_message_sid)
{
  string deity_death_message = StringTable::get(deity_death_message_sid);
  string you_die = StringTable::get(TextKeys::DEATH_MESSAGE);
  string death_message = deity_death_message + " " + you_die;
  return death_message;
}

// Gets the "The foo escapes into the wilderness." message.
string TextMessages::get_npc_escapes_message(const string& creature_description)
{
  string escapes_message = StringTable::get(TextKeys::NPC_ESCAPES_MESSAGE);
  boost::replace_first(escapes_message, "%s", creature_description);
  escapes_message[0] = toupper(escapes_message[0]);
  return escapes_message;
}

string TextMessages::get_action_not_found_message(const string& command_action)
{
  string action_message = StringTable::get(ActionTextKeys::ACTION_NOT_FOUND);
  boost::replace_first(action_message, "%s", String::clean(command_action));
  return action_message;
}

string TextMessages::get_dumping_character_message(const string& creature_name)
{
  string dumping_message = StringTable::get(TextMessages::DUMPING_CHARACTER_MESSAGE);
  boost::replace_first(dumping_message, "%s", creature_name);
  return dumping_message;
}

string TextMessages::get_sex(const CreatureSex sex)
{
  string creature_sex;
  
  switch(sex)
  {
    case CREATURE_SEX_MALE:
      creature_sex = StringTable::get(TextKeys::SEX_MALE);
      break;
    case CREATURE_SEX_FEMALE:
      creature_sex = StringTable::get(TextKeys::SEX_FEMALE);
      break;
    default:
      creature_sex = "?";
      break;
  }
  
  return creature_sex;
}

string TextMessages::get_equipment_location(const EquipmentWornLocation location)
{
  string equipment_location;
  
  switch(location)
  {
    case EQUIPMENT_WORN_HEAD:
      equipment_location = StringTable::get(EquipmentTextKeys::EQUIPMENT_HEAD);
      break;
    case EQUIPMENT_WORN_NECK:
      equipment_location = StringTable::get(EquipmentTextKeys::EQUIPMENT_NECK);
      break;
    case EQUIPMENT_WORN_RIGHT_FINGER:
      equipment_location = StringTable::get(EquipmentTextKeys::EQUIPMENT_RIGHT_FINGER);
      break;
    case EQUIPMENT_WORN_LEFT_FINGER:
      equipment_location = StringTable::get(EquipmentTextKeys::EQUIPMENT_LEFT_FINGER);
      break;
    case EQUIPMENT_WORN_WIELDED:
      equipment_location = StringTable::get(EquipmentTextKeys::EQUIPMENT_WIELDED);
      break;
    case EQUIPMENT_WORN_OFF_HAND:
      equipment_location = StringTable::get(EquipmentTextKeys::EQUIPMENT_OFF_HAND);
      break;
    case EQUIPMENT_WORN_BODY:
      equipment_location = StringTable::get(EquipmentTextKeys::EQUIPMENT_BODY);
      break;
    case EQUIPMENT_WORN_ABOUT_BODY:
      equipment_location = StringTable::get(EquipmentTextKeys::EQUIPMENT_ABOUT_BODY);
      break;
    case EQUIPMENT_WORN_FEET:
      equipment_location = StringTable::get(EquipmentTextKeys::EQUIPMENT_FEET);
      break;
    case EQUIPMENT_WORN_RANGED_WEAPON:
      equipment_location = StringTable::get(EquipmentTextKeys::EQUIPMENT_RANGED);
      break;
    case EQUIPMENT_WORN_AMMUNITION:
      equipment_location = StringTable::get(EquipmentTextKeys::EQUIPMENT_AMMUNITION);
      break;
    case EQUIPMENT_WORN_NONE:
    case EQUIPMENT_WORN_LAST:
    default:
      equipment_location = "?";
      break;
  }
  
  return equipment_location;
}

string TextMessages::get_confirmation_message(const string& query_sid)
{
  ostringstream ss;
  
  ss << StringTable::get(query_sid);
  ss << " [";
  ss << StringTable::get(TextKeys::DECISION_CONFIRM_KEY);
  ss << "/" << StringTable::get(TextKeys::DECISION_DENY_KEY);
  ss << "] ";
  
  return ss.str();
}

string TextMessages::get_area_entrance_message_given_terrain_type(const TileType type)
{
  string entrance_message;
  
  switch(type)
  {
    case TILE_TYPE_FIELD:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_FIELD);
      break;
    case TILE_TYPE_SCRUB:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_SCRUB);
      break;
    case TILE_TYPE_DESERT:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_DESERT);
      break;
    case TILE_TYPE_MOUNTAINS:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_MOUNTAINS);
      break;
    case TILE_TYPE_SEA:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_SEA);
      break;
    case TILE_TYPE_FOREST:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_FOREST);
      break;
    case TILE_TYPE_MARSH:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_MARSH);
      break;
    case TILE_TYPE_HILLS:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_HILLS);
      break;
    case TILE_TYPE_CAVERN:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_CAVERN);
      break;
    case TILE_TYPE_VILLAGE:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_VILLAGE);
      break;
    case TILE_TYPE_DUNGEON_COMPLEX:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_DUNGEON_COMPLEX);
      break;
    case TILE_TYPE_BARRACKS:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_BARRACKS);
      break;
    case TILE_TYPE_CASTLE:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_CASTLE);
      break;
    case TILE_TYPE_CHURCH:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_CHURCH);
      break;
    case TILE_TYPE_GRAVEYARD:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_GRAVEYARD);
      break;
    case TILE_TYPE_KEEP:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_KEEP);
      break;
    case TILE_TYPE_LIBRARY:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_LIBRARY);
      break;
    case TILE_TYPE_SITE_OF_DEATH:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_SITE_OF_DEATH);
      break;
    case TILE_TYPE_TEMPLE:
      entrance_message = StringTable::get(EntranceTextKeys::ENTRANCE_TEMPLE);
      break;
    case TILE_TYPE_UNDEFINED:
    case TILE_TYPE_WHEAT:
    case TILE_TYPE_CAIRN:
    case TILE_TYPE_TREE:
    case TILE_TYPE_ROAD:
    case TILE_TYPE_RIVER:
    case TILE_TYPE_SHOALS:
    case TILE_TYPE_DUNGEON:
    case TILE_TYPE_ROCK:
    case TILE_TYPE_GRAVE:
    case TILE_TYPE_REEDS:
    case TILE_TYPE_BEACH:
    case TILE_TYPE_BUSH:
    case TILE_TYPE_WEEDS:
    case TILE_TYPE_SPRINGS:
    case TILE_TYPE_DAIS:
    case TILE_TYPE_UP_STAIRCASE:
    case TILE_TYPE_DOWN_STAIRCASE:
    default:
      break;
  }
  
  return entrance_message;
}

string TextMessages::get_item_drop_message(const string& item_description, const uint quantity)
{
  // JCD FIXME: Once working, refactor to use ItemTranslator
  string desc = item_description;
  
  if (quantity > 1)
  {
    desc = item_description + " (" + Integer::to_string(quantity) + ")";
  }
  
  string item_message = StringTable::get(TextMessages::ITEM_DROP_MESSAGE);
  boost::replace_first(item_message, "%s", desc);
  return item_message;
  
}

string TextMessages::get_item_pick_up_message(ItemPtr item)
{
  ItemDescriber id(item);
  
  string item_message = StringTable::get(TextMessages::ITEM_PICK_UP_MESSAGE);
  boost::replace_first(item_message, "%s", id.describe());
  return item_message;
}

string TextMessages::get_item_pick_up_and_merge_message(ItemPtr item)
{
  ItemDescriber id(item);

  string item_message = StringTable::get(TextMessages::ITEM_PICK_UP_AND_MERGE_MESSAGE);
  boost::replace_first(item_message, "%s", id.describe());
  return item_message;
}

string TextMessages::get_item_on_ground_description_message(ItemPtr item)
{
  ItemDescriber id(item);

  string item_message = StringTable::get(TextMessages::ITEM_ON_GROUND_DESCRIPTION_MESSAGE);
  boost::replace_first(item_message, "%s", id.describe());
  return item_message;
}

string TextMessages::get_currency_amount_message(const uint currency_amount)
{
  string currency_message = StringTable::get(CURRENCY_MESSAGE_SINGLE);

  if (currency_amount != 1)
  {
    currency_message = StringTable::get(CURRENCY_MESSAGE_MULTIPLE);
    boost::replace_first(currency_message, "%s", Integer::to_string(currency_amount));
  }
  
  return currency_message;
}

// Descriptions of tile features
FeatureDescriptionTextKeys::FeatureDescriptionTextKeys()
{
}

const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_DOOR               = "FEATURE_DESCRIPTION_DOOR";
const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_GATE               = "FEATURE_DESCRIPTION_GATE";
const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_EVIL_ALTAR         = "FEATURE_DESCRIPTION_EVIL_ALTAR";
const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_GOOD_ALTAR         = "FEATURE_DESCRIPTION_GOOD_ALTAR";
const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_NEUTRAL_ALTAR      = "FEATURE_DESCRIPTION_NEUTRAL_ALTAR";
const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_FOUNTAIN           = "FEATURE_DESCRIPTION_FOUNTAIN";
const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_FIRE_PILLAR        = "FEATURE_DESCRIPTION_FIRE_PILLAR";
const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_PEW                = "FEATURE_DESCRIPTION_PEW";
const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_KING_STATUE        = "FEATURE_DESCRIPTION_KING_STATUE";
const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_QUEEN_STATUE       = "FEATURE_DESCRIPTION_QUEEN_STATUE";
const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_WARLORD_STATUE     = "FEATURE_DESCRIPTION_WARLORD_STATUE";
const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_KNIGHT_STATUE      = "FEATURE_DESCRIPTION_KNIGHT_STATUE";
const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_HIGH_PRIEST_STATUE = "FEATURE_DESCRIPTION_HIGH_PRIEST_STATUE";
const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_SORCEROR_STATUE    = "FEATURE_DESCRIPTION_SORCEROR_STATUE";
const string FeatureDescriptionTextKeys::FEATURE_DESCRIPTION_BENCH              = "FEATURE_DESCRIPTION_BENCH";

// Strings for Prayer
PrayerTextKeys::PrayerTextKeys()
{
}

PrayerTextKeys::~PrayerTextKeys()
{
}

string PrayerTextKeys::get_prayer_message(const string& deity_sid)
{
  string prayer_message = StringTable::get(PrayerTextKeys::PRAYER_INITIAL_MESSAGE);
  boost::replace_first(prayer_message, "%s", StringTable::get(deity_sid));
  
  return prayer_message;
}

const string PrayerTextKeys::PRAYER_INITIAL_MESSAGE = "PRAYER_INITIAL_MESSAGE";
const string PrayerTextKeys::PRAYER_DO_NOTHING      = "PRAYER_DO_NOTHING";
const string PrayerTextKeys::PRAYER_FULL_HP         = "PRAYER_FULL_HP";

// Strings for Combat
CombatTextKeys::CombatTextKeys()
{
}

string CombatTextKeys::get_close_miss_message(const bool is_player, const string& attacker, const string& miss_target)
{
  string close_miss_msg;
  
  if (is_player)
  {
    close_miss_msg = StringTable::get(CombatTextKeys::COMBAT_CLOSE_MISS_MESSAGE);
    boost::replace_first(close_miss_msg, "%s", miss_target);
  }
  else
  {
    close_miss_msg = StringTable::get(CombatTextKeys::COMBAT_CLOSE_MISS_MESSAGE_NP);
    boost::replace_first(close_miss_msg, "%s", attacker);
    boost::replace_first(close_miss_msg, "%s", miss_target);
    close_miss_msg[0] = toupper(close_miss_msg[0]);
  }
  
  return close_miss_msg;
}

string CombatTextKeys::get_miss_message(const bool is_player, const string& attacker, const string& miss_target)
{
  string miss_msg;

  if (is_player)
  {
    miss_msg = StringTable::get(CombatTextKeys::COMBAT_MISS_MESSAGE);
    boost::replace_first(miss_msg, "%s", miss_target);
  }
  else
  {
    miss_msg = StringTable::get(CombatTextKeys::COMBAT_MISS_MESSAGE_NP);
    boost::replace_first(miss_msg, "%s", attacker);
    boost::replace_first(miss_msg, "%s", miss_target);
    miss_msg[0] = toupper(miss_msg[0]);
  }
  
  return miss_msg;
}

string CombatTextKeys::get_critical_hit_message()
{
  string critical_hit_msg = StringTable::get(CombatTextKeys::COMBAT_CRITICAL_HIT_MESSAGE);
  return critical_hit_msg;
}

string CombatTextKeys::get_mighty_blow_message()
{
  string mighty_blow_msg = StringTable::get(CombatTextKeys::COMBAT_MIGHTY_BLOW_MESSAGE);
  return mighty_blow_msg;
}

string CombatTextKeys::get_hit_message(const bool is_player, const DamageType damage_type, const string& attacker, const string& hit_target)
{
  if (combat_damage_hit_messages.empty())
  {
    populate_combat_messages();
  }
  
  string key = create_key(is_player, damage_type);
  string hit_msg_sid = combat_damage_hit_messages[key];
  string hit_msg = StringTable::get(hit_msg_sid);
  
  // Now that we have the string, do the replacement(s) as necessary.
  if (is_player)
  {
    boost::replace_first(hit_msg, "%s", hit_target);
  }
  else
  {
    boost::replace_first(hit_msg, "%s", attacker);
    boost::replace_first(hit_msg, "%s", hit_target);
    hit_msg[0] = toupper(hit_msg[0]);
  }
  
  return hit_msg;
}

string CombatTextKeys::get_monster_death_message(const std::string& monster_name)
{
  string death_message = StringTable::get(CombatTextKeys::COMBAT_MONSTER_DEATH_MESSAGE);
  boost::replace_first(death_message, "%s", monster_name);
  death_message[0] = toupper(death_message[0]);
  return death_message;
}

string CombatTextKeys::get_no_damage_message(const bool is_player, const string& target)
{
  string no_damage_message;
  
  if (is_player)
  {
    no_damage_message = StringTable::get(CombatTextKeys::COMBAT_PLAYER_NO_DAMAGE_RECEIVED_MESSAGE);
    boost::replace_first(no_damage_message, "%s", StringTable::get(TextKeys::YOU));
  }
  else
  {
    no_damage_message = StringTable::get(CombatTextKeys::COMBAT_MONSTER_NO_DAMAGE_RECEIVED_MESSAGE);
    boost::replace_first(no_damage_message, "%s", target);
  }
  
  no_damage_message[0] = toupper(no_damage_message[0]);

  return no_damage_message;
}

string CombatTextKeys::get_ranged_attack_message(const bool is_player, const bool uses_launcher, const string& attacker, const string& ammunition, const string& target)
{
  string ranged_attack_message;
  bool has_target = !target.empty();
  
  if (is_player)
  {
    if (uses_launcher)
    {
      if (has_target)
      {
        ranged_attack_message = StringTable::get(CombatTextKeys::COMBAT_PLAYER_RANGED_ATTACK_LAUNCHER_MESSAGE);
      }
      else
      {
        ranged_attack_message = StringTable::get(CombatTextKeys::COMBAT_PLAYER_RANGED_ATTACK_LAUNCHER_NO_TARGET_MESSAGE);
      }
    }
    else
    {
      if (has_target)
      {
        ranged_attack_message = StringTable::get(CombatTextKeys::COMBAT_PLAYER_RANGED_ATTACK_MESSAGE);
      }
      else
      {
        ranged_attack_message = StringTable::get(CombatTextKeys::COMBAT_PLAYER_RANGED_ATTACK_NO_TARGET_MESSAGE);
      }
    }

    boost::replace_first(ranged_attack_message, "%s", StringTable::get(TextKeys::YOU));
    boost::replace_first(ranged_attack_message, "%s", ammunition);
    if (has_target) boost::replace_first(ranged_attack_message, "%s", target);
  }
  else
  {
    if (uses_launcher)
    {
      if (has_target)
      {
        ranged_attack_message = StringTable::get(CombatTextKeys::COMBAT_MONSTER_RANGED_ATTACK_LAUNCHER_MESSAGE);
      }
      else
      {
        ranged_attack_message = StringTable::get(CombatTextKeys::COMBAT_MONSTER_RANGED_ATTACK_LAUNCHER_NO_TARGET_MESSAGE);
      }
    }
    else
    {
      if (has_target)
      {
        ranged_attack_message = StringTable::get(CombatTextKeys::COMBAT_MONSTER_RANGED_ATTACK_MESSAGE);
      }
      else
      {
        ranged_attack_message = StringTable::get(CombatTextKeys::COMBAT_MONSTER_RANGED_ATTACK_NO_TARGET_MESSAGE);
      }
    }
    
    boost::replace_first(ranged_attack_message, "%s", attacker);
    boost::replace_first(ranged_attack_message, "%s", ammunition);
    if (has_target) boost::replace_first(ranged_attack_message, "%s", target);
  }
  
  ranged_attack_message[0] = toupper(ranged_attack_message[0]);
  return ranged_attack_message;
}

void CombatTextKeys::populate_combat_messages()
{
  combat_damage_hit_messages.insert(make_pair(create_key(0, DAMAGE_TYPE_SLASH), CombatTextKeys::COMBAT_HIT_SLASH_NP));
  combat_damage_hit_messages.insert(make_pair(create_key(1, DAMAGE_TYPE_SLASH), CombatTextKeys::COMBAT_HIT_SLASH));

  combat_damage_hit_messages.insert(make_pair(create_key(0, DAMAGE_TYPE_POUND), CombatTextKeys::COMBAT_HIT_POUND_NP));
  combat_damage_hit_messages.insert(make_pair(create_key(1, DAMAGE_TYPE_POUND), CombatTextKeys::COMBAT_HIT_POUND));

  combat_damage_hit_messages.insert(make_pair(create_key(0, DAMAGE_TYPE_PIERCE), CombatTextKeys::COMBAT_HIT_PIERCE_NP));
  combat_damage_hit_messages.insert(make_pair(create_key(1, DAMAGE_TYPE_PIERCE), CombatTextKeys::COMBAT_HIT_PIERCE));

  combat_damage_hit_messages.insert(make_pair(create_key(0, DAMAGE_TYPE_HEAT), CombatTextKeys::COMBAT_HIT_HEAT_NP));
  combat_damage_hit_messages.insert(make_pair(create_key(1, DAMAGE_TYPE_HEAT), CombatTextKeys::COMBAT_HIT_HEAT));

  combat_damage_hit_messages.insert(make_pair(create_key(0, DAMAGE_TYPE_COLD), CombatTextKeys::COMBAT_HIT_COLD_NP));
  combat_damage_hit_messages.insert(make_pair(create_key(1, DAMAGE_TYPE_COLD), CombatTextKeys::COMBAT_HIT_COLD));

  combat_damage_hit_messages.insert(make_pair(create_key(0, DAMAGE_TYPE_ACID), CombatTextKeys::COMBAT_HIT_ACID_NP));
  combat_damage_hit_messages.insert(make_pair(create_key(1, DAMAGE_TYPE_ACID), CombatTextKeys::COMBAT_HIT_ACID));

  combat_damage_hit_messages.insert(make_pair(create_key(0, DAMAGE_TYPE_POISON), CombatTextKeys::COMBAT_HIT_POISON_NP));
  combat_damage_hit_messages.insert(make_pair(create_key(1, DAMAGE_TYPE_POISON), CombatTextKeys::COMBAT_HIT_POISON));

  combat_damage_hit_messages.insert(make_pair(create_key(0, DAMAGE_TYPE_HOLY), CombatTextKeys::COMBAT_HIT_HOLY_NP));
  combat_damage_hit_messages.insert(make_pair(create_key(1, DAMAGE_TYPE_HOLY), CombatTextKeys::COMBAT_HIT_HOLY));

  combat_damage_hit_messages.insert(make_pair(create_key(0, DAMAGE_TYPE_SHADOW), CombatTextKeys::COMBAT_HIT_SHADOW_NP));
  combat_damage_hit_messages.insert(make_pair(create_key(1, DAMAGE_TYPE_SHADOW), CombatTextKeys::COMBAT_HIT_SHADOW));

  combat_damage_hit_messages.insert(make_pair(create_key(0, DAMAGE_TYPE_ARCANE), CombatTextKeys::COMBAT_HIT_ARCANE_NP));
  combat_damage_hit_messages.insert(make_pair(create_key(1, DAMAGE_TYPE_ARCANE), CombatTextKeys::COMBAT_HIT_ARCANE));

  combat_damage_hit_messages.insert(make_pair(create_key(0, DAMAGE_TYPE_MENTAL), CombatTextKeys::COMBAT_HIT_MENTAL_NP));
  combat_damage_hit_messages.insert(make_pair(create_key(1, DAMAGE_TYPE_MENTAL), CombatTextKeys::COMBAT_HIT_MENTAL));
  
  combat_damage_hit_messages.insert(make_pair(create_key(0, DAMAGE_TYPE_SONIC), CombatTextKeys::COMBAT_HIT_SONIC_NP));
  combat_damage_hit_messages.insert(make_pair(create_key(1, DAMAGE_TYPE_SONIC), CombatTextKeys::COMBAT_HIT_SONIC));

  combat_damage_hit_messages.insert(make_pair(create_key(0, DAMAGE_TYPE_RADIANT), CombatTextKeys::COMBAT_HIT_RADIANT_NP));
  combat_damage_hit_messages.insert(make_pair(create_key(1, DAMAGE_TYPE_RADIANT), CombatTextKeys::COMBAT_HIT_RADIANT));

  combat_damage_hit_messages.insert(make_pair(create_key(0, DAMAGE_TYPE_LIGHTNING), CombatTextKeys::COMBAT_HIT_LIGHTNING_NP));
  combat_damage_hit_messages.insert(make_pair(create_key(1, DAMAGE_TYPE_LIGHTNING), CombatTextKeys::COMBAT_HIT_LIGHTNING));
}

string CombatTextKeys::create_key(const bool is_player, const DamageType damage_type)
{
  ostringstream ss;
  ss << is_player << ":" << damage_type;
  return ss.str();
}

const string CombatTextKeys::COMBAT_TARGET_TOO_FAR_AWAY = "COMBAT_TARGET_TOO_FAR_AWAY";
const string CombatTextKeys::COMBAT_PLAYER_RANGED_ATTACK_MESSAGE = "COMBAT_PLAYER_RANGED_ATTACK_MESSAGE";
const string CombatTextKeys::COMBAT_MONSTER_RANGED_ATTACK_MESSAGE = "COMBAT_MONSTER_RANGED_ATTACK_MESSAGE";
const string CombatTextKeys::COMBAT_PLAYER_RANGED_ATTACK_LAUNCHER_MESSAGE = "COMBAT_PLAYER_RANGED_ATTACK_LAUNCHER_MESSAGE";
const string CombatTextKeys::COMBAT_MONSTER_RANGED_ATTACK_LAUNCHER_MESSAGE = "COMBAT_MONSTER_RANGED_ATTACK_LAUNCHER_MESSAGE";
const string CombatTextKeys::COMBAT_PLAYER_RANGED_ATTACK_NO_TARGET_MESSAGE = "COMBAT_PLAYER_RANGED_ATTACK_NO_TARGET_MESSAGE";
const string CombatTextKeys::COMBAT_MONSTER_RANGED_ATTACK_NO_TARGET_MESSAGE = "COMBAT_MONSTER_RANGED_ATTACK_NO_TARGET_MESSAGE";
const string CombatTextKeys::COMBAT_PLAYER_RANGED_ATTACK_LAUNCHER_NO_TARGET_MESSAGE = "COMBAT_PLAYER_RANGED_ATTACK_LAUNCHER_NO_TARGET_MESSAGE";
const string CombatTextKeys::COMBAT_MONSTER_RANGED_ATTACK_LAUNCHER_NO_TARGET_MESSAGE = "COMBAT_MONSTER_RANGED_ATTACK_LAUNCHER_NO_TARGET_MESSAGE";
const string CombatTextKeys::COMBAT_PLAYER_NO_DAMAGE_RECEIVED_MESSAGE  = "COMBAT_PLAYER_NO_DAMAGE_RECEIVED_MESSAGE";
const string CombatTextKeys::COMBAT_MONSTER_NO_DAMAGE_RECEIVED_MESSAGE = "COMBAT_MONSTER_NO_DAMAGE_RECEIVED_MESSAGE";
const string CombatTextKeys::COMBAT_MONSTER_DEATH_MESSAGE  = "COMBAT_MONSTER_DEATH_MESSAGE";
const string CombatTextKeys::COMBAT_CLOSE_MISS_MESSAGE     = "COMBAT_CLOSE_MISS_MESSAGE";
const string CombatTextKeys::COMBAT_CLOSE_MISS_MESSAGE_NP  = "COMBAT_CLOSE_MISS_MESSAGE_NP"; 
const string CombatTextKeys::COMBAT_MISS_MESSAGE           = "COMBAT_MISS_MESSAGE";
const string CombatTextKeys::COMBAT_MISS_MESSAGE_NP        = "COMBAT_MISS_MESSAGE_NP";
const string CombatTextKeys::COMBAT_CRITICAL_HIT_MESSAGE   = "COMBAT_CRITICAL_HIT_MESSAGE";
const string CombatTextKeys::COMBAT_MIGHTY_BLOW_MESSAGE    = "COMBAT_MIGHTY_BLOW_MESSAGE";
const string CombatTextKeys::COMBAT_HIT_SLASH              = "COMBAT_HIT_SLASH";
const string CombatTextKeys::COMBAT_HIT_SLASH_NP           = "COMBAT_HIT_SLASH_NP";
const string CombatTextKeys::COMBAT_HIT_POUND              = "COMBAT_HIT_POUND";
const string CombatTextKeys::COMBAT_HIT_POUND_NP           = "COMBAT_HIT_POUND_NP";
const string CombatTextKeys::COMBAT_HIT_PIERCE             = "COMBAT_HIT_PIERCE";
const string CombatTextKeys::COMBAT_HIT_PIERCE_NP          = "COMBAT_HIT_PIERCE_NP";
const string CombatTextKeys::COMBAT_HIT_HEAT               = "COMBAT_HIT_HEAT";
const string CombatTextKeys::COMBAT_HIT_HEAT_NP            = "COMBAT_HIT_HEAT_NP";
const string CombatTextKeys::COMBAT_HIT_COLD               = "COMBAT_HIT_COLD";
const string CombatTextKeys::COMBAT_HIT_COLD_NP            = "COMBAT_HIT_COLD_NP";
const string CombatTextKeys::COMBAT_HIT_ACID               = "COMBAT_HIT_ACID";
const string CombatTextKeys::COMBAT_HIT_ACID_NP            = "COMBAT_HIT_ACID_NP";
const string CombatTextKeys::COMBAT_HIT_POISON             = "COMBAT_HIT_POISON";
const string CombatTextKeys::COMBAT_HIT_POISON_NP          = "COMBAT_HIT_POISON_NP";
const string CombatTextKeys::COMBAT_HIT_HOLY               = "COMBAT_HIT_HOLY";
const string CombatTextKeys::COMBAT_HIT_HOLY_NP            = "COMBAT_HIT_HOLY_NP";
const string CombatTextKeys::COMBAT_HIT_SHADOW             = "COMBAT_HIT_SHADOW";
const string CombatTextKeys::COMBAT_HIT_SHADOW_NP          = "COMBAT_HIT_SHADOW_NP";
const string CombatTextKeys::COMBAT_HIT_ARCANE             = "COMBAT_HIT_ARCANE";
const string CombatTextKeys::COMBAT_HIT_ARCANE_NP          = "COMBAT_HIT_ARCANE_NP";
const string CombatTextKeys::COMBAT_HIT_MENTAL             = "COMBAT_HIT_MENTAL";
const string CombatTextKeys::COMBAT_HIT_MENTAL_NP          = "COMBAT_HIT_MENTAL_NP";
const string CombatTextKeys::COMBAT_HIT_SONIC              = "COMBAT_HIT_SONIC";
const string CombatTextKeys::COMBAT_HIT_SONIC_NP           = "COMBAT_HIT_SONIC_NP";
const string CombatTextKeys::COMBAT_HIT_RADIANT            = "COMBAT_HIT_RADIANT";
const string CombatTextKeys::COMBAT_HIT_RADIANT_NP         = "COMBAT_HIT_RADIANT_NP";
const string CombatTextKeys::COMBAT_HIT_LIGHTNING          = "COMBAT_HIT_LIGHTNING";
const string CombatTextKeys::COMBAT_HIT_LIGHTNING_NP       = "COMBAT_HIT_LIGHTNING_NP";

std::map<std::string, std::string> CombatTextKeys::combat_damage_hit_messages;

// Ranged combat messages
RangedCombatTextKeys::RangedCombatTextKeys()
{
}

RangedCombatTextKeys::~RangedCombatTextKeys()
{
}

const string RangedCombatTextKeys::RANGED_COMBAT_UNAVAILABLE_ON_WORLD_MAP   = "RANGED_COMBAT_UNAVAILABLE_ON_WORLD_MAP";
const string RangedCombatTextKeys::RANGED_COMBAT_WEAPON_NOT_EQUIPPED        = "RANGED_COMBAT_WEAPON_NOT_EQUIPPED";
const string RangedCombatTextKeys::RANGED_COMBAT_AMMUNITION_NOT_EQUIPPED    = "RANGED_COMBAT_AMMUNITION_NOT_EQUIPPED";
const string RangedCombatTextKeys::RANGED_COMBAT_WEAPON_AMMUNITION_MISMATCH = "RANGED_COMBAT_WEAPON_AMMUNITION_MISMATCH";
const string RangedCombatTextKeys::RANGED_COMBAT_AMMUNITION_REQUIRES_RANGED_WEAPON = "RANGED_COMBAT_AMMUNITION_REQUIRES_RANGED_WEAPON";

// Status ailment text keys:
const string StatusAilmentTextKeys::STATUS_HUNGER_STUFFED          = "STATUS_HUNGER_STUFFED";
const string StatusAilmentTextKeys::STATUS_MESSAGE_HUNGER_STUFFED  = "STATUS_MESSAGE_HUNGER_STUFFED";
const string StatusAilmentTextKeys::STATUS_HUNGER_FULL             = "STATUS_HUNGER_FULL";
const string StatusAilmentTextKeys::STATUS_MESSAGE_HUNGER_FULL     = "STATUS_MESSAGE_HUNGER_FULL";
const string StatusAilmentTextKeys::STATUS_HUNGER_NORMAL           = "STATUS_HUNGER_NORMAL";
const string StatusAilmentTextKeys::STATUS_MESSAGE_HUNGER_NORMAL   = "STATUS_MESSAGE_HUNGER_NORMAL";
const string StatusAilmentTextKeys::STATUS_HUNGER_HUNGRY           = "STATUS_HUNGER_HUNGRY";
const string StatusAilmentTextKeys::STATUS_MESSAGE_HUNGER_HUNGRY   = "STATUS_MESSAGE_HUNGER_HUNGRY";
const string StatusAilmentTextKeys::STATUS_HUNGER_STARVING         = "STATUS_HUNGER_STARVING";
const string StatusAilmentTextKeys::STATUS_MESSAGE_HUNGER_STARVING = "STATUS_MESSAGE_HUNGER_STARVING";
const string StatusAilmentTextKeys::STATUS_HUNGER_DYING            = "STATUS_HUNGER_DYING";
const string StatusAilmentTextKeys::STATUS_MESSAGE_HUNGER_DYING    = "STATUS_MESSAGE_HUNGER_DYING";
