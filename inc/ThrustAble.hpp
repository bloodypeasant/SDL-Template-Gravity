#pragma once
#include "ModelAble.hpp"
#include <vector>

namespace Game
{
  // Capable of performing thrust (forward self-acceleration)
  class ThrustAble : public ModelAble
  {
  public:
    // Constructs a ThrustAble object
    ThrustAble(class Position &pos, class Velocity &vel,
               class Acceleration &acc, float magThrust, int *controllerThrust);

    // Destructs a ThrustAble object
    virtual ~ThrustAble();

    // Runs the ThrustAble object
    virtual void RunModelAble() override;

  private:
    // pointer to state of this actor's thrust controls
    int *controllerThrust;

    // actor's maximum thrust magnitude
    float magThrust;

    // reference to this actor's acceleration
    class Acceleration &acc;

    // reference to this actor's position
    class Position &pos;

    // reference to this actor's velocity
    class Velocity &vel;
  };
}
