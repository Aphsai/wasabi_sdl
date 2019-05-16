#pragma once
#include "ecs.hpp"

class PhysicsComponent : public Component {
	public:
		const float TIMESTEP = 0.15;
		const float TERMINAL_VELOCITY = 50;

		bool apply_normal_force;

		float xvel = 0;
		float yvel = 0;
        float xaccel = 0;
        float yaccel = 0;

		PhysicsComponent();
		void update(Entity*);
        void applyNormalForce();
        void removeNormalForce();
};
