#pragma once
#include <SDL2/SDL.h>
#include "ecs.hpp"

class Collision {
	public:
		void collisionTable(Entity*, Entity*, bool, bool, SDL_Rect&);
	private:
		bool horizontal;
		bool vertical;
};
