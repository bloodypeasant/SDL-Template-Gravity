#include "Acceleration.hpp"
#include <math.h>
#include "GraviGetAble.hpp"
#include "GraviSetAble.hpp"
#include "Position.hpp"
#include <stdio.h>
#include "Velocity.hpp"

using namespace Game;

GraviGetAble::GraviGetAble(Position &pos, class Velocity &vel,
                           Acceleration &acc, GraviSetAble &graviSetAble,
                           float mass)
    : acc(acc), field(0, 0, 0), graviSetAble(graviSetAble), pos(pos), vel(vel),
      mass(mass)
{
  printf("    GraviGetAble::GraviGetAble(pos(%.1f, %.1f), vel(%.1f, %.1f), acc(%.1f, %.1f), _, %.1f)\n",
         pos.x, pos.y, vel.x, vel.y, acc.x, acc.y, mass);
}

GraviGetAble::~GraviGetAble()
{
  printf("    GraviGetAble::~GraviGetAble()\n");
}

void GraviGetAble::RunModelAble()
{
  graviSetAble.GetField(pos, field);
  vel.x += field.x * timeChange;
  vel.y += field.y * timeChange;
  pos.x += vel.x * timeChange;
  pos.y += vel.y * timeChange;
}
