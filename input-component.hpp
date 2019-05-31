#pragma once

#include <SDL2/SDL.h>
#include "ecs.hpp"


class InputComponent : public Component {
	public:
		bool moving_forward = false;
		bool moving_backward = false;
		bool jumping = false;
		bool looking_down = false; 
        bool fire = false;
		bool inJump = false;
        bool attack = false;

		void update(Entity* entity);
};
