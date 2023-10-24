#pragma once
#include <iostream>;
#include <vector>;
using namespace std;
#include "Box.h";
#include "Stacker.h";

class Grid
{
public:
	vector<Box *> array;
	bool playing;
	Stacker stacker;

	Grid();

	void Display();
	void CreateNumber(bool isFirst);
	void Movement();

};