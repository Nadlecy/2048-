#include "Box.h"
#include "Grid.h"
#include "TestManager.h"

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	
	TestManager tester;
	tester.TryTests();
	
	/*
	Grid* Grille = new Grid();

	Grille -> CreateNumber(true);
	

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
	return 0;*/
}