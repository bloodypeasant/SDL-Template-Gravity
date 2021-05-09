#include "Camera.hpp"
#include <stdio.h>

using namespace Game;

Camera::Camera(float posX, float posY, float posA, float dimX, float dimY)
    : Actor(posX, posY, posA, dimX, dimY)
{
  printf("    Camera::Camera(%.1f, %.1f, %.1f, %.1f, %.1f)\n",
         posX, posY, posA, dimX, dimY);
}

Camera::~Camera()
{
  printf("    Camera::~Camera()\n");
}
