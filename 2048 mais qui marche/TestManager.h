#pragma once
#include "Test.h"
#include "stacker.h"

#include <vector>

class TestManager {
public:
	std::vector<Test> testList;
	Stacker stacker;

	TestManager();

	bool TryTests();
};