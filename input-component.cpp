#include "input-component.hpp"

InputComponent::InputComponent() {
	id = 1;
}

void InputComponent::execute(Entity* entity) {
	switch(entity->event) {
		case SDLK_w: 
	       		entity->yvel++;
	       		break;
	       case SDLK_d:
	       		entity->xvel++;
	       		break;
 	}
}
