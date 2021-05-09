#include <stdio.h>
#include "Acceleration.hpp"

using namespace Game;

Acceleration::Acceleration(float x, float y, float a)
    : a(a), x(x), y(y)
{
  printf("    Acceleration::Acceleration(%.1f, %.1f, %.1f)\n", x, y, a);
}
