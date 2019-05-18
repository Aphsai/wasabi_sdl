#pragma once
#include <SDL2/SDL.h>
#include "ecs.hpp"

class ColliderComponent;

class Collision {
	public:
		void collisionTable(Entity*, Entity*, bool, SDL_Rect&);
	private:
        ColliderComponent* a_c;
        ColliderComponent* b_c;
		bool horizontal;
		bool vertical;
};
