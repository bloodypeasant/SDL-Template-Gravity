#pragma once
#include "Acceleration.hpp"
#include "ModelAble.hpp"
#include <vector>

namespace Game
{
  // Capable of receiving signals from GraviSetAble objects
  class GraviGetAble : public ModelAble
  {
  public:
    // Constructs a GraviGetAble object
    GraviGetAble(class Position &pos, class Velocity &vel,
                 class Acceleration &acc, class GraviSetAble &graviSetAble,
                 float mass);

    // Destructs a GraviGetAble object
    ~GraviGetAble();

    // Runs the GraviGetAble object
    void RunModelAble() override;

  private:
    // reference to this actor's acceleration
    Acceleration &acc;

    // for receiving updates regarding gravitational field strength
    Acceleration field;

    // source of gravity
    class GraviSetAble &graviSetAble;

    // reference to this actor's position
    class Position &pos;

    // reference to this actor's velocity
    class Velocity &vel;

    // this actor's mass
    float mass;
  };
}
