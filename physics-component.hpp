#pragma once
#include "ecs.hpp"

class PhysicsComponent : public Component {
	public:
		const float GRAVITY = 11.81;
		const float TIMESTEP = 0.15;
		float xvel = 0;
		float yvel = 0;

		void update(Entity* entity) {
			entity->xpos += xvel;
			entity->ypos += GRAVITY * GRAVITY * 0.5 * TIMESTEP * TIMESTEP + yvel * TIMESTEP;
			yvel += GRAVITY * TIMESTEP;
		}
};
