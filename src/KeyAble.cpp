#include <algorithm>
#include <stdio.h>
#include "KeyAble.hpp"

using namespace Game;

// static variables must be initialized outside the header declaration
std::vector<KeyAble *> KeyAble::keyAbles;
Uint8 const *KeyAble::keyState = nullptr;

void KeyAble::RunAll(Uint8 const *keyState)
{
  KeyAble::keyState = keyState;
  for (auto keyAble : keyAbles)
  {
    keyAble->RunKeyAble();
  }
}

KeyAble::KeyAble()
{
  printf("    KeyAble::KeyAble()\n");
  keyAbles.emplace_back(this);
}

KeyAble::~KeyAble()
{
  printf("    KeyAble::~KeyAble()\n");
  auto it = std::find(keyAbles.begin(), keyAbles.end(), this);
  if (it != keyAbles.end())
  {
    std::iter_swap(it, keyAbles.end() - 1);
    keyAbles.pop_back();
  }
}
