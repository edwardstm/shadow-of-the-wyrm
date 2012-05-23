#pragma once
#include "DecisionStrategy.hpp"
#include "ThreatRatings.hpp"

// An abstract class that represents the base class for decision strategies
// for monsters and other NPCs.
class NPCDecisionStrategy : public DecisionStrategy
{
  public:
    virtual CommandPtr get_decision(CommandFactoryPtr command_factory, KeyboardCommandMapPtr keyboard_commands, MapPtr view_map = MapPtr());
    virtual bool get_confirmation();
    
  protected:
    // Functions that are called based on the factory type
    virtual CommandPtr get_decision_for_map(CommandFactoryPtr command_factory, KeyboardCommandMapPtr keyboard_commands, MapPtr view_map) = 0;
    virtual CommandPtr get_decision_for_inventory(CommandFactoryPtr command_factory, KeyboardCommandMapPtr keyboard_commands) = 0;
    virtual CommandPtr get_decision_for_equipment(CommandFactoryPtr command_factory, KeyboardCommandMapPtr keyboard_commands) = 0;
    
    ThreatMap get_threats() const;
    
    ThreatRatings threat_ratings;
};
