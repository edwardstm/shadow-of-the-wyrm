#include "DirectionUtils.hpp"

using namespace std;

DirectionUtils::DirectionUtils()
{
}

bool DirectionUtils::is_cardinal(const Direction d)
{
  switch(d)
  {
    case Direction::DIRECTION_NORTH:
    case Direction::DIRECTION_SOUTH:
    case Direction::DIRECTION_EAST:
    case Direction::DIRECTION_WEST:
      return true;
    default:
      return false;
  }
}

bool DirectionUtils::is_ordinal(const Direction d)
{
  switch(d)
  {
    case Direction::DIRECTION_NORTH_WEST:
    case Direction::DIRECTION_NORTH_EAST:
    case Direction::DIRECTION_SOUTH_WEST:
    case Direction::DIRECTION_SOUTH_EAST:
      return true;
    default:
      return false;
  }
}

CardinalDirection DirectionUtils::get_opposite_direction(const CardinalDirection d)
{
  CardinalDirection o = d;

  switch (d)
  {
    case CardinalDirection::CARDINAL_DIRECTION_NORTH:
      o = CardinalDirection::CARDINAL_DIRECTION_SOUTH;
      break;
    case CardinalDirection::CARDINAL_DIRECTION_SOUTH:
      o = CardinalDirection::CARDINAL_DIRECTION_NORTH;
      break;
    case CardinalDirection::CARDINAL_DIRECTION_EAST:
      o = CardinalDirection::CARDINAL_DIRECTION_WEST;
      break;
    case CardinalDirection::CARDINAL_DIRECTION_WEST:
      o = CardinalDirection::CARDINAL_DIRECTION_EAST;
    default:
      break;
  }

  return o;
}

Direction DirectionUtils::get_opposite_direction(const Direction d)
{
  Direction o = d;

  switch (d)
  {
    case Direction::DIRECTION_UP:
      o = Direction::DIRECTION_DOWN;
      break;
    case Direction::DIRECTION_DOWN:
      o = Direction::DIRECTION_UP;
      break;
    case Direction::DIRECTION_NORTH_WEST:
      o = Direction::DIRECTION_SOUTH_EAST;
      break;
    case Direction::DIRECTION_NORTH:
      o = Direction::DIRECTION_SOUTH;
      break;
    case Direction::DIRECTION_NORTH_EAST:
      o = Direction::DIRECTION_SOUTH_WEST;
      break;
    case Direction::DIRECTION_WEST:
      o = Direction::DIRECTION_EAST;
      break;
    case Direction::DIRECTION_EAST:
      o = Direction::DIRECTION_WEST;
      break;
    case Direction::DIRECTION_SOUTH_WEST:
      o = Direction::DIRECTION_NORTH_EAST;
      break;
    case Direction::DIRECTION_SOUTH:
      o = Direction::DIRECTION_NORTH;
      break;
    case Direction::DIRECTION_SOUTH_EAST:
      o = Direction::DIRECTION_NORTH_WEST;
      break;
    case Direction::DIRECTION_NULL:
    default:
      break;
  }

  return o;
}

bool DirectionUtils::direction_matches_category(const Direction d, const DirectionCategory dc)
{
  bool matches = false;

  switch (dc)
  {
    case DirectionCategory::DIRECTION_CATEGORY_CARDINAL:
      matches = DirectionUtils::is_cardinal(d);
      break;
    case DirectionCategory::DIRECTION_CATEGORY_CARDINALORDINAL:
      matches = (DirectionUtils::is_ordinal(d) || DirectionUtils::is_cardinal(d));
      break;
    case DirectionCategory::DIRECTION_CATEGORY_NONE:
      break;
  }

  return matches;
}

set<Direction> DirectionUtils::get_all_directions_for_category(DirectionCategory dc)
{
  set<Direction> directions;

  switch (dc)
  {
    case DirectionCategory::DIRECTION_CATEGORY_CARDINAL:
      directions = {Direction::DIRECTION_NORTH, Direction::DIRECTION_SOUTH, Direction::DIRECTION_EAST, Direction::DIRECTION_WEST};
      break;
    case DirectionCategory::DIRECTION_CATEGORY_CARDINALORDINAL:
      directions = {Direction::DIRECTION_NORTH, Direction::DIRECTION_SOUTH, Direction::DIRECTION_EAST, Direction::DIRECTION_WEST, Direction::DIRECTION_NORTH_EAST, Direction::DIRECTION_NORTH_WEST, Direction::DIRECTION_SOUTH_EAST, Direction::DIRECTION_SOUTH_WEST};
      break;
    case DirectionCategory::DIRECTION_CATEGORY_NONE:
      directions.insert(Direction::DIRECTION_NULL);
      break;
  }

  return directions;
}

#ifdef UNIT_TESTS
#include "unit_tests/DirectionUtils_test.cpp"
#endif
