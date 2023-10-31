#include "GameObject.h"


GameObject::GameObject(const char* name, const char* filename, int sizeW, int sizeH, int posX, int posY, const char* type)
{
	objectName = name;
	objectFilename = filename;
	width = sizeW;
	height = sizeH;
	positonX = posX;
	positionY = posY;
	objectType = type;
};