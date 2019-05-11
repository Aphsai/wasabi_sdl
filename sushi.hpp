#pragma once
#include "entity.hpp"
#include "texture-manager.hpp"
#include "ecs.hpp"

class Sushi : public Entity {
	Sushi(SDL_Renderer *renderer, const char* path) {
		components.push_back(new InputComponent());
		//texture = TextureManager::loadTexture(I
	}

	void update() {
		for (auto c : components) {
			c->execute(this);
		}
	}

};
