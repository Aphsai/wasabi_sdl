#pragma once
#include "ecs.hpp"

class PhysicsComponent : public Component {
	public:
		void update(Entity* entity) {
			entity->xpos += entity->xvel;
			entity->ypos += entity->yvel;
		}
};
