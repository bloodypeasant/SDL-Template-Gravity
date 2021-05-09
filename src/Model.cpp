#include "Config.hpp"
#include "Model.hpp"
#include "ModelAble.hpp"
#include <stdio.h>

using namespace Game;
using namespace Config::Model;

SampleBackground *Model::background = nullptr;
SampleActorPlayer *Model::player = nullptr;
SampleActorSun *Model::sun = nullptr;
Uint32 Model::timePrior = 0;

void Model::Finalize()
{
  printf("\n  Model::Finalize()\n");

  // Delete the background
  printf("\n  - DELETE SAMPLE_BACKGROUND\n");
  delete background;
  background = nullptr;

  // Delete the player
  printf("\n  - DELETE SAMPLE_ACTOR_PLAYER\n");
  delete player;
  player = nullptr;

  // Delete the sun
  printf("\n  - DELETE SAMPLE_ACTOR_SUN\n");
  delete sun;
  sun = nullptr;
}

void Model::Initialize()
{
  printf("\n  Model::Intialize()\n");

  // Create the game's background
  printf("\n  + NEW SAMPLE_BACKGROUND\n");
  background = new SampleBackground(WORLD_DIM_X, WORLD_DIM_Y);

  // Create the sun
  printf("\n  + NEW SAMPLE_ACTOR_SUN\n");
  sun = new SampleActorSun();

  // Create the player
  printf("\n  + NEW SAMPLE_ACTOR_PLAYER\n");
  player = new SampleActorPlayer(*sun);
}

void Model::Run()
{
  int timeChange = SDL_GetTicks() - timePrior;
  if (timeChange > LOOP_TIME_MAX)
  {
    timeChange = LOOP_TIME_MAX;
  }
  ModelAble::RunAll(timeChange);
  Uint32 timeToEndRun = timePrior + LOOP_TIME_MIN;
  while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeToEndRun))
    ;
  timePrior = SDL_GetTicks();
}
