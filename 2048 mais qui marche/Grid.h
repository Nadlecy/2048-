#pragma once
#include <iostream>;
#include <vector>;
using namespace std;
#include "Box.h";

class Grid
{
public:
	vector<Box *> array;

	Grid();

	void Display();
	void Movement();

};