#include <algorithm>
#include "Actor.hpp"
#include <stdio.h>

using namespace Game;

std::vector<Actor *> Actor::actors;

Actor::Actor(float posX, float posY, float posA, float dimX, float dimY)
    : dim(dimX, dimY), pos(posX, posY, posA)
{
  printf("    Actor::Actor(%.1f, %.1f, %.1f, %.1f, %.1f)\n",
         posX, posY, posA, dimX, dimY);
  actors.emplace_back(this);
}

Actor::~Actor()
{
  printf("    Actor::~Actor()\n");
  auto it = std::find(actors.begin(), actors.end(), this);
  if (it != actors.end())
  {
    std::iter_swap(it, actors.end() - 1);
    /* Note that deletion of the actor will trigger this destructor, so such
    deletion is intended to be called externally -- not here. */
    actors.pop_back();
  }
}
