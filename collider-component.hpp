#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "components.hpp"
#include "defs.hpp"

class ColliderComponent : public Component {
	public:
		SDL_Rect collider;
		int tag = 0;

		ColliderComponent(SDL_Rect c) {
			collider = c;	
		}

		void init(Entity *entity) {
			tag = entity->tag;
		}

		void update(Entity *entity) {
			collider = SDL_Rect { entity->xpos, entity->ypos, TILESHEET_SIZE, TILESHEET_SIZE };
		}

		void hasCollision(ColliderComponent a) {
			if (SDL_HasIntersection(&a.collider, &collider)) {
				std::cout << a.tag << " intersection  " << tag << std::endl;
			}
		}
};
