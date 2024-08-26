#pragma once

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "Tile.hpp"

void set_local_creature(CreaturePtr creature);
CreaturePtr get_creature(const std::string& creature_id);
CreaturePtr get_creature_from_map(const std::string& creature_id, const std::string& map_id);
TilePtr get_tile(const std::string& map_id, const Coordinate& c);

// API prototypes
int add_message_with_pause(lua_State* ls);
int clear_messages(lua_State* ls);
int clear_and_add_message(lua_State* ls);
int add_message(lua_State* ls);
int add_fov_message(lua_State* ls);
int add_message_direct(lua_State* ls);
int add_debug_message(lua_State* ls);
int add_confirmation_message(lua_State* ls);
int add_prompt_message(lua_State* ls);
int add_char_message(lua_State* ls);
int add_message_for_creature(lua_State* ls);
int add_new_quest(lua_State* ls);
int is_on_quest(lua_State* ls);
int get_num_creature_killed_global(lua_State* ls);
int get_num_uniques_killed_global(lua_State* ls);
int is_unique(lua_State* ls);
int add_object_to_player_tile(lua_State* ls);
int add_object_with_resists_to_player_tile(lua_State* ls);
int add_objects_to_player_tile(lua_State* ls);
int add_object_to_map(lua_State* ls);
int add_object_to_creature(lua_State* ls);
int add_object_on_tile_to_creature(lua_State* ls);
int add_object_to_tile(lua_State* ls); // assumes current map
int add_randart_to_player_tile(lua_State* ls);
int add_key_to_player_tile(lua_State* ls);
int add_feature_to_map(lua_State* ls);
int add_all_base_features_to_map(lua_State* ls);
int add_configurable_feature_to_map(lua_State* ls);
int add_feature_to_player_tile(lua_State* ls);
int set_feature_additional_property(lua_State* ls);
int mark_quest_completed(lua_State* ls);
int remove_active_quest(lua_State* ls);
int is_quest_completed(lua_State* ls);
int get_quest_details(lua_State* ls);
int player_has_item(lua_State* ls);
int remove_object_from_player(lua_State* ls);
int is_item_generated(lua_State* ls);
int get_num_item_generated(lua_State* ls);
int set_skill_value(lua_State* ls);
int get_skill_value(lua_State* ls);
int get_magic_skills(lua_State* ls);
int check_skill(lua_State* ls);
int set_all_skills_value(lua_State* ls);
int RNG_range(lua_State* ls);
int RNG_percent_chance(lua_State* ls);
int RNG_dice(lua_State* ls);
int add_spell_castings(lua_State* ls);
int add_all_spells_castings(lua_State* ls);
int count_spells_known(lua_State* ls);
int gain_experience(lua_State* ls);
int get_experience_value(lua_State* ls);
int add_creature_to_map(lua_State* ls);
int remove_creature_from_map(lua_State* ls);
int add_status_to_creature(lua_State* ls);
int add_status_to_creature_at(lua_State* ls);
int remove_negative_statuses_from_creature(lua_State* ls);
int get_creature_statuses(lua_State* ls);
int creature_has_status(lua_State* ls);
int stop_playing_game(lua_State* ls);
int set_creature_base_damage(lua_State* ls);
int get_creature_base_damage(lua_State* ls);
int set_creature_intrinsic_resist(lua_State* ls);
int set_creature_speed(lua_State* ls);
int set_creature_str(lua_State* ls);
int set_creature_dex(lua_State* ls);
int set_creature_agi(lua_State* ls);
int set_creature_hea(lua_State* ls);
int set_creature_int(lua_State* ls);
int set_creature_wil(lua_State* ls);
int set_creature_cha(lua_State* ls);
int set_creature_piety(lua_State* ls);
int get_creature_piety(lua_State* ls);
int add_piety(lua_State* ls);
int set_creature_piety_regen_bonus(lua_State* ls);
int get_creature_piety_regen_bonus(lua_State* ls);
int get_creature_speed(lua_State* ls);
int get_creature_yx(lua_State* ls);
int get_creature_id(lua_State* ls);
int get_creature_ids(lua_State* ls);
int get_creature_base_id(lua_State* ls);
int get_creature_num_broken_conducts(lua_State* ls);
int get_current_map_id(lua_State* ls);
int get_map_id(lua_State* ls);
int get_map_exists(lua_State* ls);
int incr_str(lua_State* ls);
int incr_str_to_unburdened(lua_State* ls);
int incr_dex(lua_State* ls);
int incr_agi(lua_State* ls);
int incr_hea(lua_State* ls);
int incr_int(lua_State* ls);
int incr_wil(lua_State* ls);
int incr_cha(lua_State* ls);
int mark_stat(lua_State* ls);
int mark_str(lua_State* ls);
int mark_dex(lua_State* ls);
int mark_agi(lua_State* ls);
int mark_hea(lua_State* ls);
int mark_int(lua_State* ls);
int mark_wil(lua_State* ls);
int mark_cha(lua_State* ls);
int is_stat_max_marked(lua_State* ls);
int gain_level(lua_State* ls);
int goto_level(lua_State* ls);
int get_creature_level(lua_State* ls);
int is_player(lua_State* ls);
int map_set_custom_map_id(lua_State* ls);
int map_set_edesc(lua_State* ls);
int map_set_property(lua_State* ls);
int map_get_property(lua_State* ls);
int map_set_tile_subtype(lua_State* ls);
int map_set_tile_property(lua_State* ls);
int map_add_location(lua_State* ls);
int map_fill_random(lua_State*);
int map_fill_staggered(lua_State* ls);
int map_transform_tile(lua_State* ls);
int map_remove_tile_exit(lua_State* ls);
int map_add_tile_exit(lua_State* ls);
int map_set_explored(lua_State* ls);
int map_get_name_sid(lua_State* ls);
int map_get_dimensions(lua_State* ls);
int map_get_available_creature_coords(lua_State* ls);
int map_get_tile(lua_State* ls);
int map_do_tiles_in_range_match_type(lua_State* ls);
int map_creature_ids_have_substring(lua_State* ls);
int log(lua_State* ls);
int get_player_title(lua_State* ls);
int set_creature_at_fleeing(lua_State* ls);
int set_creature_current_hp(lua_State* ls);
int get_creature_current_hp(lua_State* ls);
int set_creature_base_hp(lua_State* ls);
int get_creature_base_hp(lua_State* ls);
int set_creature_current_ap(lua_State* ls);
int get_creature_current_ap(lua_State* ls);
int set_creature_base_ap(lua_State* ls);
int get_creature_base_ap(lua_State* ls);
int set_creature_name(lua_State* ls);
int get_creature_name(lua_State* ls);
int destroy_creature_equipment(lua_State* ls);
int destroy_creature_inventory(lua_State* ls);
int get_deity_summons(lua_State* ls);
int get_num_deities(lua_State* ls);
int clear_deities(lua_State* ls);
int summon_monsters_around_creature(lua_State* ls);
int summon_items_around_creature(lua_State* ls);
int creature_is_class(lua_State* ls);
int get_item_count(lua_State* ls);
int count_currency(lua_State* ls);
int get_unidentified_item_count(lua_State* ls);
int is_item_identified(lua_State* ls);
int get_item_value(lua_State* ls);
int select_item(lua_State* ls);
int set_hostility(lua_State* ls);
int set_map_hostility(lua_State* ls);
int is_creature_hostile(lua_State* ls);
int teleport(lua_State* ls);
int get_creature_short_description_sid(lua_State* ls);
int get_creature_description(lua_State* ls);
int get_creature_description_sids(lua_State* ls);
int transfer_item(lua_State* ls);
int creature_tile_has_item(lua_State* ls);
int pick_up_item(lua_State* ls);
int identify_item(lua_State* ls);
int identify_item_type(lua_State* ls);
int calendar_add_seconds(lua_State* ls);
int calendar_add_minutes(lua_State* ls);
int calendar_add_hours(lua_State* ls);
int calendar_add_days(lua_State* ls);
int calendar_add_years(lua_State* ls);
int add_kill_to_creature_mortuary(lua_State* ls);
int report_coords(lua_State* ls);
int get_player_world_map_coords(lua_State* ls);
int cast_spell(lua_State* ls);
int bless_equipment(lua_State* ls);
int bless_inventory(lua_State* ls);
int curse_equipment(lua_State* ls);
int curse_inventory(lua_State* ls);
int set_winner(lua_State* ls);
int get_winner(lua_State* ls);
int get_creature_colour(lua_State* ls);
int set_creature_colour(lua_State* ls);
int set_creature_evade(lua_State* ls);
int set_trap(lua_State* ls);
int has_trap(lua_State* ls);
int get_nearby_hostile_creatures(lua_State* ls);
int remove_creature_additional_property(lua_State* ls);
int set_creature_additional_property(lua_State* ls);
int get_creature_additional_property(lua_State* ls);
int get_creature_additional_property_csv(lua_State* ls);
int is_creature_in_view_map(lua_State* ls);
int redraw(lua_State* ls);
int get_race_ids(lua_State* ls);
int get_unarmed_slays(lua_State* ls);
int add_unarmed_slay(lua_State* ls);
int get_class_id(lua_State* ls);
int get_race_name(lua_State* ls);
int set_inscription(lua_State* ls);
int get_map_dimensions(lua_State* ls);
int get_coords_with_tile_type_in_range(lua_State* ls);
int get_custom_map_id(lua_State* ls);
int ranged_attack(lua_State* ls);
int get_spellbooks(lua_State* ls);
int generate_shop(lua_State* ls);
int set_shop_shopkeeper_id(lua_State* ls);
int repop_shop(lua_State* ls);
int repop_shops(lua_State* ls);
int get_num_unpaid_items(lua_State* ls);
int get_unpaid_amount(lua_State* ls);
int set_items_paid(lua_State* ls);
int bargain_discount(lua_State* ls);
int bargain_premium(lua_State* ls);
int get_item_type(lua_State* ls);
int get_shop_id(lua_State* ls);
int get_stocked_item_types(lua_State* ls);
int get_sale_price(lua_State* ls);
int set_item_unpaid(lua_State* ls);
int set_item_num_generated(lua_State* ls);
int is_in_shop(lua_State* ls);
int is_item_unpaid(lua_State* ls);
int load_map(lua_State* ls);
int has_artifact_in_inventory(lua_State* ls);
int tile_has_creature(lua_State* ls);
int tile_has_feature(lua_State* ls);
int tile_remove_feature(lua_State* ls);
int tile_is_feature_hidden(lua_State* ls);
int get_creature_original_id(lua_State* ls);
int remove_threat_from_all(lua_State* ls);
int generate_city_feature(lua_State* ls);
int get_staircase_coords(lua_State* ls);
int get_num_conducts(lua_State* ls);
int break_conduct(lua_State* ls);
int add_membership(lua_State* ls);
int has_membership(lua_State* ls);
int is_membership_excluded(lua_State* ls);
int dig_rectangles(lua_State* ls);
int get_object_ids_by_type(lua_State* ls);
int create_menu(lua_State* ls);
int set_sentinel(lua_State* ls);
int get_sid(lua_State* ls);
int set_automove_coords(lua_State* ls);
int set_decision_strategy_property(lua_State* ls);
int set_event_script(lua_State* ls);
int get_random_hostile_creature_id(lua_State* ls);
int generate_item(lua_State* ls);
int generate_creature(lua_State* ls);
int set_creature_id(lua_State* ls);
int add_all_items_to_player_tile(lua_State* ls); // Debug only! :)
int get_primordial_castings(lua_State* ls);
int creature_exists(lua_State* ls);
int set_weather(lua_State* ls);
int genocide(lua_State* ls);
int genocide_creature(lua_State* ls);
int genocide_hostile(lua_State* ls);
int generate_ancient_beast(lua_State* ls);
int generate_hireling(lua_State* ls);
int generate_adventurer(lua_State* ls);
int generate_vegetable_garden(lua_State* ls);
int generate_pen(lua_State* ls);
int set_colour(lua_State* ls);
int add_npc_level_message(lua_State* ls);
int set_leader(lua_State* ls);
int get_leader_id(lua_State* ls);
int remove_leader(lua_State* ls);
int get_name(lua_State* ls);
int set_hirelings_hired(lua_State* ls);
int get_hirelings_hired(lua_State* ls);
int set_adventurers_joined(lua_State* ls);
int get_adventurers_joined(lua_State* ls);
int get_trained_magic_skills(lua_State* ls);
int get_highest_melee_skill(lua_State* ls);
int order_follow(lua_State* ls);
int order_at_ease(lua_State* ls);
int reset_creatures_and_creature_locations(lua_State* ls);
int set_creature_speech_text_sid(lua_State* ls);
int get_creature_speech_text_sid(lua_State* ls);
int set_creature_text_details_sid(lua_State* ls);
int creature_has_humanoid_followers(lua_State* ls);
int count_creature_humanoid_followers(lua_State* ls);
int set_chat_script(lua_State* ls);
int count_creatures_with_race(lua_State* ls);
int count_creatures_with_property(lua_State* ls);
int get_time_of_day(lua_State* ls);
int generate_enclosure(lua_State* ls);
int generate_hermitage(lua_State* ls);
int update_creatures(lua_State* ls);
int get_random_village(lua_State* ls);
int get_random_preset_village(lua_State* ls);
int tokenize(lua_State* ls);
int generate_name(lua_State* ls);
int remove_chat_script(lua_State* ls);
int get_setting(lua_State* ls);
int set_current_age(lua_State* ls);
int set_max_age(lua_State* ls);
int set_hungerless(lua_State* ls);
int generate_npc_background(lua_State* ls);
int show_bestiary_text(lua_State* ls);
int get_stack_size_current_state(lua_State* ls);
int bad_fn_do_not_call(lua_State* ls);
int erase_map_linkage(lua_State* ls);
int has_trainable_skill(lua_State* ls);
int train_skills(lua_State* ls);
int set_feature_uses(lua_State* ls);
int set_creature_size(lua_State* ls);
int get_creature_size(lua_State* ls);
int get_nutrition(lua_State* ls);
int get_hidden_treasure_message(lua_State* ls);
int get_map_type(lua_State* ls);
int is_tile_available_for_creature(lua_State* ls);
int set_creature_godless(lua_State* ls);
int play_sound_effect(lua_State* ls);
int is_sound_enabled(lua_State* ls);
int is_music_enabled(lua_State* ls);
int play_event_music(lua_State* ls);
int play_map_music(lua_State* ls);
int set_map_music(lua_State* ls);
int play_music_event(lua_State* ls);
int play_music_location(lua_State* ls);
int get_music_location_for_event(lua_State* ls);
int get_music_location_for_map_type(lua_State* ls);
int does_item_exist_on_map(lua_State* ls);

// helper functions for the Lua API functions.
std::string read_sid_and_replace_values(lua_State* ls, int offset = 0);

