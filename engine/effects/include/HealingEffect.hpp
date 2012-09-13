#pragma once
#include "Effect.hpp"

class HealingEffect : public Effect
{
  public:
    virtual std::string get_effect_identification_message(boost::shared_ptr<Creature> creature) const;
    virtual Effect* clone();

  protected:
    virtual bool effect_blessed(boost::shared_ptr<Creature> creature, ActionManager * const am);
    virtual bool effect_uncursed(boost::shared_ptr<Creature> creature, ActionManager * const am);
    virtual bool effect_cursed(boost::shared_ptr<Creature> creature, ActionManager * const am);
    
    virtual bool heal(boost::shared_ptr<Creature> creature, const float healing_multiplier) const;
    
    virtual int get_random_healing_amount() const;

    static const float BLESSED_MULTIPLIER;
    static const float UNCURSED_MULTIPLIER;
    static const float CURSED_MULTIPLIER;
    static const int BASE_MIN_HP;
    static const int BASE_MAX_HP;
};
