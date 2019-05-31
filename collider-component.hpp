#pragma once
#include "ecs.hpp"
#include <SDL2/SDL.h>

class ColliderComponent : public Component {
	public:
		SDL_Rect collider;
		int type;
        int x_offset = 0;
        int y_offset = 0;

        bool leftCollision = false;
        bool rightCollision = false;
        bool topCollision = false;
        bool bottomCollision = false;

        ColliderComponent(int);
        ColliderComponent(int, int, int);
        void init(Entity*);
		void update(Entity*);
        void draw(Entity*);
};
