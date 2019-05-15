#include "jumping-component.hpp"
#include "physics-component.hpp"

JumpingComponent::JumpingComponent(float jm) {
	jumpMagnitude = jm;
}

void JumpingComponent::jump() {
	pc->yvel = jumpMagnitude;
	isJumping = true;
}

void JumpingComponent::init(Entity* entity) {
	entity->addComponent<PhysicsComponent>(PHYSICS_COMPONENT);
	pc = &entity->getComponent<PhysicsComponent>(PHYSICS_COMPONENT);
}

