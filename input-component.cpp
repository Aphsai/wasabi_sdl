#include <iostream>
#include "game.hpp"
#include "defs.hpp"
#include "input-component.hpp"

void InputComponent::update(Entity* entity) {
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
            case SDLK_h:
                attack = true;
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
