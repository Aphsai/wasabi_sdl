#pragma once
#include "ecs.hpp"
#include <SDL2/SDL.h>

class ColliderComponent : public Component {
	public:
		SDL_Rect collider;
		int type;

        bool leftCollision = false;
        bool rightCollision = false;
        bool topCollision = false;
        bool bottomCollision = false;

		ColliderComponent(int);
		void update(Entity*);
};
