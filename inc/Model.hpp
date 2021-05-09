#pragma once
#include "SampleActorPlayer.hpp"
#include "SampleActorSun.hpp"
#include "SampleBackground.hpp"
#include "SDL.h"

// namespace enclosing the game's data state
namespace Game::Model
{
  // Called at end of game to perform any needed shut-down
  void Finalize();

  // Called at start of game to intialize actors, etc.
  void Initialize();

  // Called once every game loop to run the clock and run any ModelAble actors
  void Run();

  // the game's background actor
  extern Game::SampleBackground *background;

  // the game's player actor
  extern Game::SampleActorPlayer *player;

  // the game's sun actor (gravitational source)
  extern Game::SampleActorSun *sun;

  // for timer purposes
  extern Uint32 timePrior;
}
