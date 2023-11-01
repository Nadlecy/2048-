#pragma once

#include "GameObject.h"

#include <map>
using namespace std;

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;

class Box: GameObject
{
public:
	int box_value;

	Box(int value, const char* name, int sizeW, int sizeH, int posX, int posY);
	Box(int value);
	Box();

	void BoxDisplay(int screenH, int screenW, map<const char*, SDL_Texture*> textureList);
};