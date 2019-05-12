#pragma once
#include "ecs.hpp"

class PhysicsComponent : public Component {
	public:
		const float GRAVITY = 11.81;
		float xvel = 0;
		float yvel = 0;

		void update(Entity* entity) {
			entity->xpos += xvel;
			entity->ypos += GRAVITY * GRAVITY * 0.5 * 0.15 * 0.15 + yvel * 0.15;
			if (entity->ypos < SCREEN_WIDTH / 2) {
				yvel += GRAVITY * 0.15;
			}
		}
};
