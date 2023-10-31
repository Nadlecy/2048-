#include "GameWindow.h"
#include "GameObject.h"

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <map>
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
		SDL_RenderCopy( renderer, textureList["secondaryBG"], NULL, NULL);
		SDL_RenderPresent(renderer);
		SDL_Delay(4500);

		const SDL_Rect* srcrect;

		const SDL_Rect* dstrect;

		SDL_RenderCopy(renderer, textureList["mainbg"], srcrect, dstrect);
		SDL_RenderPresent(renderer);
}

void GameWindow::NewObject(const char* name, const char* filename, int sizeW, int sizeH, int posX, int posY, const char* type) {
	objectList.push_back(new GameObject(name, filename, sizeW, sizeH, posX, posY, type));
};

void GameWindow::LoadTextures() {
	textureList["2"] = SDL_CreateTextureFromSurface(renderer, IMG_Load("img/2.png"));
	textureList["4"] = SDL_CreateTextureFromSurface(renderer, IMG_Load("img/4.png"));
	textureList["8"] = SDL_CreateTextureFromSurface(renderer, IMG_Load("img/8.png"));
	textureList["16"] = SDL_CreateTextureFromSurface(renderer, IMG_Load("img/16.png"));
	textureList["32"] = SDL_CreateTextureFromSurface(renderer, IMG_Load("img/32.png"));
	textureList["64"] = SDL_CreateTextureFromSurface(renderer, IMG_Load("img/64.png"));
	textureList["128"] = SDL_CreateTextureFromSurface(renderer, IMG_Load("img/128.png"));
	textureList["256"] = SDL_CreateTextureFromSurface(renderer, IMG_Load("img/256.png"));
	textureList["512"] = SDL_CreateTextureFromSurface(renderer, IMG_Load("img/512.png"));
	textureList["1024"] = SDL_CreateTextureFromSurface(renderer, IMG_Load("img/1024.png"));
	textureList["2048"] = SDL_CreateTextureFromSurface(renderer, IMG_Load("img/2048.png"));
	textureList["mainBG"] = SDL_CreateTextureFromSurface(renderer, IMG_Load("img/fond-jeu.png"));
	textureList["secondaryBG"] = SDL_CreateTextureFromSurface(renderer, IMG_Load("img/fond-side.jpg"));
}

void GameWindow::CloseWindow() {
	SDL_Quit();
}