#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager {
	public: 
		static SDL_Texture* tex;
		static void loadTexture(const char*);
		static void draw(SDL_Rect, SDL_Rect, int, SDL_RendererFlip flip);
		~TextureManager();
};
