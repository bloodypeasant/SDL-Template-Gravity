#pragma once

// namespace enclosing the entire game, and providing game loop functionality
namespace Game
{
  // Called at end of game to shut down resources.
  void Finalize();

  // Called at start of game to initialize resources.
  bool Initialize();

  // Called by Main.cpp to launch the game.
  void Main(int argc, char **argv);

  // Called between Initialize and Finalize to run the game loop.
  void Run();

  // Called to stop the game.
  void StopGame();

  // from the command line, if desired
  extern int argc;

  // from the command line, if desired
  extern char **argv;

  // indicates whether game loop is currently running
  extern bool isRunning;
}
