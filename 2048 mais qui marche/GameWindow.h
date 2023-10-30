#pragma once

class GameObject;
class SDL_Window;
class SDL_Renderer;

#include <vector>
using namespace std;

class GameWindow
{
public:
	vector<GameObject*> objectList;
	vector<int> windowSize;
	SDL_Window* window;
	SDL_Renderer* renderer;

	GameWindow();

	void ScreenDisplay();
	void NewObject(const char* name, const char* filename, vector<int> sizeArray, vector<int> array, const char* type);
	void CloseWindow();
};
