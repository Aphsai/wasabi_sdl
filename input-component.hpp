#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "ecs.hpp"
#include "game.hpp"

class InputComponent : public Component {
	public:
		float LATERAL_SPEED = 5;
		float LONGITUDINAL_SPEED = 5;
		bool moving_forward = false, moving_backward = false, jumping = false, looking_down = false;
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

			if (moving_forward) entity->xvel = LATERAL_SPEED;
			else if (moving_backward) entity->xvel = -LATERAL_SPEED;
			else entity->xvel = 0;
			if (jumping) entity->yvel = -LONGITUDINAL_SPEED;
			else if (looking_down) entity->yvel = LONGITUDINAL_SPEED;
			else entity->yvel = 0;
		}
};
