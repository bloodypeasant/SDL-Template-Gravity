#pragma once
#include "Actor.hpp"
#include "ViewAble.hpp"

namespace Game
{
  // Sample background actor
  class SampleBackground : public Actor, public ViewAble
  {
  public:
    // Constructs a new SampleBackground
    SampleBackground(float dimX, float dimY);

    // Destructs a SampleBackground
    ~SampleBackground();
  };
}
