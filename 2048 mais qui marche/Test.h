#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Box;

class Test
{
public:
	const char * testName;
	vector<Box> situationArray;
	vector<Box> resultArray;
	int testDirection;
	bool expectedResult;

	Test(const char * name, int direction, vector<int> array, vector<int> arrayTwo, bool expected = true);

	/*bool DirectionRight();
	bool DirectionLeft();
	bool DirectionUp();
	bool DirectionDown();
	bool FusionNormal();
	bool FusionWithGap();
	bool FusionFourAdjacent();
	bool Win();
	bool Loss();

	bool TryAll();*/
};