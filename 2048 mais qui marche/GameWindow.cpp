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
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	
	SDL_SetWindowTitle(window, "2048");
};

void GameWindow::ScreenDisplay() {
	int listlenght = objectList.size();

	for ( int i =0; i < listlenght; i++){
		SDL_Surface* /*nom du truc*/ tmp =  SDL_LoadBMP(objectList[i]->objectFilename);

		int SDL_RenderCopy(SDL_Renderer * renderer,SDL_Texture * texture,const SDL_Rect * srcrect,const SDL_Rect * dstrect);
	}
}

void GameWindow::NewObject(const char* name, const char* filename, vector<int> sizeArray, vector<int> array, const char* type) {
	objectList.push_back(new GameObject(name, filename, sizeArray, array, type));
};

void GameWindow::CloseWindow() {
	SDL_Quit();
}