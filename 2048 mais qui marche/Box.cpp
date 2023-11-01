#include "Box.h"

using namespace std;


Box::Box(int value, const char* name, int sizeW, int sizeH, int posX, int posY) :GameObject(name, sizeW, sizeH, posX, posY)
{
	box_value = value;
};

Box::Box(int value) :GameObject("box", 0, 0, 0, 0)
{
	box_value = value;
};

Box::Box() :Box(0)
{
	box_value = 0;
};

void Box::BoxDisplay(int screenH, int screenW, map<const char*, SDL_Texture*> textureList)
{
	
}