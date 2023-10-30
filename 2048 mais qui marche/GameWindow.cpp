#include "GameWindow.h"
#include "GameObject.h"
#include <SDL.h>

#include <vector>
#include <iostream>
using namespace std;

GameWindow::GameWindow()
{
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	windowSize = { DM.w, DM.h }; // {largeur, hauteur}
	window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSize[0], windowSize[1], SDL_WINDOW_FULLSCREEN_DESKTOP);

};

void GameWindow::NewObject(const char* name, const char* filename, vector<int> array, const char* type) {
	ObjectList.push_back(new GameObject(name, filename, array, type));
};

void GameWindow::CloseWindow() {

}