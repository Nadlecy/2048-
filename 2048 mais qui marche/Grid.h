#pragma once

#include "Stacker.h"
#include "Box.h"

#include <vector>
#include <string>

using namespace std;

class Grid
{
public:
	vector<Box> array;
	bool playing;
	int score;
	int oldScore;
	Stacker stacker;
	vector<string> directionArray;

	Grid();

	void Display();
	void CreateNumber(bool isFirst);
	void Movement();
	bool Win();
	//bool Defeat();

};