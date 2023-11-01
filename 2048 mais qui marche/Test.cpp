#include "Test.h"
#include "Box.h"

Test::Test(const char* name, int direction, vector<int> array, vector<int> arrayTwo, bool expected /*= true*/)
{
	testName = name;
	testDirection = direction;
	
	situationArray = {};
	for (int i = 0; i < 16; i++) {
		situationArray.push_back(Box(array[i]));
	}

	resultArray = {};
	for (int i = 0; i < 16; i++) {
		resultArray.push_back(Box(arrayTwo[i]));
	}

	expectedResult = expected;
}