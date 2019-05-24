#include <iostream>
#include "game.hpp"
#include "defs.hpp"
#include "projectile.hpp"
#include "input-component.hpp"
#include "physics-component.hpp"
#include "jumping-component.hpp"
#include "graphics-component.hpp"
#include "collider-component.hpp"

void InputComponent::init(Entity* entity) {
	pc = &entity->getComponent<PhysicsComponent>(PHYSICS_COMPONENT);
	gc = &entity->getComponent<GraphicsComponent>(GRAPHICS_COMPONENT);
	jc = &entity->getComponent<JumpingComponent>(JUMPING_COMPONENT);
    cc = &entity->getComponent<ColliderComponent>(COLLIDER_COMPONENT);
}

void InputComponent::handleKeypress() {
	if (Game::event.type == SDL_KEYDOWN) {
		switch (Game::event.key.keysym.sym) {
			case SDLK_a: 
				moving_backward = true;
				break;
			case SDLK_d:
				moving_forward = true;
				break;
			case SDLK_w:
				jumping = true;
				break;
			case SDLK_s:
				looking_down = true;
				break;
            case SDLK_SPACE:
                fire = true;
                break;
			} 
		}
	if (Game::event.type == SDL_KEYUP) {
		switch (Game::event.key.keysym.sym) {
			case SDLK_a: 
				moving_backward = false;
				break;
			case SDLK_d:
				moving_forward = false;
				break;
			case SDLK_w:
				jumping = false;
				break;
			case SDLK_s:
				looking_down = false;
				break;
		}
	}
}

void InputComponent::update(Entity* entity) {
	handleKeypress();	
	const int LATERAL_SPEED = 30;
    const int PROJECTILE_SPEED = TILESHEET_SIZE * SCALING;
	if (moving_forward) {
        flip = SDL_FLIP_NONE;
        if (!cc->rightCollision) {
		    pc->xvel = LATERAL_SPEED;
        }
        if (!jc->isJumping) {
            gc->setAnimation(WALK, flip);
        }
	}
	else if (moving_backward)  {
        flip = SDL_FLIP_HORIZONTAL;
        if (!cc->leftCollision) {
		    pc->xvel = -LATERAL_SPEED;
        }
        if (!jc->isJumping) {
            gc->setAnimation(WALK, flip);
        }
	}
	else {
		pc->xvel = 0;
        if (!jc->isJumping) {
            gc->setAnimation(IDLE, flip);
        }
	}

    if (fire) {
        float velocity = PROJECTILE_SPEED;
        if (flip == SDL_FLIP_HORIZONTAL) {
           velocity = -velocity; 
        }
        fire = false;
        Game::manager->addEntity(new Projectile(entity->xpos, entity->ypos, entity->tag, velocity));
    }

	if (jumping) {
        gc->setAnimation(JUMP, flip);
        if (!jc->isJumping) {
		    jc->jump();
        }
	}
}
