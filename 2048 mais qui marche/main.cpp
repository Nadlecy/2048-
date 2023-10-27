#include "Box.h"
#include "Grid.h"
#include "TestManager.h"

#include <iostream>
#include <vector>
//#include <SDL.h>

using namespace std;

void Test() 
{
	TestManager tester;
	tester.TryTests();
}

void Play() 
{
	//SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	Grid* Grille = new Grid();
	Grille->CreateNumber(true);


	while (Grille->playing == true)
	{
		Grille->CreateNumber(false);
		Grille->Display();


		Grille->Movement();

		system("cls");

		if (not (Grille->Win() && Grille->stacker.OverallCheck(Grille->array))) {
			Grille->Display();
			Grille->playing = false;
		}

	}

	//SDL_Quit();
}

int main()
{
	Test();
	//Play();

	return 0;
}