#pragma once
#include "Color.hpp"
#include "SDL.h"

/* Note: To reduce time-consuming recompilation whenever configuration settings
are modified, declare the config settings in this .hpp file -- but define
their values in a separate Config.cpp file. */

namespace Game::Config
{
  //////////////////////////////////////////////////////////////// GAME :: ACTOR
  namespace Actor
  {
    ///////////////////////////////////////// GAME :: ACTOR :: SAMPLE BACKGROUND
    namespace SampleBackground
    {
      // location of image file
      extern char const *IMAGE_FILE;
    }

    /////////////////////////////////////// GAME :: ACTOR :: SAMPLE_ACTOR_PLAYER
    namespace SampleActorPlayer
    {
      // angular acceleration in radians per millisecond per millisecond
      extern float const ACC_A;

      // magnitude of full translational acceleration
      extern float const ACC_MAG_TRANS;

      // x-component of translational acceleration in model units per ms per ms
      extern float const ACC_X;

      // y-component of translational acceleration in model units per ms per ms
      extern float const ACC_Y;

      // width in model units
      extern float const DIM_X;

      // height in model units
      extern float const DIM_Y;

      // key to move forward
      extern Uint8 const KEY_FWD;

      // key to rotate counter-clockwise
      extern Uint8 const KEY_ROTATE_CCW;

      // key to rotate clockwise
      extern Uint8 const KEY_ROTATE_CW;

      // location of image file
      extern char const *IMAGE_FILE;

      // mass of player in model mass units
      extern float const MASS;

      // orientation angle in radians
      extern float const POS_A;

      // x-position in model units
      extern float const POS_X;

      // y-pos in model units
      extern float const POS_Y;

      // maximum angular speed
      extern float const SPEED_MAX_ANGULAR;

      // maximum translational speed
      extern float const SPEED_MAX_TRANS;

      // orientation angular velocity in radians per millisecond
      extern float const VEL_A;

      // x-component of translational velocity in model units per millisecond
      extern float const VEL_X;

      // y-component of translational velocity in model units per millisecond
      extern float const VEL_Y;
    }

    ////////////////////////////////////////// GAME :: ACTOR :: SAMPLE_ACTOR_SUN
    namespace SampleActorSun
    {
      // width in model units
      extern float const DIM_X;

      // height in model units
      extern float const DIM_Y;

      // location of image file
      extern char const *IMAGE_FILE;

      // mass of sun in model mass units
      extern float const MASS;

      // orientation angle in radians
      extern float const POS_A;

      // x-position in model units
      extern float const POS_X;

      // y-pos in model units
      extern float const POS_Y;
    }
  }

  /////////////////////////////////////////////////////////// GAME :: CONTROLLER
  namespace Controller
  {
    // key to stop the game
    extern Uint8 const KEY_STOP_GAME;
  }

  //////////////////////////////////////////////////////////////// GAME :: MODEL
  namespace Model
  {
    // length of the "timeout" delay at start of each animation loop
    extern int const LOOP_TIME_MAX;

    // maximum allowable timeChange, in case of system delay (e.g. debugging)
    extern int const LOOP_TIME_MIN;

    // world's width
    extern float const WORLD_DIM_X;

    // world's height
    extern float const WORLD_DIM_Y;
  }

  ///////////////////////////////////////////////////////////////// GAME :: VIEW
  namespace View
  {
    // color to which the background is cleared each animation frame
    extern Color const BG_COLOR;

    // specifies JPG, PNG and/or TIF
    extern int const INIT_IMAGE_FLAGS;

    // specifies which SDL renderer settings are activated
    extern Uint32 const INIT_RENDERER_FLAGS;

    // specifies which renderer index to use
    extern int const INIT_RENDERER_INDEX;

    // specifies which SDL subsystems to activate
    extern Uint32 const INIT_SDL_FLAGS;

    // specifies details about window when created
    extern Uint32 const INIT_WINDOW_FLAGS;

    // title to be displayed in window
    extern char const *TITLE;

    // window's width
    extern int const WINDOW_DIM_X;

    // window's height
    extern int const WINDOW_DIM_Y;

    // window's x-position
    extern int const WINDOW_POS_X;

    // window's y-position
    extern int const WINDOW_POS_Y;
  }
}
