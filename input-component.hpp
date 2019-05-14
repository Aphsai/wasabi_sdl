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

		bool moving_forward = false;
		bool moving_backward = false;
		bool jumping = false;
		bool looking_down = false; 
		bool inJump = false;

		void init(Entity* entity);
		void handleKeypress();
		void update(Entity* entity);
			
	private:
		const float LATERAL_SPEED = 5;
		const float LONGITUDINAL_SPEED = 50;
};
