#include "Camera.hpp"
#include "Config.hpp"
#include "SDL_image.h"
#include "View.hpp"
#include "ViewAble.hpp"
#include <stdio.h>

using namespace Game;
using namespace Config::View;

Camera *View::primaryCamera = nullptr;
SDL_Renderer *View::renderer = nullptr;
SDL_Window *View::window = nullptr;

void View::Finalize()
{
  printf("\n  View::Finalize()\n");
  // Delete the primary camera
  printf("\n  - DELETE CAMERA\n");
  delete primaryCamera;
  primaryCamera = nullptr;
  // Clean up dynamically loaded (JPG, PNG, TIF) library handles / free memory
  IMG_Quit();
  // Destroy the window's rendering context / free associated textures
  SDL_DestroyRenderer(renderer);
  // Destroy the SDL window
  SDL_DestroyWindow(window);
  // Clean up all initialized SDL subsystems
  SDL_Quit();
}

bool View::Initialize()
{
  printf("\n  View::Intialize()\n");

  // Initialize SDL library with INIT_SDL_FLAGS specified in Config file.
  if (SDL_Init(INIT_SDL_FLAGS) != 0)
  {
    SDL_Log("ERROR -- SDL_Init(): %s", SDL_GetError());
    return false;
  }

  // Create an SDL window using arguments specified in Config file.
  window = SDL_CreateWindow(TITLE, WINDOW_POS_X, WINDOW_POS_Y, WINDOW_DIM_X,
                            WINDOW_DIM_Y, INIT_WINDOW_FLAGS);
  if (!window)
  {
    SDL_Log("ERROR -- SDL_CreateWindow(): %s", SDL_GetError());
    return false;
  }

  // Create 2D renderering context for the window using args in Config file.
  renderer = SDL_CreateRenderer(window, INIT_RENDERER_INDEX,
                                INIT_RENDERER_FLAGS);
  if (!renderer)
  {
    SDL_Log("ERROR -- SDL_CreateRenderer(): %s", SDL_GetError());
    return false;
  }

  // Initialize JPG, PNG and/or TIF support per INIT_IMAGE_FLAGS in Config file.
  if (IMG_Init(INIT_IMAGE_FLAGS) == 0)
  {
    SDL_Log("ERROR -- IMG_Init(): %s", SDL_GetError());
    return false;
  }

  // Create the game's primary camera
  printf("\n  + NEW CAMERA\n");
  primaryCamera = new Camera(0, 0, 0, WINDOW_DIM_X, WINDOW_DIM_Y);

  // Set the ViewAble class's static variables
  ViewAble::SetCamera(primaryCamera);
  ViewAble::SetRenderer(renderer);

  // Initialization was successful
  return true;
}

void View::Run()
{
  /* Note that the renderer should be cleared even if a background image is
  being drawn every frame, because clearing improves performance by allowing
  unneeded frame data to be discarded. */
  SDL_SetRenderDrawColor(renderer,
                         BG_COLOR.r, BG_COLOR.g, BG_COLOR.b, BG_COLOR.a);
  SDL_RenderClear(renderer);

  /*****************************************************************************
  // Uncomment this code to test basic SDL drawing

  SDL_Rect rect1{100, 100, 100, 100};
  SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
  SDL_RenderFillRect(renderer, &rect1);
  *****************************************************************************/

  ViewAble::RunAll();

  // Update the screen with the newly performed renderings.
  SDL_RenderPresent(renderer);
}
