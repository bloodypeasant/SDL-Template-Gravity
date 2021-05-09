#include "Controller.hpp"
#include "Game.hpp"
#include "Model.hpp"
#include <stdio.h>
#include "View.hpp"

int Game::argc = 0;
char **Game::argv = nullptr;
bool Game::isRunning = false;

void Game::Finalize()
{
  printf("\nGame::Finalize()\n");
  Model::Finalize();
  View::Finalize();
}

bool Game::Initialize()
{
  printf("\nGame::Initialize()\n");
  if (!View::Initialize())
  {
    return false;
  }
  Model::Initialize();
  return true;
}

void Game::Main(int argc, char **argv)
{
  printf("\nGame::Launch()\n");
  Game::argc = argc;
  Game::argv = argv;
  if (Initialize())
  {
    Run();
  }
  Finalize();
}

void Game::Run()
{
  printf("\nGame::Run()\n");
  isRunning = true;
  while (isRunning)
  {
    Controller::Run();
    Model::Run();
    View::Run();
  }
}

void Game::StopGame()
{
  printf("\nGame::StopGame()\n");
  isRunning = false;
}
