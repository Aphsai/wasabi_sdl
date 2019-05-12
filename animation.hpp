#pragma once
#include <SDL2/SDL.h>

struct Animation {
	SDL_Rect src;
	int index = 0;
	int frames = 0;
	int speed = 0;

	Animation(SDL_Rect r, int f, int s) {
		frames = f;
		speed = s;
		src = r;
	}
};
