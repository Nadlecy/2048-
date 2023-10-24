#pragma once
#include <iostream>;
#include <vector>;
using namespace std;
#include "Box.h";

class Grid
{
public:
	vector<Box *> array;
	bool playing;

	Grid();

	void Display();
	void CreateNumber(bool isFirst);
	void Movement();

};