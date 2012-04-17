#include "Ring.hpp"

Ring::Ring()
{
  type = ITEM_TYPE_RING;
  symbol = '=';
}

Ring::~Ring()
{
}

Item* Ring::clone()
{
  return new Ring(*this);
}
