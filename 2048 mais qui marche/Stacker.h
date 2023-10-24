#pragma once
#include <iostream>;
#include <vector>;
#include "Box.h";
#include "Grid.h";
using namespace std;

class Stacker
{
public:
	vector<Box*> storage;
	int direction;//to lower memory consumption, each direction is represented by a single digit

	Stacker();

	void Retrieve(int slot, Grid grid);
	void Squish();
	void Send(int slot, Grid grid);
	void Launch(int direction, Grid grid);
};