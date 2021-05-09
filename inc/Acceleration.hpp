#pragma once

namespace Game
{
  // Holds translational and angular acceleration attributes
  struct Acceleration
  {
    // Constructs a Velocity
    Acceleration(float x, float y, float a);

    // angular acceleration in radians per ms per ms
    float a;

    // x-component of translational acceleration in model units per ms per ms
    float x;

    // y-component of translational acceleration in model units per ms per ms
    float y;
  };
}
