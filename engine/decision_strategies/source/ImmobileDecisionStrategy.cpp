#include <string>
#include <sstream>
#include <boost/make_shared.hpp>
#include "Commands.hpp"
#include "ImmobileDecisionStrategy.hpp"

using namespace std;
using boost::make_shared;

ImmobileDecisionStrategy::ImmobileDecisionStrategy(ControllerPtr new_controller)
: controller(new_controller)
{
}

CommandPtr ImmobileDecisionStrategy::get_decision_for_map(CommandFactoryPtr command_factory, KeyboardCommandMapPtr keyboard_commands, MapPtr view_map)
{
  CommandPtr command;

  // JCD FIXME: Fill actual logic later.  Right now, just search.  That way, turns will continue to advance.
  // Later, add logic to consider LOS on the current map, and so on.
  // 
  // Create a class of string constants to hold the actual command keyboard value constants later.
  // Once this is done, remove the direct make_shared calls, remove the using statement, and remove the include.
  command = make_shared<SearchCommand>();

  return command;
}

CommandPtr ImmobileDecisionStrategy::get_decision_for_inventory(CommandFactoryPtr command_factory, KeyboardCommandMapPtr keyboard_commands)
{
  CommandPtr null;
  return null;
}

CommandPtr ImmobileDecisionStrategy::get_decision_for_equipment(CommandFactoryPtr command_factory, KeyboardCommandMapPtr keyboard_commands)
{
  CommandPtr null;
  return null;
}
