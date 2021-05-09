#pragma once
#include "Actor.hpp"
#include "GraviSetAble.hpp"
#include "ViewAble.hpp"

namespace Game
{
  // Sample actor that doesn't change or move in any way
  class SampleActorSun : public Actor, public GraviSetAble, public ViewAble
  {
  public:
    // Constructs a new SampleActorSun
    SampleActorSun();

    // Destructs a SampleActorSun
    ~SampleActorSun();
  };
}
