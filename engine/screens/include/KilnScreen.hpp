#pragma once
#include <map>
#include <string>
#include "Screen.hpp"
#include "Display.hpp"

class KilnScreen : public Screen
{
  public:
    KilnScreen(DisplayPtr new_display, const bool fire_bombs, const bool shadow_bombs);

  protected:
    void initialize() override;

    bool allow_fire_bombs;
    bool allow_shadow_bombs;
};
