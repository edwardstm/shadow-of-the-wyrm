#pragma once
#include <map>
#include <string>

#include "ResistanceTypes.hpp"

inline ResistanceType operator--(ResistanceType &rt, int)
{
  return rt = ResistanceType(rt-1);
}

inline ResistanceType operator++(ResistanceType &rt, int)
{
  return rt = ResistanceType(rt+1);
}

#define DEFAULT_RESISTANCE_VALUE 0.0;

// JCD FIXME: Make Resistance a class similar to Skill: contains its type, value, and a name sid.
class Resistance
{
  public:
    Resistance();
    Resistance(const ResistanceType type, const std::string& name_sid, const double value);

    void set_type(const ResistanceType new_type);
    ResistanceType get_type() const;

    void set_name_sid(const std::string& new_name_sid);
    std::string get_name_sid() const;

    void set_value(const double new_value);
    double get_value() const;

    std::string str() const;

  protected:
    ResistanceType type;
    std::string name_sid;
    double value;
};

// Individual resistance types
class SlashResistance : public Resistance
{
  public:
    SlashResistance();
};

class PierceResistance : public Resistance
{
  public:
    PierceResistance();
};

class PoundResistance : public Resistance
{
  public:
    PoundResistance();
};

class HeatResistance : public Resistance
{
  public:
    HeatResistance();
};

class ColdResistance : public Resistance
{
  public:
    ColdResistance();
};

class AcidResistance : public Resistance
{
  public:
    AcidResistance();
};

class PoisonResistance : public Resistance
{
  public:
    PoisonResistance();
};

class HolyResistance : public Resistance
{
  public:
    HolyResistance();
};

class ShadowResistance : public Resistance
{
  public:
    ShadowResistance();
};

class ArcaneResistance : public Resistance
{
  public:
    ArcaneResistance();
};

class MentalResistance : public Resistance
{
  public:
    MentalResistance();
};

class SonicResistance : public Resistance
{
  public:
    SonicResistance();
};

class RadiantResistance : public Resistance
{
  public:
    RadiantResistance();
};

class LightningResistance : public Resistance
{
  public:
    LightningResistance();
};

typedef std::map<ResistanceType, Resistance> ResistancesMap;

// Resistance container class
class Resistances
{
  public:
    Resistances();

    void set_resistance_value(const ResistanceType type, double value);
    double get_resistance_value(const ResistanceType type) const;

    std::string str() const;

  protected:
    void default_resistances();

    ResistancesMap resistances;
};
