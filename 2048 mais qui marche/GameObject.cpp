#include "GameObject.h";

#include <vector>
#include <iostream>;
using namespace std;

GameObject::GameObject(const char* name, vector<int> array, vector<int> arrayTwo)
{
	objectName = name;
	objectDimension = array;
	objectPosition = arrayTwo;
};