#include "Dimension.hpp"
#include <stdio.h>

using namespace Game;

Dimension::Dimension(float x, float y)
    : x(x), y(y)
{
  printf("    Dimension::Dimension(%.1f, %.1f)\n", x, y);
}
