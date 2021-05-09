#include "Config.hpp"
#include "SDL_image.h"

namespace Game::Config
{
  namespace Actor
  {
    namespace SampleBackground
    {
      char const *
          IMAGE_FILE =
              "assets/images/sample-background.jpg";
    }

    namespace SampleActorPlayer
    {
      float const
          ACC_A =
              0.0f; // in radians per millisecond per millisecond

      float const
          ACC_MAG_TRANS =
              0.0001f; // in model units per millisecond per millisecond

      float const
          ACC_X =
              0.0f; // in model units per millisecond per millisecond

      float const
          ACC_Y =
              0.0f; // in model units per millisecond per millisecond

      float const
          DIM_X =
              100.0f; // in model coordinates

      float const
          DIM_Y =
              116.0f; // in model coordinates

      Uint8 const
          KEY_FWD =
              SDL_SCANCODE_W;

      Uint8 const
          KEY_ROTATE_CCW =
              SDL_SCANCODE_A;

      Uint8 const
          KEY_ROTATE_CW =
              SDL_SCANCODE_D;

      char const *
          IMAGE_FILE =
              "assets/images/sample-actor-player.png";

      float const
          MASS =
              1000.0f; // in model mass units

      float const
          POS_A =
              0.0f; // in model coordinates

      float const
          POS_X =
              448.0f; // in model coordinates

      float const
          POS_Y =
              -320.0f; // in model coordinates

      float const
          SPEED_MAX_ANGULAR =
              0.005f; // in radians per millisecond

      float const
          SPEED_MAX_TRANS =
              0.05f; // in model units per millisecond

      float const
          VEL_A =
              0.0f; // in radians per millisecond

      float const
          VEL_X =
              0.0f; // in model units per millisecond

      float const
          VEL_Y =
              0.0f; // in model units per millisecond
    }

    namespace SampleActorSun
    {
      float const
          DIM_X =
              300.0f; // in model coordinates

      float const
          DIM_Y =
              300.0f; // in model coordinates

      char const *
          IMAGE_FILE =
              "assets/images/sample-actor-sun.png";

      float const
          MASS =
              1000.0f; // in model mass units

      float const
          POS_A =
              0.0f; // in radians

      float const
          POS_X =
              0.0f; // in model coordinates

      float const
          POS_Y =
              0.0f; // in model coordinates
    }
  }

  namespace Controller
  {
    Uint8 const
        KEY_STOP_GAME =
            SDL_SCANCODE_ESCAPE;
  }

  namespace Model
  {
    int const
        LOOP_TIME_MAX =
            50; // milliseconds

    int const
        LOOP_TIME_MIN =
            16; // milliseconds

    float const
        WORLD_DIM_X =
            1024.0f; // in model coordinates

    float const
        WORLD_DIM_Y =
            768.0f; // in model coordinates
  }

  namespace View
  {
    Color const
        BG_COLOR =
            {0, 0, 255, 255};

    /* Options (which can be joined by | operator) are
        IMG_INIT_JPG
        IMG_INIT_PNG
        SDL_INIT_TIF.
    */
    int const
        INIT_IMAGE_FLAGS =
            IMG_INIT_PNG;

    /* Options (which can be joined by | operator) are
        SDL_RENDERER_SOFTWARE: the renderer is a software fallback
        SDL_RENDERER_ACCELERATED: the renderer uses hardware acceleration
        SDL_RENDERER_PRESENTVSYNC: present is synchronized with the refresh rate
        SDL_RENDERER_TARGETTEXTURE: the renderer supports rendering to texture
    */
    Uint32 const
        INIT_RENDERER_FLAGS =
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    /* Index of the rendering driver to initialize, or -1 to initialize the
    first one supporting the requested flags. */
    int const
        INIT_RENDERER_INDEX =
            -1;

    /* Options (which can be joined by | operator) are
        SDL_INIT_TIMER: timer subsystem
        SDL_INIT_AUDIO: audio subsystem
        SDL_INIT_VIDEO: video subsystem; automatically initializes the events
                        subsystem
        SDL_INIT_JOYSTICK: joystick subsystem; automatically initializes the
                           events subsystem
        SDL_INIT_HAPTIC: haptic (force feedback) subsystem
        SDL_INIT_GAMECONTROLLER: controller subsystem; automatically initializes
                                 the joystick subsystem
        SDL_INIT_EVENTS: events subsystem
        SDL_INIT_EVERYTHING: all of the above subsystems
        SDL_INIT_NOPARACHUTE: compatibility; this flag is ignored
    */
    Uint32 const
        INIT_SDL_FLAGS =
            SDL_INIT_VIDEO | SDL_INIT_AUDIO;

    /* Options (which can be joined by | operator) are 
        SDL_WINDOW_FULLSCREEN: fullscreen window
        SDL_WINDOW_FULLSCREEN_DESKTOP: fullscreen window at desktop resolution
        SDL_WINDOW_OPENGL: window usable with an OpenGL context
        SDL_WINDOW_VULKAN: window usable with a Vulkan instance
        SDL_WINDOW_METAL: window usable with a Metal instance
        SDL_WINDOW_HIDDEN: window is not visible
        SDL_WINDOW_BORDERLESS: no window decoration
        SDL_WINDOW_RESIZABLE: window can be resized
        SDL_WINDOW_MINIMIZED: window is minimized
        SDL_WINDOW_MAXIMIZED: window is maximized
        SDL_WINDOW_INPUT_GRABBED: window has grabbed input focus
        SDL_WINDOW_ALLOW_HIGHDPI: window should be created in high-DPI mode if
                                  supported (>= SDL 2.0.1)
    */
    Uint32 const
        INIT_WINDOW_FLAGS =
            0;

    char const *
        TITLE =
            "Title";

    int const
        WINDOW_DIM_X =
            1024; // in screen coordinates

    int const
        WINDOW_DIM_Y =
            768; // in screen coordinates

    /* Options are
        x-position of the SDL window in screen coordinates
        SDL_WINDOWPOS_CENTERED
        SDL_WINDOWPOS_UNDEFINED
    */
    int const
        WINDOW_POS_X =
            SDL_WINDOWPOS_CENTERED;

    /* Options are
        y-position of the SDL window in screen coordinates
        SDL_WINDOWPOS_CENTERED
        SDL_WINDOWPOS_UNDEFINED
    */
    int const
        WINDOW_POS_Y =
            SDL_WINDOWPOS_CENTERED;
  }
}
