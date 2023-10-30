#pragma once

class GameObject;
class SDL_Window;

#include <vector>
using namespace std;

class GameWindow
{
public:
	vector<GameObject*> ObjectList;
	vector<int> windowSize;
	SDL_Window* window;

	GameWindow();

	void NewObject(const char* name, const char* filename, vector<int> array, const char* type);
	void CloseWindow();
};
