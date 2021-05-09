#pragma once
#include <vector>

namespace Game
{
  // Capable of sending signals to GraviGetAble objects
  class GraviSetAble
  {
  public:
    // Constructs a GraviSetAble object
    GraviSetAble(class Position &pos, float mass);

    // Destructs a GraviSetAble object
    ~GraviSetAble();

    // Gets field
    void GetField(class Position &posObject, class Acceleration &field);

  private:
    // mass of this gravity source
    float mass;

    // reference to this actor's position
    class Position &pos;
  };
}
