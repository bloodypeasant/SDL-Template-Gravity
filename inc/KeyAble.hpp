#pragma once
#include "SDL.h"
#include <vector>

namespace Game
{
  // Capable of responding to keyState updates in Controller's loop
  class KeyAble
  {
  public:
    // Called by Controller to run all KeyAble objects in the game
    static void RunAll(Uint8 const *keyState);

    // Constructs a KeyAble object
    KeyAble();

    // Destructs a KeyAble object
    virtual ~KeyAble();

    // Runs the KeyAble object
    virtual void RunKeyAble() = 0;

  protected:
    // contains pointers to all KeyAble objects in the game
    static std::vector<KeyAble *> keyAbles;

    // pointer to keyState to be shared by all KeyAble objects
    static Uint8 const *keyState;
  };
}
