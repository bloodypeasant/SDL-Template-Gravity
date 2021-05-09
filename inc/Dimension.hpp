#pragma once

namespace Game
{
  // Holds width and height attributes
  struct Dimension
  {
    // Constructs a Dimension
    Dimension(float x, float y);

    // x-dimension ("width") in model units
    float x;

    // y-dimension ("height") in model units
    float y;
  };
}
