#pragma once

#include "stacker.h"

#include <vector>

class Test;

class TestManager {
public:
	std::vector<Test> testList;
	Stacker stacker;

	TestManager();

	bool TryTests();
};