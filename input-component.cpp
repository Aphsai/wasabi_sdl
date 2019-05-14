#include "input-component.hpp"

void InputComponent::init(Entity* entity) {
	pc = &entity->getComponent<PhysicsComponent>(PHYSICS_COMPONENT);
	gc = &entity->getComponent<GraphicsComponent>(GRAPHICS_COMPONENT);
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

	if (entity->ypos > SCREEN_HEIGHT / 2) {
		entity->ypos = SCREEN_HEIGHT / 2;
		pc->yvel = 0;
		gc->setAnimation(LAND);
		inJump = false;
	}
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
	if (!inJump) {
		if (jumping) {
			pc->yvel = -LONGITUDINAL_SPEED;
			gc->setAnimation(JUMP);
			inJump = true;
		}
		else pc->yvel = 0;
	}
}
