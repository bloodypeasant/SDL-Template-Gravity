#pragma once
#include "SDL.h"
#include <vector>

namespace Game
{
  // Capable of responding to mouse events in Controller's loop
  class MouseAble
  {
  public:
    // Called by Controller to run all MouseAble objects in the game
    static void RunAll(SDL_Event *event);

    // Constructs a MouseAble object
    MouseAble();

    // Destructs a MouseAble object
    ~MouseAble();

    // Runs the MouseAble object
    void Run();

  protected:
    // pointer to mouse event to be shared by all MouseAble objects
    static SDL_Event *event;

    // contains pointers to all MouseAble objects in the game
    static std::vector<MouseAble *> mouseAbles;
  };
}
