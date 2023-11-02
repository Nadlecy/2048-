#pragma once

class GameObject
{
	//ask about this !
public:
	
	const char* objectName;
	int width;
	int height;
	int positionX;
	int positionY;

	GameObject(const char* name, int width, int height, int positionX, int positionY);
};