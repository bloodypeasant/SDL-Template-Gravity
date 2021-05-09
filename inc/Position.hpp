#pragma once

namespace Game
{
  // Holds Cartesian and orientational attributes
  struct Position
  {
    // Constructs a Position
    Position(float x, float y, float a);

    // orientation angle in radians
    float a;

    // x-position in model units
    float x;

    // y-position in model units
    float y;
  };
}
