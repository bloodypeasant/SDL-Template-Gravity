#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace Game
{
  // Capable of being viewed (i.e., in View's loop to be graphically rendered)
  class ViewAble
  {
  public:
    // Called by View to run all ViewAble objects in the game
    static void RunAll();

    // Called by View to set the active camera
    static void SetCamera(class Camera *camera);

    // Called by View to set the active renderer
    static void SetRenderer(class SDL_Renderer *renderer);

    // Constructs a ViewAble object
    ViewAble(class Position &pos, class Dimension &dim);

    // Destructs a ViewAble object
    ~ViewAble();

    // Runs the ViewAble object
    void Run();

    // Sets the texture by loading fileName if not yet loaded
    void SetTexture(const std::string &fileName);

  private:
    // static pointer to camera to be shared by all viewAbles when rendering
    static class Camera *camera;

    // static pointer to renderer to be shared by all viewAbles
    static class SDL_Renderer *renderer;

    // static map of loaded textures
    static std::unordered_map<std::string, class SDL_Texture *> textures;

    // contains pointers to all viewAbles in the game
    static std::vector<ViewAble *> viewAbles;

    // reference to the ViewAble object's dimensions
    class Dimension &dim;

    // reference to the ViewAble object's position
    class Position &pos;

    // pointer to this viewAble's texture
    class SDL_Texture *texture;
  };
}
