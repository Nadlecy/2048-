#pragma once

class GameObject
{
public:
	
	const char* objectName;
	const char* objectFilename;
	int width;
	int height;
	int positonX;
	int positionY;
	const char* objectType;

	GameObject(const char* name, const char* filename, int width, int height, int positonX, int positionY , const char* type);

};