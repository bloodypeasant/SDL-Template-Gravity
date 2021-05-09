#include "Acceleration.hpp"
#include <math.h>
#include "Position.hpp"
#include "ThrustAble.hpp"
#include <stdio.h>
#include "Velocity.hpp"

using namespace Game;

ThrustAble::ThrustAble(Position &pos, class Velocity &vel, Acceleration &acc,
                       float magThrust, int *controllerThrust)
    : controllerThrust(controllerThrust), magThrust(magThrust),
      acc(acc), pos(pos), vel(vel)
{
  printf("    ThrustAble::ThrustAble(pos(%.1f, %.1f), vel(%.1f, %.1f), acc(%.1f, %.1f), %.1f, %d)\n",
         pos.x, pos.y, vel.x, vel.y, acc.x, acc.y, magThrust, *controllerThrust);
}

ThrustAble::~ThrustAble()
{
  printf("    ThrustAble::~ThrustAble()\n");
}

void ThrustAble::RunModelAble()
{
  float accMag = (*controllerThrust) * magThrust;
  acc.x = accMag * cos(pos.a);
  acc.y = accMag * sin(pos.a);
  vel.x += acc.x * timeChange;
  vel.y += acc.y * timeChange;
  pos.x += vel.x * timeChange;
  pos.y += vel.y * timeChange;
}
