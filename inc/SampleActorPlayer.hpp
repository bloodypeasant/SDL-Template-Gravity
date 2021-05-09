#pragma once
#include "Acceleration.hpp"
#include "Actor.hpp"
#include "GraviGetAble.hpp"
#include "GraviSetAble.hpp"
#include "KeyAble.hpp"
#include "RotateAble.hpp"
#include "ThrustAble.hpp"
#include "Velocity.hpp"
#include "ViewAble.hpp"

namespace Game
{
  // Sample player responsive to controls
  class SampleActorPlayer
      : public Actor,
        public GraviGetAble,
        public KeyAble,
        public RotateAble,
        public ThrustAble,
        public ViewAble
  {
  public:
    // Constructs a new SampleActorPlayer
    SampleActorPlayer(GraviSetAble &graviSetAble);

    // Destructs a SampleActorPlayer
    ~SampleActorPlayer();

    // Overrides KeyAble's Run method
    void RunKeyAble() override;

  private:
    // player's acceleration (x, y, a)
    Acceleration acc;

    // player's velocity (x, y, a)
    Velocity vel;

    // rotation signaled by controller
    int controllerRotation = 0;

    // forward thrust signaled by controller
    int controllerThrust = 0;
  };
}
