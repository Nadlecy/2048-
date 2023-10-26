#pragma once
#include "Test.h"
#include "stacker.h"

#include <vector>

class TestManager {
public:
	vector<Test*> testList;
	Stacker stacker;

	TestManager();

	bool TryTests();
};