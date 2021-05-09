#pragma once
#include "Dimension.hpp"
#include "Position.hpp"
#include <vector>

namespace Game
{
  // Base class of all actors in the game
  class Actor
  {
  public:
    // Constructs a new Actor & adds it to the static list of actors
    Actor(float posX, float posY, float posA, float dimX, float dimY);

    // Destructs an Actor & removes it from the static list of actors
    ~Actor();

    float GetDimX() { return dim.x; }

    float GetDimY() { return dim.y; }

    float GetPosX() { return pos.x; }

    float GetPosY() { return pos.y; }

  protected:
    // contains pointers to all actors in the game
    static std::vector<Actor *> actors;

    // actor's dimensions (x, y)
    Dimension dim;

    // actor's position (x, y, a)
    Position pos;
  };
}
