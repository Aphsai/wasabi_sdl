#pragma once
#include "ecs.hpp"

class PhysicsComponent;

class JumpingComponent : public Component {
	public:
		JumpingComponent(float);
		void init(Entity*);
		void jump();
        void resetJump();

		float jumpMagnitude;
		bool isJumping;
	private:
		PhysicsComponent* pc;
};
