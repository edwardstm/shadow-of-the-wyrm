#include "Spellbook.hpp"
#include "Serialize.hpp"

using namespace std;

Spellbook::Spellbook()
: difficulty(0)
{
  type = ITEM_TYPE_SPELLBOOK;
  symbol = '\"';
}

Spellbook::~Spellbook()
{
}

bool Spellbook::operator==(const Spellbook& rhs) const
{
  bool result = Readable::operator==(rhs);

  result = result && (spell_id == rhs.spell_id);
  result = result && (difficulty == rhs.difficulty);

  return result;
}

bool Spellbook::destroy_on_read() const
{
  return false;
}

void Spellbook::set_spell_id(const string& new_spell_id)
{
  spell_id = new_spell_id;
}

string Spellbook::get_spell_id() const
{
  return spell_id;
}

void Spellbook::set_difficulty(const int new_difficulty)
{
  difficulty = new_difficulty;
}

int Spellbook::get_difficulty() const
{
  return difficulty;
}

Item* Spellbook::clone()
{
  return new Spellbook(*this);
}

bool Spellbook::serialize(ostream& stream)
{
  Readable::serialize(stream);

  Serialize::write_string(stream, spell_id);
  Serialize::write_int(stream, difficulty);

  return true;
}

bool Spellbook::deserialize(istream& stream)
{
  Readable::deserialize(stream);

  Serialize::read_string(stream, spell_id);
  Serialize::read_int(stream, difficulty);

  return true;
}

ClassIdentifier Spellbook::internal_class_identifier() const
{
  return CLASS_ID_SPELLBOOK;
}

#ifdef UNIT_TESTS
#include "unit_tests/Spellbook_test.cpp"
#endif

