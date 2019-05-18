#include "physics-component.hpp"
#include "defs.hpp"
#include <iostream>

PhysicsComponent::PhysicsComponent() {
	apply_normal_force = false;
	yaccel = GRAVITY;
}

void PhysicsComponent::update(Entity* entity) {

	entity->xpos = entity->n_xpos;
	entity->ypos = entity->n_ypos;

	entity->n_xpos += static_cast<int>(0.5 * xaccel * xaccel * TIMESTEP * TIMESTEP + xvel * TIMESTEP);
	entity->n_ypos += static_cast<int>(0.5 * yaccel * yaccel * TIMESTEP * TIMESTEP + yvel * TIMESTEP);

    yvel += yaccel * TIMESTEP;
    xvel += xaccel * TIMESTEP;
    removeNormalForce();

}

void PhysicsComponent::removeNormalForce() {
    yaccel = GRAVITY;
}

void PhysicsComponent::applyNormalForce() {
    yvel = 0;
    yaccel = GRAVITY + NORMAL_FORCE;
}
