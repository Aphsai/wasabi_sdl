#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "components.hpp"
#include "defs.hpp"

class ColliderComponent : public Component {
	public:
		SDL_Rect collider;
		int tag = 0;
		const char* type;

		ColliderComponent(const char*);
		ColliderComponent(const char*, int w, int h);
		void init(Entity*);
		void update(Entity*);
		void hasCollision(ColliderComponent);
};
