#include <iostream>
#include <math.h>
#include "collision.hpp"
#include "components.hpp"



void Collision::collisionTable(Entity* a, Entity* b, bool horizontal, bool vertical, SDL_Rect& intersection) {

	int a_type = a->getComponent<ColliderComponent>(COLLIDER_COMPONENT).type;
	int b_type = b->getComponent<ColliderComponent>(COLLIDER_COMPONENT).type;

    //std::cout << "Logging ----- " << std::endl;
    //std::cout << "Intersection Rectangle " << intersection.x << " " << intersection.y << " " << intersection.w << " " << intersection.h << std::endl;
    //std::cout << a->xpos << " " << a->ypos << std::endl;
	switch (a_type) {
		case 0: {
	        PhysicsComponent *pc = &a->getComponent<PhysicsComponent>(PHYSICS_COMPONENT);
            JumpingComponent *jc = &a->getComponent<JumpingComponent>(JUMPING_COMPONENT);
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
						} else {
							a->ypos -= intersection.h;
							pc->applyNormalForce();
                            jc->resetJump();
						}
					}
			        break;
				}
			}
		}
	}
}
