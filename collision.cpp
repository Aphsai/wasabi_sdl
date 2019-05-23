#include <iostream>
#include <math.h>
#include "defs.hpp"
#include "game.hpp"
#include "collision.hpp"
#include "components.hpp"

void Collision::collisionTable(Entity* a, Entity* b, bool horizontal, SDL_Rect& intersection) {

	a_c = &a->getComponent<ColliderComponent>(COLLIDER_COMPONENT);
	b_c = &b->getComponent<ColliderComponent>(COLLIDER_COMPONENT);

    //Draw collision intersections
    //SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
    //SDL_RenderFillRect(Game::renderer, &intersection);
    //SDL_RenderPresent(Game::renderer);
    //std::cout << "Collision" << std::endl;
    //std::cout << "------------------------" << std::endl;
    //std::cout << "Entities : " << a->tag << " " << b->tag << std::endl;
    //std::cout << "Intersection : " << intersection.w << " " << intersection.h << " " << intersection.x << " " << intersection.y << std::endl;
    //std::cout << "------------------------" << std::endl;

	switch (a_c->type) {
		case PLAYER: {
	        PhysicsComponent *pc = &a->getComponent<PhysicsComponent>(PHYSICS_COMPONENT);
            JumpingComponent *jc = &a->getComponent<JumpingComponent>(JUMPING_COMPONENT);
			switch(b_c->type) {
				case TERRAIN: {
					if (horizontal) {
						if (intersection.x <= a->xpos) {
							a->xpos += (intersection.w);	
                            a_c->leftCollision = true;
						} else {
							a->xpos -= (intersection.w);
                            a_c->rightCollision = true;
						}
					} else {
						if (intersection.y <= a->ypos) {
							a->ypos += (intersection.h);
                            a_c->topCollision = true;
						} else {
							a->ypos -= (intersection.h);
                            jc->resetJump();
							pc->applyNormalForce();
                            a_c->bottomCollision = true;
						}
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
                }
            }
        }
	}
}
