#include "Grid.h"
#include "Box.h"

#include <iostream>
#include <string>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


Grid::Grid() 
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			array.push_back(Box(0, "box", 0, 0, j, i));
		}
	}

	playing = true;
	score = 0;
	oldScore = 0;
	stacker = Stacker();
	directionArray = {"up","down","left","right"};

	srand(time(NULL));
};

/*
void Grid::Display()
{
	
	cout << "_____________________" << endl;
	for (int i = 0; i < 4; i++) {
		cout << "|";
		for (int u = 0; u < 4; u++) {
			if (array[i*4 + u].box_value > 0)
			{

				int size = trunc(log10(array[i * 4 +u].box_value));

				if (size == 4){

					cout << array[i * 4 +u].box_value;

				} else {

					string space;

					for (int j = size +1; j < 4; j++){

						space += " ";

					}

					cout << space << array[i * 4 +u].box_value <<"|";

				}
			}
			else {
				cout << "    |";
			}
		}
		cout << endl << "_____________________" << endl;
	}

}*/

void Grid::CreateNumber(bool isFirst)
{
	bool placing = false;

	for (int i = 0; i < 16; i++) {
		if (array[i].box_value == 0) {
			placing = true;
		}
	}


	int rng = rand() % 16;

	if (isFirst)
	{
		array[rng].box_value = 2;
	} 
	else 
	{
		while (placing) {
			if (array[rng].box_value == 0) {

				if (rand() % 10 == 9)
				{
					array[rng].box_value = 4; 
				}
				else {
					array[rng].box_value = 2;
				}
				placing = false;
			}
			else {
				rng = rand() % 16;
			}
		}
	}

	oldScore = score;

	for (int i = 0; i < 16; i++) {

		score += (array[i].box_value);

	}

	score -= oldScore;
}

void Grid::Movement()
{
	string playerAnswer;

	bool choosing = true;
	while (choosing) {


		char c = _getch();
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
			playerAnswer = "left";
			choosing = false;
			break;
		case KEY_RIGHT:
			playerAnswer = "right";
			choosing = false;
			break;
		default:
			choosing = true;
			break;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (playerAnswer == directionArray[i]) {
			stacker.Launch(i, array);
		}
	}
};

bool Grid::Win()
{
	for (int i = 0; i < 16; i++) {
		if (array[i].box_value == 2048) {
			cout << "you win" << endl;

			return false;
		}
	}

	return true;
};

