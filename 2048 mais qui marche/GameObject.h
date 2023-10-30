#pragma once

#include <vector>
#include <iostream>
using namespace std;

class GameObject
{
public:
	
	const char* objectName;
	const char* objectFilename;
	vector<int> objectSize;
	vector<int> objectPosition;
	const char* objectType;

	GameObject(const char* name, const char* filename, vector<int> sizeArray, vector<int> array, const char* type);

};