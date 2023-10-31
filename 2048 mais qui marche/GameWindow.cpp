#include "GameWindow.h"
#include "GameObject.h"

#include <SDL.h>
#include <SDL_image.h>
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
		SDL_Surface* image = IMG_Load("img/2.png");
		if (!image)
		{
			printf("Erreur de chargement de l'image : %s", SDL_GetError());
			cout << "Image not load";
		}
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
		SDL_RenderCopy( renderer, texture,NULL,NULL);
		SDL_RenderPresent(renderer);
}

void GameWindow::NewObject(const char* name, const char* filename, int sizeW, int sizeH, int posX, int posY, const char* type) {
	objectList.push_back(new GameObject(name, filename, sizeW, sizeH, posX, posY, type));
};

void GameWindow::LoadTextures() {

}

void GameWindow::CloseWindow() {
	SDL_Quit();
}