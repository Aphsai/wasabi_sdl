#pragma once
#include "ecs.hpp"

class PhysicsComponent : public Component {
	public:
		const float GRAVITY = 11.81;
		const float TIMESTEP = 0.15;
		const float MAX_Y_VEL = 50;

		bool apply_normal_force;
		float xvel = 0;
		float yvel = 0;
		PhysicsComponent();
		void update(Entity*);
};
