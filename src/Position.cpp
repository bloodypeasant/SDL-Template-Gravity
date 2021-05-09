#include "Position.hpp"
#include <stdio.h>

using namespace Game;

Position::Position(float x, float y, float a)
    : a(a), x(x), y(y)
{
  printf("    Position::Position(%.1f, %.1f, %.1f)\n", x, y, a);
}
