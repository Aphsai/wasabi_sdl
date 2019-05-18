#include <iostream>
#include <math.h>
#include "defs.hpp"
#include "collision.hpp"
#include "components.hpp"

void Collision::collisionTable(Entity* a, Entity* b, bool horizontal, SDL_Rect& intersection) {

	a_c = &a->getComponent<ColliderComponent>(COLLIDER_COMPONENT);
	b_c = &b->getComponent<ColliderComponent>(COLLIDER_COMPONENT);

	switch (a_c->type) {
		case PLAYER: {
	        PhysicsComponent *pc = &a->getComponent<PhysicsComponent>(PHYSICS_COMPONENT);
            JumpingComponent *jc = &a->getComponent<JumpingComponent>(JUMPING_COMPONENT);
			switch(b_c->type) {
				case TERRAIN: {
					if (horizontal) {
						if (intersection.x <= a->xpos) {
							a->xpos += intersection.w + 1;	
                            a_c->leftCollision = true;
						} else {
							a->xpos -= intersection.w - 1;
                            a_c->rightCollision = true;
						}
					} else {
						if (intersection.y <= a->ypos) {
							a->ypos += intersection.h + 1;
                            a_c->topCollision = true;
						} else {
							a->ypos -= intersection.h - 1;
							pc->applyNormalForce();
                            jc->resetJump();
                            a_c->bottomCollision = true;
						}
					}
			        break;
				}
			}
		}
	}
}
