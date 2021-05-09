#include "Position.hpp"
#include "RotateAble.hpp"
#include <stdio.h>
#include "Velocity.hpp"

using namespace Game;

RotateAble::RotateAble(Position &pos, Velocity &vel, float angularSpeed,
                       int *controllerRotation)
    : angularSpeed(angularSpeed), controllerRotation(controllerRotation),
      pos(pos), vel(vel)
{
  printf("    RotateAble::RotateAble(pos(%.1f, %.1f), vel(%.1f, %.1f), %.1f, %d)\n",
         pos.x, pos.y, vel.x, vel.y, angularSpeed, *controllerRotation);
}

RotateAble::~RotateAble()
{
  printf("    RotateAble::~RotateAble()\n");
}

void RotateAble::RunModelAble()
{
  vel.a = (*controllerRotation) * angularSpeed;
  pos.a += vel.a * timeChange;
}
