#pragma once
#include <vector>

namespace Game
{
  // Capable of responding to timeChange updates passed from Model's loop
  class ModelAble
  {
  public:
    // Called by Model to run all ModelAble objects in the game
    static void RunAll(int timeChange);

    // Constructs a ModelAble object
    ModelAble();

    // Destructs a ModelAble object
    virtual ~ModelAble();

    // Runs the ModelAble object
    virtual void RunModelAble() = 0;

  protected:
    // contains pointers to all ModelAble objects in the game
    static std::vector<ModelAble *> modelAbles;

    // timeChange to be shared by all ModelAble objects
    static int timeChange;
  };
}
