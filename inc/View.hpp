#pragma once
#include "SDL.h"

// namespace enclosing the game's graphical display elements
namespace Game::View
{
  // Called at end of game to shut down resources
  void Finalize();

  // Called at start of game to initialize resources
  bool Initialize();

  // Called once every game loop to perform graphical rendering
  void Run();

  // pointer to the game's camera
  extern class Camera *primaryCamera;

  // pointer to the view's renderer
  extern SDL_Renderer *renderer;

  // pointer to the view's window
  extern SDL_Window *window;
}
