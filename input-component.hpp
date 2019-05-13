#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "defs.hpp"
#include "components.hpp"
#include "game.hpp"

class InputComponent : public Component {
	public:
		PhysicsComponent* pc;
		GraphicsComponent* gc;

		void init(Entity* entity) {
			pc = &entity->getComponent<PhysicsComponent>(PHYSICS_COMPONENT);
			gc = &entity->getComponent<GraphicsComponent>(GRAPHICS_COMPONENT);
		}

		bool moving_forward = false, moving_backward = false, jumping = false, looking_down = false, inJump = false;

		void update(Entity* entity) {
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
	private:
		const float LATERAL_SPEED = 5;
		const float LONGITUDINAL_SPEED = 50;
};
