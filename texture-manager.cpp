#include "texture-manager.hpp"


SDL_Texture* TextureManager::loadTexture(const char* path, SDL_Renderer *renderer) {
	IMG_Init(IMG_INIT_PNG);
	SDL_Texture *tex = NULL;
	SDL_Surface *loadedSurface = IMG_Load(path);

	tex = SDL_CreateTextureFromSurface(renderer, loadedSurface);


	SDL_FreeSurface(loadedSurface);
	IMG_Quit();

	return tex;
}

void TextureManager::draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest, SDL_Renderer *renderer) {
	SDL_RenderCopy(renderer, tex, &src, &dest);
}
