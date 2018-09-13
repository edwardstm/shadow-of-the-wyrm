#pragma once

enum struct ClassIdentifier
{
  CLASS_ID_NULL = 0,
  CLASS_ID_GAME = 1,
  CLASS_ID_CURSES_DISPLAY = 2,
  CLASS_ID_COMMAND_FACTORY = 3,
  CLASS_ID_EQUIPMENT_COMMAND_FACTORY = 4,
  CLASS_ID_INVENTORY_COMMAND_FACTORY = 5,
  CLASS_ID_TILE_SELECTION_COMMAND_FACTORY = 6,
  CLASS_ID_ACTION_COORDINATOR = 7,
  CLASS_ID_ACTION_COST = 8,
  CLASS_ID_KEYBOARD_COMMAND_MAP = 9,
  CLASS_ID_EQUIPMENT_KEYBOARD_COMMAND_MAP = 10,
  CLASS_ID_INVENTORY_KEYBOARD_COMMAND_MAP = 11,
  CLASS_ID_TILE_SELECTION_KEYBOARD_COMMAND_MAP = 12,
  CLASS_ID_SCREEN_KEYBOARD_COMMAND_MAP = 13,
  CLASS_ID_HELP_KEYBOARD_COMMAND_MAP = 14,
  CLASS_ID_SKILLS_KEYBOARD_COMMAND_MAP = 15,
  CLASS_ID_ACTION_MANAGER = 16,
  CLASS_ID_TILE_SELECTION_ACTION = 17,
  CLASS_ID_WORLD = 18,
  CLASS_ID_CALENDAR = 19,
  CLASS_ID_SPRING = 20,
  CLASS_ID_SUMMER = 21,
  CLASS_ID_AUTUMN = 22,
  CLASS_ID_WINTER = 23,
  CLASS_ID_WORLD_TIME_KEEPER = 24,
  CLASS_ID_TIME_OBSERVER = 25,
  CLASS_ID_CREATURE_TIME_OBSERVER = 26,
  CLASS_ID_WORLD_TIME_OBSERVER = 27,
  CLASS_ID_SEASONS_TIME_OBSERVER = 28,
  CLASS_ID_SPECIAL_DAY_OBSERVER = 29,
  CLASS_ID_AGE_TIME_OBSERVER = 30,
  CLASS_ID_MAP_TIME_OBSERVER = 31,
  CLASS_ID_MAP_REGISTRY = 32,
  CLASS_ID_MAP = 33,
  CLASS_ID_DIMENSIONS = 34,
  CLASS_ID_DEPTH = 35,
  CLASS_ID_MAP_EXIT = 36,
  CLASS_ID_TILE = 37,
  CLASS_ID_BARRACKS_TILE = 38,
  CLASS_ID_BEACH_TILE = 39,
  CLASS_ID_BUSH_TILE = 40,
  CLASS_ID_CAIRN_TILE = 41,
  CLASS_ID_CASTLE_TILE = 42,
  CLASS_ID_CAVERN_TILE = 43,
  CLASS_ID_CHURCH_TILE = 44,
  CLASS_ID_DAIS_TILE = 45,
  CLASS_ID_DESERT_TILE = 46,
  CLASS_ID_DOWN_STAIRCASE_TILE = 47,
  CLASS_ID_DUNGEON_COMPLEX_TILE = 48,
  CLASS_ID_DUNGEON_TILE = 49,
  CLASS_ID_FIELD_TILE = 50,
  CLASS_ID_FOREST_TILE = 51,
  CLASS_ID_GRAVE_TILE = 52,
  CLASS_ID_BARROW_TILE = 53,
  CLASS_ID_GRAVEYARD_TILE = 54,
  CLASS_ID_HILLS_TILE = 55,
  CLASS_ID_KEEP_TILE = 56,
  CLASS_ID_LIBRARY_TILE = 57,
  CLASS_ID_MARSH_TILE = 58,
  CLASS_ID_MINE_TILE = 59,
  CLASS_ID_MOUNTAINS_TILE = 60,
  CLASS_ID_PIER_TILE = 61,
  CLASS_ID_REEDS_TILE = 62,
  CLASS_ID_RIVER_TILE = 63,
  CLASS_ID_ROAD_TILE = 64,
  CLASS_ID_ROCK_TILE = 65,
  CLASS_ID_SCRUB_TILE = 66,
  CLASS_ID_SEA_TILE = 67,
  CLASS_ID_SHOALS_TILE = 68,
  CLASS_ID_SITE_OF_DEATH_TILE = 69,
  CLASS_ID_SPRINGS_TILE = 70,
  CLASS_ID_STAIRCASE_TILE = 71,
  CLASS_ID_TEMPLE_TILE = 72,
  CLASS_ID_TREE_TILE = 73,
  CLASS_ID_UP_STAIRCASE_TILE = 74,
  CLASS_ID_VILLAGE_TILE = 75,
  CLASS_ID_WEEDS_TILE = 76,
  CLASS_ID_WHEAT_TILE = 77,
  CLASS_ID_WORLD_MAP_TILE = 78,
  CLASS_ID_WORLD_MAP_LANDMARK_TILE = 79,
  CLASS_ID_WORSHIP_SITE_TILE = 80,
  CLASS_ID_WILD_ORCHARD_TILE = 81,
  CLASS_ID_FRUIT_TREE_TILE = 82,
  CLASS_ID_EVERGREEN_TREE_TILE = 83,
  CLASS_ID_ROCKY_EARTH_TILE = 84,
  CLASS_ID_WELL_TILE = 85,
  CLASS_ID_CRYPT_TILE = 86,
  CLASS_ID_AIR_TILE = 87,
  CLASS_ID_EARTH_TILE = 88,
  CLASS_ID_SEWER_COMPLEX_TILE = 89,
  CLASS_ID_SEWER_TILE = 90,
  CLASS_ID_SHRINE_TILE = 91,
  CLASS_ID_SEABED_TILE = 92,
  CLASS_ID_AQUATIC_VEGETATION_TILE = 93,
  CLASS_ID_FLOATING_TOWER_TILE = 94,
  CLASS_ID_VOID_TILE = 95,
  CLASS_ID_MAGICAL_TREE_TILE = 96,
  CLASS_ID_FEATURE = 97,
  CLASS_ID_ALTAR = 98,
  CLASS_ID_ENTRANCE = 99,
  CLASS_ID_BENCH = 100,
  CLASS_ID_DECORATIVE_STATUE = 101,
  CLASS_ID_KING_DECORATIVE_STATUE = 102,
  CLASS_ID_QUEEN_DECORATIVE_STATUE = 103,
  CLASS_ID_WARLORD_DECORATIVE_STATUE = 104,
  CLASS_ID_KNIGHT_DECORATIVE_STATUE = 105,
  CLASS_ID_HIGH_PRIEST_DECORATIVE_STATUE = 106,
  CLASS_ID_SORCEROR_DECORATIVE_STATUE = 107,
  CLASS_ID_DOOR = 108,
  CLASS_ID_PEW = 109,
  CLASS_ID_EAST_WEST_PEW = 110,
  CLASS_ID_ENTRANCE_STATE = 111,
  CLASS_ID_GOOD_ALTAR = 112,
  CLASS_ID_NEUTRAL_ALTAR = 113,
  CLASS_ID_EVIL_ALTAR = 114,
  CLASS_ID_FIRE_PILLAR = 115,
  CLASS_ID_FOUNTAIN = 116,
  CLASS_ID_GATE = 117,
  CLASS_ID_LOCK = 118,
  CLASS_ID_TRAP = 119,
  CLASS_ID_SARCOPHAGUS = 120,
  CLASS_ID_TABLE = 121,
  CLASS_ID_BASIC_FEATURE = 122,
  CLASS_ID_SLOT_MACHINE = 123,
  CLASS_ID_SIGN = 124,
  CLASS_ID_PLAYER_DECISION_STRATEGY = 125,
  CLASS_ID_AUTOMATIC_MOVEMENT_DECISION_STRATEGY = 126,
  CLASS_ID_IMMOBILE_DECISION_STRATEGY = 127,
  CLASS_ID_MOBILE_DECISION_STRATEGY = 128,
  CLASS_ID_CURSES_KEYBOARD_CONTROLLER = 129,
  CLASS_ID_NULL_KEYBOARD_CONTROLLER = 130,
  CLASS_ID_THREAT_RATINGS = 131,
  CLASS_ID_CREATURE = 132,
  CLASS_ID_BOOL_STATISTIC = 133,
  CLASS_ID_STATISTIC = 134,
  CLASS_ID_DICE = 135,
  CLASS_ID_DAMAGE = 136,
  CLASS_ID_MOVEMENT_ACCUMULATION = 137,
  CLASS_ID_RELIGION = 138,
  CLASS_ID_DEITY_STATUS = 139,
  CLASS_ID_RESISTANCES = 140,
  CLASS_ID_SLASH_RESISTANCE = 141,
  CLASS_ID_PIERCE_RESISTANCE = 142,
  CLASS_ID_POUND_RESISTANCE = 143,
  CLASS_ID_HEAT_RESISTANCE = 144,
  CLASS_ID_COLD_RESISTANCE = 145,
  CLASS_ID_ACID_RESISTANCE = 146,
  CLASS_ID_POISON_RESISTANCE = 147,
  CLASS_ID_HOLY_RESISTANCE = 148,
  CLASS_ID_SHADOW_RESISTANCE = 149,
  CLASS_ID_ARCANE_RESISTANCE = 150,
  CLASS_ID_LIGHTNING_RESISTANCE = 151,
  CLASS_ID_SKILLS = 152,
  CLASS_ID_SKILL_ARCHERY = 153,
  CLASS_ID_SKILL_AWARENESS = 154,
  CLASS_ID_SKILL_BARGAINING = 155,
  CLASS_ID_SKILL_BEASTMASTERY = 156,
  CLASS_ID_SKILL_BLINDFIGHTING = 157,
  CLASS_ID_SKILL_BOATING = 158,
  CLASS_ID_SKILL_BOWYER = 159,
  CLASS_ID_SKILL_BREWING = 160,
  CLASS_ID_SKILL_CANTRIPS = 161,
  CLASS_ID_SKILL_CARRYING = 162,
  CLASS_ID_SKILL_COMBAT = 163,
  CLASS_ID_SKILL_CRAFTING = 164,
  CLASS_ID_SKILL_DESERT_LORE = 165,
  CLASS_ID_SKILL_DETECTION = 166,
  CLASS_ID_SKILL_DISARM_TRAPS = 167,
  CLASS_ID_SKILL_DUAL_WIELD = 168,
  CLASS_ID_SKILL_DUNGEONEERING = 169,
  CLASS_ID_SKILL_ESCAPE = 170,
  CLASS_ID_SKILL_FISHING = 171,
  CLASS_ID_SKILL_FLETCHERY = 172,
  CLASS_ID_SKILL_FORAGING = 173,
  CLASS_ID_SKILL_FOREST_LORE = 174,
  CLASS_ID_SKILL_HERBALISM = 175,
  CLASS_ID_SKILL_HIDING = 176,
  CLASS_ID_SKILL_HUNTING = 177,
  CLASS_ID_SKILL_INTIMIDATION = 178,
  CLASS_ID_SKILL_JEWELER = 179,
  CLASS_ID_SKILL_JUMPING = 180,
  CLASS_ID_SKILL_LEADERSHIP = 181,
  CLASS_ID_SKILL_LITERACY = 182,
  CLASS_ID_SKILL_LORE = 183,
  CLASS_ID_SKILL_MAGICGENERAL = 184,
  CLASS_ID_SKILL_MARSH_LORE = 185,
  CLASS_ID_SKILL_MEDICINE = 186,
  CLASS_ID_SKILL_MOUNTAIN_LORE = 187,
  CLASS_ID_SKILL_MOUNTAINEERING = 188,
  CLASS_ID_SKILL_MUSIC = 189,
  CLASS_ID_SKILL_NIGHT_SIGHT = 190,
  CLASS_ID_SKILL_OCEANOGRAPHY = 191,
  CLASS_ID_SKILL_PAPERCRAFT = 192,
  CLASS_ID_SKILL_RELIGION = 193,
  CLASS_ID_SKILL_SCRIBING = 194,
  CLASS_ID_SKILL_SKINNING = 195,
  CLASS_ID_SKILL_SMITHING = 196,
  CLASS_ID_SKILL_SPELUNKING = 197,
  CLASS_ID_SKILL_STEALTH = 198,
  CLASS_ID_SKILL_SWIMMING = 199,
  CLASS_ID_SKILL_TANNING = 200,
  CLASS_ID_SKILL_THIEVERY = 201,
  CLASS_ID_SKILL_WANDCRAFT = 202,
  CLASS_ID_SKILL_WEAVING = 203,
  CLASS_ID_SKILL_AXES = 204,
  CLASS_ID_SKILL_SHORT_BLADES = 205,
  CLASS_ID_SKILL_LONG_BLADES = 206,
  CLASS_ID_SKILL_BLUDGEONS = 207,
  CLASS_ID_SKILL_DAGGERS = 208,
  CLASS_ID_SKILL_RODS_AND_STAVES = 209,
  CLASS_ID_SKILL_SPEARS = 210,
  CLASS_ID_SKILL_UNARMED = 211,
  CLASS_ID_SKILL_WHIPS = 212,
  CLASS_ID_SKILL_EXOTIC = 213,
  CLASS_ID_SKILL_THROWN_AXES = 214,
  CLASS_ID_SKILL_THROWN_BLADES = 215,
  CLASS_ID_SKILL_THROWN_BLUDGEONS = 216,
  CLASS_ID_SKILL_BOWS = 217,
  CLASS_ID_SKILL_CROSSBOWS = 218,
  CLASS_ID_SKILL_THROWN_DAGGERS = 219,
  CLASS_ID_SKILL_ROCKS = 220,
  CLASS_ID_SKILL_SLINGS = 221,
  CLASS_ID_SKILL_THROWN_SPEARS = 222,
  CLASS_ID_SKILL_THROWN_EXOTIC = 223,
  CLASS_ID_SKILL_ARCANE = 224,
  CLASS_ID_SKILL_DIVINE = 225,
  CLASS_ID_SKILL_MYSTIC = 226,
  CLASS_ID_SKILL_PRIMORDIAL = 227,
  CLASS_ID_WEIGHT = 228,
  CLASS_ID_AMMUNITION = 229,
  CLASS_ID_AMULET = 230,
  CLASS_ID_ARMOUR = 231,
  CLASS_ID_BOAT = 232,
  CLASS_ID_SPELLBOOK = 233,
  CLASS_ID_CURRENCY = 234,
  CLASS_ID_TOOL = 235,
  CLASS_ID_FOOD = 236,
  CLASS_ID_MISC_ITEM = 237,
  CLASS_ID_PLANT = 238,
  CLASS_ID_POTION = 239,
  CLASS_ID_RING = 240,
  CLASS_ID_SCROLL = 241,
  CLASS_ID_STAFF = 242,
  CLASS_ID_WAND = 243,
  CLASS_ID_MELEE_WEAPON = 244,
  CLASS_ID_RANGED_WEAPON = 245,
  CLASS_ID_INVENTORY = 246,
  CLASS_ID_NULL_INVENTORY = 247,
  CLASS_ID_EQUIPMENT = 248,
  CLASS_ID_METADATA = 249,
  CLASS_ID_HUNGER_CLOCK = 250,
  CLASS_ID_GENERATION_VALUES = 251,
  CLASS_ID_CREATURE_GENERATION_VALUES = 252,
  CLASS_ID_MORTUARY = 253,
  CLASS_ID_QUESTS = 254,
  CLASS_ID_QUEST = 255,
  CLASS_ID_LOADED_MAP_DETAILS = 256,
  CLASS_ID_SPELL_KNOWLEDGE = 257,
  CLASS_ID_INDIVIDUAL_SPELL_KNOWLEDGE = 258,
  CLASS_ID_MAGIC_COMMAND_FACTORY = 259,
  CLASS_ID_SCREEN_COMMAND_FACTORY = 260,
  CLASS_ID_HELP_COMMAND_FACTORY = 261,
  CLASS_ID_SKILLS_COMMAND_FACTORY = 262,
  CLASS_ID_MAGIC_KEYBOARD_COMMAND_MAP = 263,
  CLASS_ID_REGULAR_STATUE = 264,
  CLASS_ID_PETRIFIED_CORPSE_STATUE = 265,
  CLASS_ID_SCRIPT_ENGINE = 266,
  CLASS_ID_AUTOMATIC_MOVEMENT = 267,
  CLASS_ID_STATUS_AILMENTS = 268,
  CLASS_ID_BARREL = 269,
  CLASS_ID_BLOOD = 270,
  CLASS_ID_CONDUCTS = 271,
  CLASS_ID_SCORE_FILE_ENTRY = 272,
  CLASS_ID_SETTINGS = 273,
  CLASS_ID_MESSAGE_BUFFER = 274,
  CLASS_ID_DEITY = 275,
  CLASS_ID_CREATURE_ACTIONS = 276,
  CLASS_ID_MODIFIER = 277,
  CLASS_ID_ALIGNMENT = 278,
  CLASS_ID_FORGE = 279,
  CLASS_ID_TANNERY = 280,
  CLASS_ID_JEWELER_WORKBENCH = 281,
  CLASS_ID_WHEEL_AND_LOOM = 282,
  CLASS_ID_BED = 283,
  CLASS_ID_STONE_MARKER = 284,
  CLASS_ID_INITIAL_ITEM = 285,
  CLASS_ID_SCRIPT_DETAILS = 286,
  CLASS_ID_DIG_CHANCES = 287,
  CLASS_ID_TILE_TRANSFORM = 288,
  CLASS_ID_TILE_TRANSFORM_OBSERVER = 289,
  CLASS_ID_CALENDAR_DAY = 290,
  CLASS_ID_MARKS = 291,
  CLASS_ID_SHOP = 292,
  CLASS_ID_SHOPS_TIME_OBSERVER = 293,
  CLASS_ID_STATUS = 294,
  CLASS_ID_STARTING_LOCATION = 295,
  CLASS_ID_MEMBERSHIPS = 296,
  CLASS_ID_MEMBERSHIP = 297
};

// Any class IDs needed for Lua scripts (e.g., feature class IDs) should go
// here.
//
// If you're adding tile IDs anywhere other than the end of the list, this
// value needs to be recalculated!
#define CCLASS_ID_FOUNTAIN 116
#define CCLASS_ID_FORGE 279
#define CCLASS_ID_TANNERY 280
#define CCLASS_ID_JEWELER_WORKBENCH 281
#define CCLASS_ID_WHEEL_AND_LOOM 282