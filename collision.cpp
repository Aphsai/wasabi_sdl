#include <iostream>
#include <math.h>
#include "defs.hpp"
#include "game.hpp"
#include "collision.hpp"
#include "components.hpp"

void Collision::collisionTable(Entity* a_e, Entity* b_e, bool axis, SDL_Rect& intersection) {

    a = a_e;
    b = b_e;

    horizontal = axis;

	a_c = &a->getComponent<ColliderComponent>(COLLIDER_COMPONENT);
	b_c = &b->getComponent<ColliderComponent>(COLLIDER_COMPONENT);

    left = right = top = bottom = false;

	switch (a_c->type) {
		case PLAYER: {
			switch(b_c->type) {
				case TERRAIN: {
                    determineDirection(intersection);
                    preventIntangibility(intersection);
                    if (bottom) {
                        a->getComponent<JumpingComponent>(JUMPING_COMPONENT).resetJump();
                    }
			    break;
				}
			}
		}
        break;
        case PROJECTILE: {
            switch(b_c->type) {
                case TERRAIN: {
                    if (a->mark_remove == false) {
                        a->mark_remove = true;
                        b->mark_remove = true;
                    }
                break;
                }
                case ENEMY: {
                    HealthComponent *hc = &b->getComponent<HealthComponent>(HEALTH_COMPONENT);
                    hc->receiveDamage(b, 10);
                    a->mark_remove = true;
                    break;
                }
            }
        }
        break;
        case ENEMY: {
            switch(b_c->type) {
                case TERRAIN: {
                    determineDirection(intersection);
                    preventIntangibility(intersection);
                break;
                }
            }
        }
	}
}

void Collision::determineDirection(SDL_Rect& intersection) {
    if (horizontal) {
    	if (intersection.x <= a->xpos) {
            a_c->leftCollision = true;
            left = true;
    	} else {
            a_c->rightCollision = true;
            right = true;
    	}
    } else {
    	if (intersection.y <= a->ypos) {
            a_c->topCollision = true;
            top = true;
    	} else {
            a_c->bottomCollision = true;
            bottom = true;
    	}
    }
}

void Collision::preventIntangibility(SDL_Rect& intersection) {
        PhysicsComponent *pc = &a->getComponent<PhysicsComponent>(PHYSICS_COMPONENT);
		if (left) {
			a->xpos += (intersection.w);	
		} else if(right) {
			a->xpos -= (intersection.w);
		} else if (top) {
			a->ypos += (intersection.h);
		} else if (bottom) {
			a->ypos -= (intersection.h);
			pc->applyNormalForce();
		}
}
