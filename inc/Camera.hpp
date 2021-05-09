#pragma once
#include "Actor.hpp"

namespace Game
{
  // Camera "sees" the portion of the model world to be graphically rendered
  class Camera : public Actor
  {
  public:
    // Constructs a new Camera
    Camera(float posX, float posY, float posA, float dimX, float dimY);

    // Destructs a Camera
    ~Camera();
  };
}
