#include <iostream>
#include <math.h>
#include "defs.hpp"
#include "game.hpp"
#include "collision.hpp"
#include "components.hpp"
#include "quadtree.hpp"

void Collision::handleCollision(std::unordered_set<Entity*> entities) {

    if (quadtree == nullptr) {
        quadtree = new QuadTree(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    }
    quadtree->construct(entities);

    std::vector<QuadTree*> leaves;
    quadtree->getLeaves(leaves);

    //for (QuadTree *q : leaves) {
    //    q->clean();
    //}
    for (QuadTree* q : leaves) {
        SDL_Rect l = { q->xpos, q->ypos, q->width, q->height };
        SDL_RenderDrawRect(Game::renderer, &l);
	    for (Entity* a_e : q->entities) {
            a = a_e;

	        a_c = &a->getComponent<ColliderComponent>(COLLIDER_COMPONENT);	
            a_c->resetCollision();

            std::cout << "Checking entity " << a->tag << std::endl;

            //Resolve x-axis collisions
            a->xpos = a->n_xpos;
            //std::cout << "Updated x position " << std::endl;
	    	for (Entity* b_e: q->entities) {
                //std::cout << "assigning b_collider" << std::endl;
	            b_c = &b_e->getComponent<ColliderComponent>(COLLIDER_COMPONENT);	
	    		if (a_c->type != b_c->type) {
                    //std::cout << "differing types found" << std::endl;
                    b = b_e;
                    std::cout << "\t with entity " << b->tag << std::endl;
                    hasCollision(true);
	    		}
	    	}
            a->n_xpos = a->xpos;

            //Resolve y-axis collisions
            a->ypos = a->n_ypos;
            for (Entity* b_e: q->entities) {
	            b_c = &b_e->getComponent<ColliderComponent>(COLLIDER_COMPONENT);	
	    		if (a_c->type != b_c->type) {
                    b = b_e;
                    hasCollision(false);
	    		}
	    	}
            a->n_ypos = a->ypos;
	    }
    }
    SDL_RenderPresent(Game::renderer);
}

void Collision::hasCollision(bool x_axis) {
    SDL_Rect intersection;
    SDL_Rect a_collider = SDL_Rect { a->xpos, a->ypos, a->width, a->height };
    SDL_Rect b_collider = SDL_Rect { b->xpos, b->ypos, b->width, b->height };
	if (SDL_IntersectRect(&a_collider, &b_collider, &intersection)) {
        bool horizontal = intersection.w < intersection.h;
        //std::cout << "collision found!" << std::endl;
    void update(std::unordered_set<Entity*>);
        if (horizontal == x_axis) {
		    collisionTable(x_axis, intersection);
        }
	}
    a_c->update(a);
}

void Collision::collisionTable(bool axis, SDL_Rect& intersection) {

    horizontal = axis;
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
