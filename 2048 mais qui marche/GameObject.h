#pragma once

class GameObject
{
private:
	
	const char* objectName;
	int width;
	int height;
	int positionX;
	int positionY;

public:
	GameObject(const char* name, int width, int height, int positionX, int positionY);
};