#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class TextureManager {
	public: 
		static SDL_Texture *loadTexture(const char*, SDL_Renderer*);
		static void draw(SDL_Texture*, SDL_Rect, SDL_Rect, SDL_Renderer*);
};
