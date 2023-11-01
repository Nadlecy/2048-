#include "Box.h"

#include <string> 
#include <SDL.h>
#include <SDL_image.h>
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

void Box::BoxDisplay(int screenH, int screenW, map<string, SDL_Texture*> textureList, SDL_Renderer* renderer)
{

	SDL_Rect dstrect;

	dstrect.x = screenW / 2 - screenH / 2 + 20 /* + posX */ ;
	dstrect.y = 20 /* + posY */;
	dstrect.w = (screenW / 2 - screenH / 2) / 3;
	dstrect.h = (screenW / 2 - screenH / 2) / 3;

	SDL_RenderCopy(renderer, textureList[to_string(box_value)], NULL, &dstrect);

	SDL_RenderPresent(renderer);
}