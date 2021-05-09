#include "Config.hpp"
#include "SampleBackground.hpp"
#include <stdio.h>

using namespace Game;
using namespace Config::Actor::SampleBackground;

SampleBackground::SampleBackground(float dimX, float dimY)
    : Actor(0, 0, 0, dimX, dimY), ViewAble(this->Actor::pos, this->Actor::dim)
{
  printf(
      "    SampleBackground::SampleBackground(%.1f, %.1f, %.1f, %.1f, %.1f)\n",
      0.0f, 0.0f, 0.0f, dimX, dimY);
  SetTexture(IMAGE_FILE);
}

SampleBackground::~SampleBackground()
{
  printf("    SampleBackground::~SampleBackground()\n");
}
