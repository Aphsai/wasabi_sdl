#include <iostream>
#include <math.h>
#include "defs.hpp"
#include "game.hpp"
#include "collision.hpp"
#include "components.hpp"
#include "quadtree.hpp"

void Collision::handleCollision(std::unordered_set<Entity*> entities) {

    if (quadtree == nullptr) {
        quadtree = new QuadTree(0, 0, MAP_SIZE * TILESHEET_SIZE * SCALING, MAP_SIZE * TILESHEET_SIZE * SCALING, 0);
    }

    std::vector<QuadTree*> leaves;

    quadtree->construct(entities);
    quadtree->getLeaves(leaves);

    std::unordered_map<int, std::unordered_set<int>> collided_with;
    for (QuadTree* q : leaves) {
        for (Entity* a_e : q->entities) {
            a = a_e;
            a_c = &a->getComponent<ColliderComponent>(COLLIDER_COMPONENT);	

            //Resolve x-axis collisions
            a->xpos = a->n_xpos;
            for (Entity* b_e: q->entities) {
                b_c = &b_e->getComponent<ColliderComponent>(COLLIDER_COMPONENT);
                if (a_c->type != b_c->type && collided_with[a->tag].find(b_e->tag) == collided_with[a->tag].end()) {
                    b = b_e;
                    hasCollision(true, collided_with);
                }
            }
            a->n_xpos = a->xpos;

            //Resolve y-axis collisions
            a->ypos = a->n_ypos;
            for (Entity* b_e: q->entities) {
                b_c = &b_e->getComponent<ColliderComponent>(COLLIDER_COMPONENT);
                if (a_c->type != b_c->type && collided_with[a->tag].find(b_e->tag) == collided_with[a->tag].end()) {
                    b = b_e;
                    hasCollision(false, collided_with);
                }
            }
            a->n_ypos = a->ypos;
        }
    }
    for (QuadTree *q : leaves) {
        q->clean();
    }
    quadtree->combine();
}

void Collision::hasCollision(bool x_axis, std::unordered_map<int, std::unordered_set<int>>& collided_with) {
    SDL_Rect intersection;
    SDL_Rect a_collider = SDL_Rect { a->xpos, a->ypos, a->width, a->height };
    SDL_Rect b_collider = SDL_Rect { b->xpos, b->ypos, b->width, b->height };

    if (SDL_IntersectRect(&a_collider, &b_collider, &intersection)) {
        bool horizontal = intersection.w < intersection.h;
        if (horizontal == x_axis) {
            collided_with[a->tag].insert(b->tag);
            collisionTable(x_axis, intersection);
        }
    }
}

void Collision::collisionTable(bool axis, SDL_Rect& intersection) {

    horizontal = axis;
    left = right = top = bottom = false;

    switch (a_c->type) {
        case PLAYER: {
            switch(b_c->type) {
                case TERRAIN: {
                    PhysicsComponent *pc = &a->getComponent<PhysicsComponent>(PHYSICS_COMPONENT);
                    determineDirection(intersection);
                    preventIntangibility(intersection);
                    if (bottom) {
                        JumpingComponent *jc = &a->getComponent<JumpingComponent>(JUMPING_COMPONENT);
                        if (!jc->isJumping) {
                            pc->yvel = 0;
                        }
                        jc->resetJump();
                    }
                    break;
                }
                case ENEMY: {
                    HealthComponent* hc = &a->getComponent<HealthComponent>(HEALTH_COMPONENT);    
                    hc->receiveDamage(a, 5);
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
                    HealthComponent* hc = &b->getComponent<HealthComponent>(HEALTH_COMPONENT);
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

