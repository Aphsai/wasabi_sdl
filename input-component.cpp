#include <iostream>
#include "game.hpp"
#include "defs.hpp"
#include "input-component.hpp"
#include "physics-component.hpp"
#include "jumping-component.hpp"
#include "graphics-component.hpp"

void InputComponent::init(Entity* entity) {
	pc = &entity->getComponent<PhysicsComponent>(PHYSICS_COMPONENT);
	gc = &entity->getComponent<GraphicsComponent>(GRAPHICS_COMPONENT);
	jc = &entity->getComponent<JumpingComponent>(JUMPING_COMPONENT);
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

	if (moving_forward) {
		pc->xvel = LATERAL_SPEED;
		if (!inJump)
			gc->setAnimation(WALK);
	}
	else if (moving_backward) pc->xvel = -LATERAL_SPEED;
	else {
		gc->unsetAnimation();
		pc->xvel = 0;
	}
	if (!jc->isJumping) {
		jc->jump();
		gc->setAnimation(JUMP);
	}
	else pc->yvel = 0;
}
