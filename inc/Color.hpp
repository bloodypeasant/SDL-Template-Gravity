#pragma once
#include "SDL.h"

namespace Game
{
  struct Color
  {
    // Constructs a new color with specified RGBA values
    Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    // red 0-255
    Uint8 r;

    // green 0-255
    Uint8 g;

    // blue 0-255
    Uint8 b;

    // alpha 0-255
    Uint8 a;
  };
}
