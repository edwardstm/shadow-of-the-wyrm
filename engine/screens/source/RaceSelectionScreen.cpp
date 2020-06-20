#include "RaceSelectionScreen.hpp"
#include "Game.hpp"
#include "OptionsComponent.hpp"
#include "PromptTextKeys.hpp"
#include "TextComponent.hpp"
#include "TextKeys.hpp"

using namespace std;

RaceSelectionScreen::RaceSelectionScreen(DisplayPtr new_display, const string& synop)
: Screen(new_display), creature_synopsis(synop)
{
  initialize();
}

// Initialize the race selection screen.  Races must have been read in, and set into the Game
// instance at this point.
//
// The Screen will return an int based on the user's selection.  This will map to a race_id, which will then map to a
// Race*.
void RaceSelectionScreen::initialize()
{
  Game& game_instance = Game::instance();
  const RaceMap& races = game_instance.get_races_ref();
  ostringstream synop;

  vector<ScreenComponentPtr> race_screen;

  if (!creature_synopsis.empty())
  {
    synop << "[" << creature_synopsis << "]";
  }

  race_screen.push_back(make_shared<TextComponent>(synop.str()));

  TextComponentPtr race_selection_text = std::make_shared<TextComponent>(StringTable::get(TextKeys::SELECT_RACE));

  // Each option represents a player-selectable race.
  OptionsComponentPtr options = std::make_shared<OptionsComponent>();

  int current_id = 0;
  for (auto& races_pair : races)
  {
    string race_id = races_pair.first;
    Race* current_race = races_pair.second.get();

    if (current_race && current_race->get_user_playable() && options)
    {
      Option current_option;
      current_option.set_id(current_id);
      current_option.set_description(StringTable::get(current_race->get_race_name_sid()));

      options->add_option(current_option);
      options->add_option_description(StringTable::get(current_race->get_race_short_description_sid()));
      current_id++;
    }
  }

  // Random selection (use '*')
  Option random_option;
  random_option.set_id(random_option.get_id_for_random());
  random_option.set_description(StringTable::get(TextKeys::RANDOM_SELECTION));

  options->add_option(random_option);
  options->add_option_description("");

  race_screen.push_back(race_selection_text);
  race_screen.push_back(options);

  add_page(race_screen);

  // Set the prompt
  PromptPtr any_key_prompt = std::make_unique<Prompt>(PromptLocation::PROMPT_LOCATION_LOWER_RIGHT);
  any_key_prompt->set_text_sid(PromptTextKeys::PROMPT_SELECT_AN_OPTION);
  user_prompt = std::move(any_key_prompt);
}
