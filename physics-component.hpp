#pragma once
#include "ecs.hpp"

class PhysicsComponent : public Component {
	public:
		const float GRAVITY = -9.81;

		void update(Entity* entity) {
			entity->xpos += entity->xvel;
			entity->ypos += GRAVITY * GRAVITY * 0.5 + entity->yvel;
			entity->yvel += GRAVITY;
		}
};
