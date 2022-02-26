require('constants')
require('fn')
require('quest')

-- Common quests for various NPCs.
local function add_common_quest_reward()
  local reward_ids = {}
  
  if RNG_percent_chance(75) then
    reward_ids = {{LIGHTNING_WAND_ID, 1}, {MAGICI_SHARD_ID, RNG_range(2, 4)}, {STONEFLOWER_ID, RNG_range(2, 4)}, {CURRENCY_ID, RNG_range(20, 30)}, {UNCURSING_SCROLL_ID, RNG_range(2,3)}, {SPEED_POTION_ID, RNG_range(2, 4)}, {ETHER_POTION_ID, RNG_range(2, 4)}, {HEALING_POTION_ID, RNG_range(2,4)}}
  else
    reward_ids = {{GOLDEN_APPLE_ID, 1}, {SILVER_APPLE_ID, 1}, {ENCHANTING_SCROLL_ID, 1}, {GAIN_ATTRIBUTES_POTION_ID, 1}}
  end

  local reward = reward_ids[RNG_range(1, #reward_ids)]
  add_object_to_player_tile(reward[1], reward[2])
end

-- Long day/thirsty quest
local function thirsty_start_fn()
  clear_and_add_message("THIRSTY_QUEST_START_SID")
end

local function thirsty_completion_condition_fn()
  return player_has_item(GNOMISH_STOUT_ID)
end

local function thirsty_completion_fn()
  remove_object_from_player(GNOMISH_STOUT_ID)
  
  add_message("THIRSTY_QUEST_COMPLETE_SID")
  add_common_quest_reward()
  Quest:try_additional_quest_reward()
  
  return true
end

-- New rowboat to visit family quest.
local function rowboat_start_fn()
  add_message_with_pause("ROWBOAT_QUEST_START_SID")
  clear_and_add_message("ROWBOAT_QUEST_START2_SID")
end

local function rowboat_completion_condition_fn()
  return player_has_item(ROWBOAT_ID)
end

local function rowboat_completion_fn()
  remove_object_from_player(ROWBOAT_ID)
  
  add_message("ROWBOAT_QUEST_COMPLETE_SID")
  add_object_to_player_tile(SPEED_POTION_ID)
  add_object_to_player_tile(CURRENCY_ID, RNG_range(50, 60))
  Quest:try_additional_quest_reward()

  return true
end

-- Fish for feast quest
local function fishfeast_start_fn()
  add_message_with_pause("FISHFEAST_QUEST_START_SID")
  add_message_with_pause("FISHFEAST_QUEST_START2_SID")
  clear_and_add_message("FISHFEAST_QUEST_START3_SID")
end

local function fishfeast_completion_condition_fn()
  return (player_has_item(SALMON_ID) and player_has_item(TROUT_ID))
end

local function fishfeast_completion_fn()
  remove_object_from_player(SALMON_ID)
  remove_object_from_player(TROUT_ID)
  
  add_message("FISHFEAST_QUEST_COMPLETE_SID")
  add_object_to_player_tile(SILVERWEED_ID, RNG_range(2,4))
  
  Quest:try_additional_quest_reward()
  
  return true
end

-- Escort to a village from when they were young...
local function villagevisit_start_fn()
  local cr_id = args[SPEAKING_CREATURE_ID]
  local v_name = get_creature_additional_property(cr_id, "CREATURE_PROPERTIES_ESCORT_DESTINATION_NAME")
  local v_loc = get_creature_additional_property(cr_id, "CREATURE_PROPERTIES_ESCORT_DESTINATION_LOCATION")
  
  add_message_with_pause("VILLAGEVISIT_QUEST_START_SID", {v_name, get_sid(v_loc)})
  add_message_with_pause("VILLAGEVISIT_QUEST_START2_SID")
  clear_and_add_message("VILLAGEVISIT_QUEST_START3_SID")

  -- Follow the player
  order_follow(cr_id, PLAYER_ID)
end

local function villagevisit_completion_condition_fn()
  -- JCD FIXME: Check to see if the player's last location on the world map
  -- matches that of the village we're supposed to visit.

  return false
end

local function villagevisit_completion_fn()
  local objs = {ENCHANTING_SCROLL_ID, GAIN_ATTRIBUTES_POTION_ID}
  local obj = objs[RNG_range(1, #objs)]
  local cr_id = args[SPEAKING_CREATURE_ID]

  Quest:remove_escort_details(cr_id)
  order_follow(cr_id, cr_id)

  add_object_to_player_tile(CURRENCY_ID, RNG_range(500, 600))
  add_object_to_player_tile(obj)

  clear_and_add_message("VISITVILLAGE_QUEST_COMPLETE_SID")

  return true
end

-- CommonQuest module.  Used to quests that can be used by a variety of
-- NPCs.
CommonQuests = {}
CommonQuests.__index = CommonQuests

local function get_quests(cr_id, sdesc_sid)
  local thirsty_quest = Quest:new("thirsty_" .. cr_id, 
                                  "THIRSTY_QUEST_TITLE_SID", 
                                  sdesc_sid,
                                  "THIRSTY_QUEST_DESCRIPTION_SID", 
                                  "THIRSTY_QUEST_COMPLETE_SID", 
                                  "THIRSTY_QUEST_REMINDER_SID", 
                                  truefn,
                                  thirsty_start_fn, 
                                  thirsty_completion_condition_fn, 
                                  thirsty_completion_fn)

  local rowboat_quest = Quest:new("rowboat_" .. cr_id, 
                                  "ROWBOAT_QUEST_TITLE_SID", 
                                  sdesc_sid,
                                  "ROWBOAT_QUEST_DESCRIPTION_SID", 
                                  "ROWBOAT_QUEST_COMPLETE_SID", 
                                  "ROWBOAT_QUEST_REMINDER_SID", 
                                  truefn,
                                  rowboat_start_fn, 
                                  rowboat_completion_condition_fn, 
                                  rowboat_completion_fn)

  local fishfeast_quest = Quest:new("fishfeast_" .. cr_id, 
                                    "FISHFEAST_QUEST_TITLE_SID", 
                                    sdesc_sid,
                                    "FISHFEAST_QUEST_DESCRIPTION_SID", 
                                    "FISHFEAST_QUEST_COMPLETE_SID", 
                                    "FISHFEAST_QUEST_REMINDER_SID", 
                                    truefn,
                                    fishfeast_start_fn, 
                                    fishfeast_completion_condition_fn, 
                                    fishfeast_completion_fn)

  -- Pick a village
  -- JCD FIXME: This fires EVERY TIME!
  local v_y, v_x, name, location
  v_y, v_x, name, location = get_random_village()
  
  Quest:set_escort_details(cr_id, v_y, v_x, name, location)
  
  local villagevisit_quest = Quest:new("villagevisit_" .. cr_id, 
                                       "VILLAGEVISIT_QUEST_TITLE_SID", 
                                       sdesc_sid,
                                       {"VILLAGEVISIT_QUEST_DESCRIPTION_SID", fn.array_to_csv({name, location})}, 
                                       "VILLAGEVISIT_QUEST_COMPLETE_SID", 
                                       {"VILLAGEVISIT_QUEST_REMINDER_SID", fn.array_to_csv({name, location})}, 
                                       truefn,
                                       villagevisit_start_fn, 
                                       villagevisit_completion_condition_fn, 
                                       villagevisit_completion_fn)

  local quests = {{thirsty_quest, 5},
                  {rowboat_quest, 5},
		  {fishfeast_quest, 5},
                  {villagevisit_quest, 100}}
  return quests
end

function CommonQuests:do_quests(creature_id)
  local sdesc_sid = get_creature_short_description_sid(creature_id)
  local quests = get_quests(creature_id, sdesc_sid)
  
  for i,v in ipairs(quests) do
    local do_quest = Quest:check_probabilistic_quest(creature_id, v[1].quest_id, v[2])
    
    if do_quest and v[1]:execute() then
      return true
    end
  end

  return false
end

