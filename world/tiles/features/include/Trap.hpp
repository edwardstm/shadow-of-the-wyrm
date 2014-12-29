#pragma once
#include <memory>
#include "Damage.hpp"
#include "Feature.hpp"

class Trap : public Feature
{
  public:
    Trap();
    virtual ~Trap() {};
    bool operator==(const Trap& trap) const;
    
    Trap* clone() override;
    Trap* clone_and_randomize_uses();

    virtual bool get_is_hidden() const override;

    virtual bool apply_on_movement(CreaturePtr creature) const override;

    virtual uchar get_symbol() const override;

    void set_triggered(const bool new_triggered);
    bool get_triggered() const;

    void set_id(const std::string& new_id);
    std::string get_id() const;

    void set_description_sid(const std::string& new_description_sid);

    void set_trigger_message_sid(const std::string& new_trigger_message_sid);
    std::string get_trigger_message_sid() const;

    void set_damage(const Damage& new_damage);
    Damage get_damage() const;

    bool serialize(std::ostream& stream) const override;
    bool deserialize(std::istream& stream) override;

  protected:
    virtual std::string get_description_sid() const override;

    bool triggered;
    std::string id;
    std::string description_sid;
    std::string trigger_message_sid;
    Damage damage;

  private:
    virtual ClassIdentifier internal_class_identifier() const override;
};

typedef std::shared_ptr<Trap> TrapPtr;
