#pragma once
#include "Box.h"
#include "Stacker.h"

#include <iostream>
#include <vector>

using namespace std;

class Grid
{
public:
	vector<Box *> array;
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