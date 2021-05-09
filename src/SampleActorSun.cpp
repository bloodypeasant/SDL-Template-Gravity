#include "Config.hpp"
#include "SampleActorSun.hpp"
#include <stdio.h>

using namespace Game;
using namespace Config::Actor::SampleActorSun;

SampleActorSun::SampleActorSun()
    : Actor(POS_X, POS_Y, POS_A, DIM_X, DIM_Y),
      GraviSetAble(this->Actor::pos, MASS),
      ViewAble(this->Actor::pos, this->Actor::dim)
{
  printf(
      "    SampleActorSun::SampleActorSun()\n");
  SetTexture(IMAGE_FILE);
}

SampleActorSun::~SampleActorSun()
{
  printf("    SampleActorSun::~SampleActorSun()\n");
}
