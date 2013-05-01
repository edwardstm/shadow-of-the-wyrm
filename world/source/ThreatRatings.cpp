#include <boost/foreach.hpp>
#include "Serialize.hpp"
#include "ThreatRatings.hpp"

using namespace std;

ThreatRatings::ThreatRatings()
{
}

ThreatRatings::~ThreatRatings()
{
}

bool ThreatRatings::operator==(const ThreatRatings& threat) const
{
  bool result = true;

  result = result && (threat_ratings == threat.threat_ratings);

  return result;
}

// Check to see if a particular creature ID exists at any threat level
bool ThreatRatings::has_threat(const string& creature_id) const
{
  for (ThreatMap::const_iterator c_it = threat_ratings.begin(); c_it != threat_ratings.end(); c_it++)
  {
    set<string> threats_at_current_level = c_it->second;
    
    if (threats_at_current_level.find(creature_id) != threats_at_current_level.end())
    {
      return true;
    }
  }
  
  return false;
}

// Add a threat at a given threat rating.
void ThreatRatings::add_threat(const string& creature_id, const int threat_rating)
{
  ThreatMap::iterator t_it = threat_ratings.find(threat_rating);
  
  if (t_it != threat_ratings.end())
  {
    set<string>& threats = t_it->second;
    threats.insert(creature_id);
  }
  else
  {
    set<string> threats;
    threats.insert(creature_id);
    threat_ratings.insert(make_pair(threat_rating, threats));
  }
}

// Update a creature's threat rating by deleting the old, and adding the new.
void ThreatRatings::update_threat(const string& creature_id, const int old_threat_rating, const int new_threat_rating)
{
  remove_threat(creature_id, old_threat_rating);
  add_threat(creature_id, new_threat_rating);
}

// Remove a creature from the list of threat ratings.
void ThreatRatings::remove_threat(const string& creature_id, const int threat_rating)
{
  ThreatMap::iterator t_it = threat_ratings.find(threat_rating);
  
  if (t_it != threat_ratings.end())
  {
    set<string>& threats = t_it->second;
    threats.erase(creature_id);
  }
}

// Get all the threats.
ThreatMap ThreatRatings::get_all_threats() const
{
  return threat_ratings;
}

// Write out the threat map.
bool ThreatRatings::serialize(ostream& stream)
{
  Serialize::write_size_t(stream, threat_ratings.size());

  BOOST_FOREACH(ThreatMap::value_type& t_val, threat_ratings)
  {
    Serialize::write_int(stream, t_val.first);
    
    set<string> threats = t_val.second;

    Serialize::write_size_t(stream, threats.size());

    BOOST_FOREACH(const string& threat, threats)
    {
      Serialize::write_string(stream, threat);
    }
  }

  return true;
}

bool ThreatRatings::deserialize(istream& stream)
{
  size_t threat_map_size;
  Serialize::read_size_t(stream, threat_map_size);

  threat_ratings.clear();

  for (unsigned int i = 0; i < threat_map_size; i++)
  {
    int threat_rating = 0;
    Serialize::read_int(stream, threat_rating);

    size_t threat_rating_count = 0;
    Serialize::read_size_t(stream, threat_rating_count);

    set<string> threats;

    for (unsigned int j = 0; j < threat_rating_count; j++)
    {
      string threat_creature_id;
      Serialize::read_string(stream, threat_creature_id);

      threats.insert(threat_creature_id);
    }

    threat_ratings.insert(make_pair(threat_rating, threats));
  }

  return true;
}

ClassIdentifier ThreatRatings::internal_class_identifier() const
{
  return CLASS_ID_THREAT_RATINGS;
}

#ifdef UNIT_TESTS
#include "unit_tests/ThreatRatings_test.cpp"
#endif


