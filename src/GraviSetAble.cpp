#include "Acceleration.hpp"
#include <math.h>
#include "GraviSetAble.hpp"
#include "Position.hpp"
#include <stdio.h>

using namespace Game;

const float G = 0.002f;

GraviSetAble::GraviSetAble(class Position &pos, float mass)
    : mass(mass), pos(pos)
{
  printf("    GraviSetAble::GraviSetAble(pos(%.1f, %.1f), %.1f)\n",
         pos.x, pos.y, mass);
}

GraviSetAble::~GraviSetAble()
{
  printf("    GraviSetAble::~GraviSetAble()\n");
}

void GraviSetAble::GetField(Position &posObject, Acceleration &field)
{
  float dx = posObject.x - pos.x;
  float dy = posObject.y - pos.y;
  float rSqrd = dx * dx + dy * dy;
  float fieldMag = G * mass / rSqrd;
  float angle = atan2(dy, dx);
  field.x = -fieldMag * cos(angle);
  field.y = -fieldMag * sin(angle);
}
