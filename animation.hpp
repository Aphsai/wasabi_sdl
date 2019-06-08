#pragma once
#include <SDL2/SDL.h>
#include "defs.hpp"

struct Animation {
    
	SDL_Rect src;
	int index = 0;
	int frames = 0;
	int speed = 0;
    int type = LINEAR;

	Animation(SDL_Rect r, int f, int s) {
		frames = f;
		speed = s;
		src = r;
	}

};
