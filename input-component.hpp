#pragma once

#include <SDL2/SDL.h>
#include "ecs.hpp"

class PhysicsComponent;
class GraphicsComponent;
class JumpingComponent;
class ColliderComponent;

class InputComponent : public Component {
	public:
		bool moving_forward = false;
		bool moving_backward = false;
		bool jumping = false;
		bool looking_down = false; 
		bool inJump = false;

		void init(Entity* entity);
		void handleKeypress();
		void update(Entity* entity);
			
	private:
		PhysicsComponent* pc;
		GraphicsComponent* gc;
		JumpingComponent* jc;
        ColliderComponent* cc;
};
