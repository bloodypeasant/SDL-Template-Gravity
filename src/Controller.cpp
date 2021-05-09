#include "Config.hpp"
#include "Controller.hpp"
#include "Game.hpp"
#include "KeyAble.hpp"
#include "MouseAble.hpp"
#include "SDL.h"

using namespace Game;
using namespace Config::Controller;

void Controller::Run()
{
  // Loop through events that have accumulated since last animation frame.
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      // Game-stopping events are handled by the game.
      StopGame();
      break;
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
    case SDL_MOUSEMOTION:
    case SDL_MOUSEWHEEL:
      // Mouse events are passed to mouseAbles (maybe multiple times per loop)
      MouseAble::RunAll(&event);
      break;
    default:
      // Note: There are numerous other events that can be handled, if needed.
      break;
    }
  }

  // Get the present state of the keyboard.
  Uint8 const *keyState = SDL_GetKeyboardState(NULL);
  if (keyState[KEY_STOP_GAME]) // STOP_GAME key is specified in the Config file.
  {
    // A game-stopping keyState is handled by the game.
    StopGame();
  }
  else
  {
    // The keyState is passed to keyAbles (just one time per loop)
    KeyAble::RunAll(keyState);
  }
}
