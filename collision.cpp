#include <iostream>
#include <math.h>
#include "collision.hpp"
#include "jumping-component.hpp"

void Collision::handleCollision(Entity* a, Entity* b) {
	SDL_Rect a_rect = a->getComponent<ColliderComponent>(COLLIDER_COMPONENT).collider;	
	SDL_Rect b_rect = b->getComponent<ColliderComponent>(COLLIDER_COMPONENT).collider;	
	pc = &a->getComponent<PhysicsComponent>(PHYSICS_COMPONENT);

	if (SDL_IntersectRect(&a_rect, &b_rect, &intersection)) {
		std::cout << "Intersection between : " << a->tag << " " << b->tag << std::endl;
		horizontal = intersection.w <= intersection.h;
		vertical = intersection.h < intersection.w;
		collisionTable(a, b);
	} else {
		if (pc != nullptr) {
			std::cout << "No collision found" << std::endl;
		}
	}
}

void Collision::collisionTable(Entity* a, Entity* b) {

	int a_type = a->getComponent<ColliderComponent>(COLLIDER_COMPONENT).type;
	int b_type = b->getComponent<ColliderComponent>(COLLIDER_COMPONENT).type;


	//std::cout << "Handling collision between: " << a_type << " " << b_type << std::endl;
	
	if (pc != nullptr) {
		std::cout << "Velocity vectors: " << pc->xvel << " " << pc->yvel << std::endl;
	}

	switch (a_type) {
		case 0: {
			switch(b_type) {
				case 1: {
						if (horizontal) {
							if (intersection.x <= a->xpos) {
								a->xpos += intersection.w;	
							} else {
								a->xpos -= intersection.w;
							}
						} else {
							if (intersection.y <= a->ypos) {
								a->ypos += intersection.h;
								std::cout << "Top Collision" << std::endl;
								pc->apply_normal_force = false;
							} else {
								a->ypos -= intersection.h;
								std::cout << "Bottom Collision" << std::endl;
								a->getComponent<JumpingComponent>(JUMPING_COMPONENT).isJumping = false;
							}
						}
					}
			}
			break;
		}
	}
	horizontal = vertical = false;
}
