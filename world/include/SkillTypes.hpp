#pragma once

enum struct SkillsSelectionType
{
  SKILLS_SELECTION_SELECT_SKILL = 0,
  SKILLS_SELECTION_IMPROVE_SKILL = 1
};

enum struct SkillType
{
  SKILL_UNDEFINED = -1,
  SKILL_GENERAL_BEGIN = 0,
  SKILL_GENERAL_ARCHERY = 0,
  SKILL_GENERAL_AWARENESS = 1,
  SKILL_GENERAL_BARGAINING = 2,
  SKILL_GENERAL_BEASTMASTERY = 3,
  SKILL_GENERAL_BLIND_FIGHTING = 4,
  SKILL_GENERAL_BOATING = 5,
  SKILL_GENERAL_BOWYER = 6,
  SKILL_GENERAL_BREWING = 7,
  SKILL_GENERAL_CARRYING = 8,
  SKILL_GENERAL_COMBAT = 9,
  SKILL_GENERAL_CRAFTING = 10,
  SKILL_GENERAL_DESERT_LORE = 11,
  SKILL_GENERAL_DETECTION = 12,
  SKILL_GENERAL_DISARM_TRAPS = 13,
  SKILL_GENERAL_DUAL_WIELD = 14,
  SKILL_GENERAL_DUNGEONEERING = 15,
  SKILL_GENERAL_ESCAPE = 16,
  SKILL_GENERAL_FISHING = 17,
  SKILL_GENERAL_FLETCHERY = 18,
  SKILL_GENERAL_FORAGING = 19,
  SKILL_GENERAL_FOREST_LORE = 20,
  SKILL_GENERAL_HERBALISM = 21,
  SKILL_GENERAL_HIDING = 22,
  SKILL_GENERAL_HUNTING = 23,
  SKILL_GENERAL_INTIMIDATION = 24,
  SKILL_GENERAL_JEWELER = 25,
  SKILL_GENERAL_JUMPING = 26,
  SKILL_GENERAL_LEADERSHIP = 27,
  SKILL_GENERAL_LITERACY = 28,
  SKILL_GENERAL_LORE = 29,
  SKILL_GENERAL_MAGIC = 30,
  SKILL_GENERAL_MARSH_LORE = 31,
  SKILL_GENERAL_MEDICINE = 32,
  SKILL_GENERAL_MOUNTAIN_LORE = 33,
  // xx UNUSED = 34,
  SKILL_GENERAL_MUSIC = 35,
  SKILL_GENERAL_NIGHT_SIGHT = 36,
  SKILL_GENERAL_OCEAN_LORE = 37,
  SKILL_GENERAL_PAPERCRAFT = 38,
  SKILL_GENERAL_RELIGION = 39,
  SKILL_GENERAL_SCRIBING = 40,
  SKILL_GENERAL_SKINNING = 41,
  SKILL_GENERAL_SMITHING = 42,
  SKILL_GENERAL_SPELUNKING = 43,
  SKILL_GENERAL_STEALTH = 44,
  SKILL_GENERAL_SWIMMING = 45,
  SKILL_GENERAL_TANNING = 46,
  SKILL_GENERAL_THIEVERY = 47,
  SKILL_GENERAL_WANDCRAFT = 48,
  SKILL_GENERAL_WEAVING = 49,
  SKILL_GENERAL_LAST = 50,

  SKILL_MELEE_BEGIN = 1000,
  SKILL_MELEE_AXES = 1000,
  SKILL_MELEE_SHORT_BLADES = 1001,
  SKILL_MELEE_LONG_BLADES = 1002,
  SKILL_MELEE_BLUDGEONS = 1003,
  SKILL_MELEE_DAGGERS = 1004,
  SKILL_MELEE_RODS_AND_STAVES = 1005,
  SKILL_MELEE_SPEARS = 1006,
  SKILL_MELEE_UNARMED = 1007,
  SKILL_MELEE_WHIPS = 1008,
  SKILL_MELEE_EXOTIC = 1009,
  SKILL_MELEE_LAST = 1010,

  SKILL_RANGED_BEGIN = 2000,
  SKILL_RANGED_AXES = 2000,
  SKILL_RANGED_BLADES = 2001,
  SKILL_RANGED_BLUDGEONS = 2002,
  SKILL_RANGED_BOWS = 2003,
  SKILL_RANGED_CROSSBOWS = 2004,
  SKILL_RANGED_DAGGERS = 2005,
  SKILL_RANGED_ROCKS = 2006,
  SKILL_RANGED_SLINGS = 2007,
  SKILL_RANGED_SPEARS = 2008,
  SKILL_RANGED_EXOTIC = 2009,
  SKILL_RANGED_LAST = 2010,

  SKILL_MAGIC_BEGIN = 3000,
  SKILL_MAGIC_ARCANE = 3000,
  SKILL_MAGIC_DIVINE = 3001,
  SKILL_MAGIC_MYSTIC = 3002,
  SKILL_MAGIC_PRIMORDIAL = 3003,
  SKILL_MAGIC_CANTRIPS = 3004,
  SKILL_MAGIC_LAST = 3005
};

// Make the corresponding values available for the Lua code.
constexpr auto CSKILL_GENERAL_ARCHERY = 0;
constexpr auto CSKILL_GENERAL_AWARENESS = 1;
constexpr auto CSKILL_GENERAL_BARGAINING = 2;
constexpr auto CSKILL_GENERAL_BEASTMASTERY = 3;
constexpr auto CSKILL_GENERAL_BLIND_FIGHTING = 4;
constexpr auto CSKILL_GENERAL_BOATING = 5;
constexpr auto CSKILL_GENERAL_BOWYER = 6;
constexpr auto CSKILL_GENERAL_BREWING = 7;
constexpr auto CSKILL_GENERAL_CARRYING = 8;
constexpr auto CSKILL_GENERAL_COMBAT = 9;
constexpr auto CSKILL_GENERAL_CRAFTING = 10;
constexpr auto CSKILL_GENERAL_DESERT_LORE = 11;
constexpr auto CSKILL_GENERAL_DETECTION = 12;
constexpr auto CSKILL_GENERAL_DISARM_TRAPS = 13;
constexpr auto CSKILL_GENERAL_DUAL_WIELD = 14;
constexpr auto CSKILL_GENERAL_DUNGEONEERING = 15;
constexpr auto CSKILL_GENERAL_ESCAPE = 16;
constexpr auto CSKILL_GENERAL_FISHING = 17;
constexpr auto CSKILL_GENERAL_FLETCHERY = 18;
constexpr auto CSKILL_GENERAL_FORAGING = 19;
constexpr auto CSKILL_GENERAL_FOREST_LORE = 20;
constexpr auto CSKILL_GENERAL_HERBALISM = 21;
constexpr auto CSKILL_GENERAL_HIDING = 22;
constexpr auto CSKILL_GENERAL_HUNTING = 23;
constexpr auto CSKILL_GENERAL_INTIMIDATION = 24;
constexpr auto CSKILL_GENERAL_JEWELER = 25;
constexpr auto CSKILL_GENERAL_JUMPING = 26;
constexpr auto CSKILL_GENERAL_LEADERSHIP = 27;
constexpr auto CSKILL_GENERAL_LITERACY = 28;
constexpr auto CSKILL_GENERAL_LORE = 29;
constexpr auto CSKILL_GENERAL_MAGIC = 30;
constexpr auto CSKILL_GENERAL_MARSH_LORE = 31;
constexpr auto CSKILL_GENERAL_MEDICINE = 32;
constexpr auto CSKILL_GENERAL_MOUNTAIN_LORE = 33;
constexpr auto CSKILL_GENERAL_MUSIC = 35;
constexpr auto CSKILL_GENERAL_NIGHT_SIGHT = 36;
constexpr auto CSKILL_GENERAL_OCEAN_LORE = 37;
constexpr auto CSKILL_GENERAL_PAPERCRAFT = 38;
constexpr auto CSKILL_GENERAL_RELIGION = 39;
constexpr auto CSKILL_GENERAL_SCRIBING = 40;
constexpr auto CSKILL_GENERAL_SKINNING = 41;
constexpr auto CSKILL_GENERAL_SMITHING = 42;
constexpr auto CSKILL_GENERAL_SPELUNKING = 43;
constexpr auto CSKILL_GENERAL_STEALTH = 44;
constexpr auto CSKILL_GENERAL_SWIMMING = 45;
constexpr auto CSKILL_GENERAL_TANNING = 46;
constexpr auto CSKILL_GENERAL_THIEVERY = 47;
constexpr auto CSKILL_GENERAL_WANDCRAFT = 48;
constexpr auto CSKILL_GENERAL_WEAVING = 49;

constexpr auto CSKILL_MELEE_AXES = 1000;
constexpr auto CSKILL_MELEE_SHORT_BLADES = 1001;
constexpr auto CSKILL_MELEE_LONG_BLADES = 1002;
constexpr auto CSKILL_MELEE_BLUDGEONS = 1003;
constexpr auto CSKILL_MELEE_DAGGERS = 1004;
constexpr auto CSKILL_MELEE_RODS_AND_STAVES = 1005;
constexpr auto CSKILL_MELEE_SPEARS = 1006;
constexpr auto CSKILL_MELEE_UNARMED = 1007;
constexpr auto CSKILL_MELEE_WHIPS = 1008;
constexpr auto CSKILL_MELEE_EXOTIC = 1009;

constexpr auto CSKILL_RANGED_AXES = 2000;
constexpr auto CSKILL_RANGED_BLADES = 2001;
constexpr auto CSKILL_RANGED_BLUDGEONS = 2002;
constexpr auto CSKILL_RANGED_BOWS = 2003;
constexpr auto CSKILL_RANGED_CROSSBOWS = 2004;
constexpr auto CSKILL_RANGED_DAGGERS = 2005;
constexpr auto CSKILL_RANGED_ROCKS = 2006;
constexpr auto CSKILL_RANGED_SLINGS = 2007;
constexpr auto CSKILL_RANGED_SPEARS = 2008;
constexpr auto CSKILL_RANGED_EXOTIC = 2009;

constexpr auto CSKILL_MAGIC_ARCANE = 3000;
constexpr auto CSKILL_MAGIC_DIVINE = 3001;
constexpr auto CSKILL_MAGIC_MYSTIC = 3002;
constexpr auto CSKILL_MAGIC_PRIMORDIAL = 3003;
constexpr auto CSKILL_MAGIC_CANTRIPS = 3004;

enum struct SkillCategory
{
  SKILL_CATEGORY_UNDEFINED = -1,
  SKILL_CATEGORY_GENERAL = 0,
  SKILL_CATEGORY_MELEE = 1,
  SKILL_CATEGORY_RANGED = 2,
  SKILL_CATEGORY_MAGIC = 3
};

