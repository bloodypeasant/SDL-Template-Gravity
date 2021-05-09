#pragma once

namespace Game
{
  // Holds translational and orientation-angular velocity attributes
  struct Velocity
  {
    // Constructs a Velocity
    Velocity(float x, float y, float a);

    // orientation angular velocity in radians per millisecond
    float a;

    // x-component of translational velocity in model units per millisecond
    float x;

    // y-component of translational velocity in model units per millisecond
    float y;
  };
}
