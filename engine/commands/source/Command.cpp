#include "Command.hpp"

using namespace std;

Command::Command(const string& name)
: command_name(name)
{
}

Command::~Command()
{
}

string Command::get_name() const
{
  return command_name;
}
