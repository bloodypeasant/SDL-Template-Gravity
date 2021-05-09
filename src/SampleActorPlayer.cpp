#include "Config.hpp"
#include "SampleActorPlayer.hpp"
#include <stdio.h>

using namespace Game;
using namespace Config::Actor::SampleActorPlayer;

SampleActorPlayer::SampleActorPlayer(GraviSetAble &graviSetAble)
    : acc(ACC_X, ACC_Y, ACC_A),
      vel(VEL_X, VEL_Y, VEL_A),
      Actor(POS_X, POS_Y, POS_A, DIM_X, DIM_Y),
      GraviGetAble(this->Actor::pos, vel, acc, graviSetAble, MASS),
      RotateAble(this->Actor::pos, vel, SPEED_MAX_ANGULAR, &controllerRotation),
      ThrustAble(this->Actor::pos, vel, acc, ACC_MAG_TRANS, &controllerThrust),
      ViewAble(this->Actor::pos, this->Actor::dim)
{
  printf(
      "    SampleActorPlayer::SampleActorPlayer()\n");
  SetTexture(IMAGE_FILE);
}

SampleActorPlayer::~SampleActorPlayer()
{
  printf("    SampleActorPlayer::~SampleActorPlayer()\n");
}

void SampleActorPlayer::RunKeyAble()
{
  controllerRotation = 0;
  if (KeyAble::keyState[KEY_ROTATE_CCW])
  {
    // rotate counter-clockwise
    --controllerRotation;
  }
  if (KeyAble::keyState[KEY_ROTATE_CW])
  {
    // rotate clockwise
    ++controllerRotation;
  }

  controllerThrust = 0;
  if (KeyAble::keyState[KEY_FWD])
  {
    // thrust forward
    ++controllerThrust;
  }
}
