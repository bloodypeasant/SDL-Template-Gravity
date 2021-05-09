#include <algorithm>
#include <stdio.h>
#include "MouseAble.hpp"

using namespace Game;

// static variables must be initialized outside the header declaration
SDL_Event *MouseAble::event = nullptr;
std::vector<MouseAble *> MouseAble::mouseAbles;

void MouseAble::RunAll(SDL_Event *event)
{
  MouseAble::event = event;
  for (auto mouseAble : mouseAbles)
  {
    mouseAble->Run();
  }
}

MouseAble::MouseAble()
{
  printf("MouseAble::MouseAble()\n");
  mouseAbles.emplace_back(this);
}

MouseAble::~MouseAble()
{
  printf("MouseAble::~MouseAble()\n");
  auto it = std::find(mouseAbles.begin(), mouseAbles.end(), this);
  if (it != mouseAbles.end())
  {
    std::iter_swap(it, mouseAbles.end() - 1);
    mouseAbles.pop_back();
  }
}

void MouseAble::Run()
{
  // TODO
}
