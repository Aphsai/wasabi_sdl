#include <iostream>
#include "game.hpp"
#include "defs.hpp"
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
	const float LATERAL_SPEED = 30;
    SDL_RendererFlip flip;
	if (moving_forward && !cc->rightCollision) {
		pc->xvel = LATERAL_SPEED;
        flip = SDL_FLIP_NONE;
        gc->setAnimation(WALK, flip);
	}
	else if (moving_backward && !cc->leftCollision)  {
		pc->xvel = -LATERAL_SPEED;
        flip = SDL_FLIP_HORIZONTAL;
        //gc->setAnimation(WALK, flip);
	}
	else {
		pc->xvel = 0;
        gc->unsetAnimation();
	}

	if (jumping && !jc->isJumping) {
        gc->setAnimation(JUMP, flip);
		jc->jump();
	}
}
