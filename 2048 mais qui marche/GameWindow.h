#pragma once

class GameObject;
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;

#include "Grid.h"

#include <vector>
#include <map>
#include <string> 
using namespace std;

class GameWindow
{
public:
	map<string, SDL_Texture*> textureList;
	vector<GameObject*> objectList;
	vector<int> windowSize;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Grid grid;

	GameWindow();

	void ScreenDisplay();
	void NewObject(const char* name, int sizeW, int sizeH, int posX, int posY);
	void LoadTextures();
	void CloseWindow();
};
