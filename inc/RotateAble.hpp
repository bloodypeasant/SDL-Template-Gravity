#pragma once
#include "ModelAble.hpp"
#include <vector>

namespace Game
{
  // Capable of being rotated
  class RotateAble : public ModelAble
  {
  public:
    // Constructs a RotateAble object
    RotateAble(class Position &pos, class Velocity &vel, float angularSpeed,
               int *controllerRotation);

    // Destructs a RotateAble object
    virtual ~RotateAble();

    // Runs the RotateAble object
    virtual void RunModelAble() override;

  private:
    // this actor's maximum angular speed
    float angularSpeed;

    // pointer to state of actor's rotational controls
    int *controllerRotation;

    // reference to this actor's position
    class Position &pos;

    // reference to this actor's velocity
    class Velocity &vel;
  };
}
