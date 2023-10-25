#include "Grid.h";
#include "Box.h";

#include <iostream>;
#include <string>;
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


Grid::Grid() 
{
	array = {};
	for (int i = 0; i < 16; i++) {
		array.push_back(new Box());
	}

	playing = true;
	stacker = Stacker();
	directionArray = {"up","down","left","right"};
};

void Grid::Display()
{
	//system("cls");
	cout << "_____________________" << endl;
	for (int i = 0; i < 4; i++) {
		cout << "|";
		for (int u = 0; u < 4; u++) {
			if (array[i*4 + u]->box_value > 0)
			{

				int size = trunc(log10(array[i * 4 +u]->box_value));

				if (size == 4){

					cout << array[i * 4 +u]->box_value;

				} else {

					string space;

					for (int j = size +1; j < 4; j++){

						space += " ";

					}

					cout << space << array[i * 4 +u]->box_value <<"|";

				}
			}
			else {
				cout << "    |";
			}
		}
		cout << endl << "_____________________" << endl;
	}
}

void Grid::CreateNumber(bool isFirst)
{
	bool placing = false;

	for (int i = 0; i < 16; i++) {
		if (array[i]->box_value == 0) {
			placing = true;
			cout << "gwagwa";
		}
	}


	int rng = rand() % 16;

	if (isFirst)
	{
		array[rng]->box_value = 2;
	} 
	else 
	{
		while (placing) {
			if (array[rng]->box_value == 0) {

				if (rand() % 10 == 9)
				{
					array[rng]->box_value = 4; 
				}
				else {
					array[rng]->box_value = 2;
				}
				placing = false;
			}
			else {
				rng = rand() % 16;
			}
		}
	}
}

void Grid::Movement()
{
	string playerAnswer;

	bool choosing = true;
	while (choosing) {


		char c = getch();
		switch (c) {
		case KEY_UP:
			playerAnswer = "up";
			choosing = false;
			break;
		case KEY_DOWN:
			playerAnswer = "down";
			choosing = false;
			break;
		case KEY_LEFT:
			playerAnswer = "right";
			choosing = false;
			break;
		case KEY_RIGHT:
			playerAnswer = "left";
			choosing = false;
			break;
		default:
			choosing = true;
			break;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (playerAnswer == directionArray[i]) {
			stacker.direction = i;
			stacker.Launch(i, array);
		}
	}
};

bool Grid::Win()
{
	for (int i = 0; i < 16; i++) {
		if (array[i]->box_value == 2048) {
			system("cls");
			cout << "you win";

			return false;
		}
	}

	return true;
};

/*bool Grid::Defeat()
{
	int u = 0

	for (int i = 0, i < 16, i++) {
		if (array[i] != 0) {
			u += 1;
		}
	}

	if (u == 16) {
		return false // faudrait ajouer une fonction dans la stackers pour effectuer les 4 deplacement possible voir si il y en a un qui bouge
	}

	return true
};*/