#pragma once
#include "ecs.hpp"

class PhysicsComponent;

class JumpingComponent : public Component {
	public:
		JumpingComponent(float);
		void init(Entity*);
		void jump();

		float jumpMagnitude;
		bool isJumping;
	private:
		PhysicsComponent* pc;
};
