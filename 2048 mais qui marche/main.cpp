
#include "Grid.h"
#include "TestManager.h"
#include "GameWindow.h"

#include <iostream>
#include <vector>
#include <SDL.h>

using namespace std;

void Test() 
{
	TestManager tester;
	tester.TryTests();
}

void Play() 
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	GameWindow game = GameWindow();

	game.grid.CreateNumber(true);
	game.LoadTextures();

	while (game.grid.playing == true)
	{
		game.grid.CreateNumber(false);
		game.grid.Display();

		game.ScreenDisplay();
		game.grid.Movement();

		//system("cls");

		if (not (game.grid.Win() && game.grid.stacker.OverallCheck(game.grid.array))) {
			game.grid.Display();
			game.grid.playing = false;
		}

	}

	game.CloseWindow();
		
}

int main(int argc, char** argv)
{
	Test();
	Play();

	return 0;
}