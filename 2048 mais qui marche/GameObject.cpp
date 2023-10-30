#include "GameObject.h"

#include <vector>
#include <iostream>
using namespace std;

GameObject::GameObject(const char* name, const char* filename, vector<int> array, const char* type)
{
	objectName = name;
	objectFilename = filename;
	objectPosition = array;
	objectType = type;
};