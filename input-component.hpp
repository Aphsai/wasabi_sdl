#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "ecs.hpp"
#include "game.hpp"

class InputComponent : public Component {
	public:
		float LATERAL_SPEED = 5;
		float LONGITUDINAL_SPEED = 5;
		void update(Entity* entity) {
			if (Game::event.type == SDL_KEYDOWN) {
				switch (Game::event.key.keysym.sym) {
					case SDLK_a: 
						entity->xvel = -LATERAL_SPEED;
						break;
					case SDLK_d:
						entity->xvel = LATERAL_SPEED;
						break;
					case SDLK_w:
						entity->yvel = -LONGITUDINAL_SPEED;
						break;
					case SDLK_s:
						entity->yvel = LONGITUDINAL_SPEED;
						break;
				} 
			}
			if (Game::event.type == SDL_KEYUP) {
				switch (Game::event.key.keysym.sym) {
					case SDLK_a:
						entity->xvel = 0;
						break;
					case SDLK_d:
						entity->xvel = 0;
						break;
					case SDLK_w:
						entity->yvel = 0;
						break;
					case SDLK_s:
						entity->yvel = 0;
						break;
				}
			}
		}
};
