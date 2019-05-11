#pragma once
#include "SDL2/SDL.h"
#include "texture-manager.hpp"
#include <vector>
#include "components.hpp"

class Entity {
	public:
		std::vector<Component*> components;
		SDL_Renderer *renderer;
		SDL_Texture *texture;

	private:
		float xpos, ypos;
		float xvel, yvel;

};
