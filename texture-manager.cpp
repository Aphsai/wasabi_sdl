#include "texture-manager.hpp"
#include "game.hpp"
#include <iostream>

SDL_Texture* TextureManager::tex = nullptr;

void TextureManager::loadTexture(const char* path) {
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface *loadedSurface = IMG_Load(path);
	if (loadedSurface < 0) {
		
	}

	TextureManager::tex = SDL_CreateTextureFromSurface(Game::renderer, loadedSurface);
	if (tex < 0) {
		
	}
	SDL_FreeSurface(loadedSurface);
	IMG_Quit();
	
}

void TextureManager::draw(SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip) {
	SDL_RenderCopyEx(Game::renderer, TextureManager::tex, &src, &dest, NULL, NULL, flip);
}

TextureManager::~TextureManager() {
	delete tex;
}
