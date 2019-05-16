#include "physics-component.hpp"
#include "defs.hpp"
#include <iostream>
PhysicsComponent::PhysicsComponent() {
	apply_normal_force = false;
	yaccel = GRAVITY;
}

void PhysicsComponent::update(Entity* entity) {

	//std::cout << "Velocity vectors: " << xvel << " " << yvel << std::endl;
    //std::cout << "Acceleration vectors: " << xaccel << " " << yaccel << std::endl;

	entity->p_xpos = entity->xpos;
	entity->p_ypos = entity->ypos;

	entity->xpos += 0.5 * xaccel * xaccel * TIMESTEP * TIMESTEP + xvel * TIMESTEP;
	entity->ypos += 0.5 * yaccel * yaccel * TIMESTEP * TIMESTEP + yvel * TIMESTEP;

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
