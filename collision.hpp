#pragma once
#include "components.hpp"

class Collision {
	public:
		void handleCollision(Entity*, Entity*);
	private:
		PhysicsComponent* pc;
		bool horizontal;
		bool vertical;
		SDL_Rect intersection;
		void collisionTable(Entity*, Entity*);
};
