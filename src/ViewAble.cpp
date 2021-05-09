#include <algorithm>
#include "Camera.hpp"
#include "Dimension.hpp"
#include "Position.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include "ViewAble.hpp"

using namespace Game;

float const DEG_PER_RAD = 180 / 3.14159; // TODO: incorporate a math library

// static variables must be initialized outside the header declaration
Camera *ViewAble::camera = nullptr;
SDL_Renderer *ViewAble::renderer = nullptr;
std::unordered_map<std::string, SDL_Texture *> ViewAble::textures;
std::vector<ViewAble *> ViewAble::viewAbles;

void ViewAble::RunAll()
{
  for (auto viewAble : viewAbles)
  {
    viewAble->Run();
  }
}

void ViewAble::SetCamera(Camera *camera)
{
  printf("\n    ViewAble::SetCamera()\n");
  ViewAble::camera = camera;
}

void ViewAble::SetRenderer(SDL_Renderer *renderer)
{
  printf("    ViewAble::SetRenderer()\n");
  ViewAble::renderer = renderer;
}

ViewAble::ViewAble(Position &pos, Dimension &dim)
    : dim(dim), pos(pos), texture(nullptr)
{
  printf("    ViewAble::ViewAble(pos(%.1f, %.1f), dim(%.1f, %.1f))\n",
         pos.x, pos.y, dim.x, dim.y);
  viewAbles.emplace_back(this);
}

ViewAble::~ViewAble()
{
  printf("    ViewAble::~ViewAble()\n");
  auto it = std::find(viewAbles.begin(), viewAbles.end(), this);
  if (it != viewAbles.end())
  {
    std::iter_swap(it, viewAbles.end() - 1);
    viewAbles.pop_back();
  }
}

void ViewAble::SetTexture(const std::string &fileName)
{
  printf("    ViewAble::SetTexture(%s)\n", fileName.c_str());
  // check to see if the same fileName has already been turned into a texture
  auto it = textures.find(fileName);
  if (it != textures.end())
  {
    // if the texture already exists, use it
    texture = it->second;
  }
  else
  {
    // Load the image file to a surface temporarily.
    SDL_Surface *surface = IMG_Load(fileName.c_str());
    if (!surface)
    {
      SDL_Log("ERROR -- IMG_Load(%s)", fileName.c_str());
      texture = nullptr;
      return;
    }

    // TODO : temporary -- for testing
    if (!renderer)
    {
      SDL_Log("ERROR -- No renderer.");
    }

    // Use the surface to create a texture.
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    // Free the temporary surface (it is no longer needed)
    SDL_FreeSurface(surface);
    if (!texture)
    {
      SDL_Log("ERROR -- SDL_CreateTextureFromSurface(%s)", fileName.c_str());
      texture = nullptr;
      return;
    }

    // Store the texture in the textures map using fileName as the key.
    textures.emplace(fileName.c_str(), texture);
  }
}

void ViewAble::Run()
{
  // define the viewAble's bounding rectangle
  SDL_Rect rect{
      (int)(0.5 * (camera->GetDimX() - dim.x) + pos.x - camera->GetPosX()),
      (int)(0.5 * (camera->GetDimY() - dim.y) + pos.y - camera->GetPosY()),
      (int)dim.x, (int)dim.y};
  // draw the viewAble
  SDL_RenderCopyEx(renderer, texture, nullptr, &rect, pos.a * DEG_PER_RAD,
                   nullptr, SDL_FLIP_NONE);
}
