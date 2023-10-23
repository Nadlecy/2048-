#include <iostream>;
#include "Grid.h";
#include "Box.h";


Grid::Grid() 
{
	array = {};
	for (int i = 0; i < 4; i++) {
		for (int u = 0; u < 4; u++)
		{
			array.push_back(new Box(i, u));
		}
	}
};

void Grid::Display()
{
	for (int i = 0; i < 16; i++) {
		cout << array[i]->box_value << endl;
	}
}

void Grid::Movement()
{
	int i = 0;
};