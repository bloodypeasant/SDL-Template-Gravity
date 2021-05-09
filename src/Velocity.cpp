#include <stdio.h>
#include "Velocity.hpp"

using namespace Game;

Velocity::Velocity(float x, float y, float a)
    : a(a), x(x), y(y)
{
  printf("    Velocity::Velocity(%.1f, %.1f, %.1f)\n", x, y, a);
}
