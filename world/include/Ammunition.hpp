#pragma once
#include "Wearable.hpp"

class Ammunition : public Wearable
{
  public:
    Ammunition();
    ~Ammunition();
    
    virtual EquipmentWornLocation get_worn_location() const;
    
    Item* clone();
};

typedef boost::shared_ptr<Ammunition> AmmunitionPtr;
