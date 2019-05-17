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
    
	const float LATERAL_SPEED = 30;
	if (moving_forward) {
		pc->xvel = LATERAL_SPEED;
	}
	else if (moving_backward)  {
		pc->xvel = -LATERAL_SPEED;
	}
	else {
		pc->xvel = 0;
	}

	if (jumping && !jc->isJumping) {
		jc->jump();
	}
}
