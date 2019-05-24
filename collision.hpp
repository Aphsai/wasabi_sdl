#pragma once
#include <SDL2/SDL.h>
#include "ecs.hpp"

class ColliderComponent;

class Collision {
	public:
		void collisionTable(Entity*, Entity*, bool, SDL_Rect&);
	private:
        void preventIntangibility(SDL_Rect&);
        void determineDirection(SDL_Rect&);

        ColliderComponent* a_c;
        ColliderComponent* b_c;

        Entity* a;
        Entity* b;

        bool left = false;
        bool right = false;
        bool top = false;
        bool bottom = false;
		bool horizontal;
};
