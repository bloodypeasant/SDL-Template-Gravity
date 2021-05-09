#include <algorithm>
#include <stdio.h>
#include "ModelAble.hpp"

using namespace Game;

// static variables must be initialized outside the header declaration
std::vector<ModelAble *> ModelAble::modelAbles;
int ModelAble::timeChange = 0;

void ModelAble::RunAll(int timeChange)
{
  ModelAble::timeChange = timeChange;
  for (auto modelAble : modelAbles)
  {
    modelAble->RunModelAble();
  }
}

ModelAble::ModelAble()
{
  printf("    ModelAble::ModelAble()\n");
  modelAbles.emplace_back(this);
}

ModelAble::~ModelAble()
{
  printf("    ModelAble::~ModelAble()\n");
  auto it = std::find(modelAbles.begin(), modelAbles.end(), this);
  if (it != modelAbles.end())
  {
    std::iter_swap(it, modelAbles.end() - 1);
    modelAbles.pop_back();
  }
}
