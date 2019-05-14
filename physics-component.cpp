#include "physics-component.hpp"

PhysicsComponent::PhysicsComponent() {
}

void PhysicsComponent::update(Entity* entity) {
	entity->xpos += xvel;
	entity->ypos += GRAVITY * GRAVITY * 0.5 * TIMESTEP * TIMESTEP + yvel * TIMESTEP;
	yvel += GRAVITY * TIMESTEP;
}
