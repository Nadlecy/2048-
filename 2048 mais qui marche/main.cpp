
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

	Grid* Grille = new Grid();
	Grille->CreateNumber(true);
	game.LoadTextures();
	game.ScreenDisplay();

	while (Grille->playing == true)
	{
		Grille->CreateNumber(false);
		Grille->Display();


		Grille->Movement();

		//system("cls");

		if (not (Grille->Win() && Grille->stacker.OverallCheck(Grille->array))) {
			Grille->Display();
			Grille->playing = false;
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