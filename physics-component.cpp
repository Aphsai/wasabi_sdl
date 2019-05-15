#include "physics-component.hpp"

PhysicsComponent::PhysicsComponent() {
	apply_normal_force = true;
}

void PhysicsComponent::update(Entity* entity) {
	entity->p_xpos = entity->xpos;
	entity->p_ypos = entity->ypos;
	entity->xpos += xvel;
	entity->ypos += GRAVITY * GRAVITY * 0.5 * TIMESTEP * TIMESTEP + yvel * TIMESTEP;
	if (apply_normal_force == false) { 
		yvel += GRAVITY * TIMESTEP;
		yvel = fmin(yvel, MAX_Y_VEL / 2); 
		yvel = fmax(yvel, -MAX_Y_VEL);
	}
}
