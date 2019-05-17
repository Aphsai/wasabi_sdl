#include "jumping-component.hpp"
#include "physics-component.hpp"
#include <iostream>

JumpingComponent::JumpingComponent(float jm) {
	jumpMagnitude = jm;
}

void JumpingComponent::resetJump() {
    isJumping = false;
}

void JumpingComponent::jump() {
    
    pc->removeNormalForce();
	pc->yvel = -jumpMagnitude;
	isJumping = true;
}

void JumpingComponent::init(Entity* entity) {
	pc = &entity->getComponent<PhysicsComponent>(PHYSICS_COMPONENT);
}

