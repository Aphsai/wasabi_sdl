#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <unordered_map>
#include "ecs.hpp"
#include "animation.hpp"

class GraphicsComponent : public Component {
	public: 
		SDL_Rect src;
		SDL_RendererFlip flip;
		std::vector<Animation*> animations;
		std::unordered_map<const char*, Animation*> animation_map;
		Animation* currentAnimation;

		int frameDelay = 0;

		GraphicsComponent(SDL_Rect&);
		void draw(Entity*);
		void addAnimation(const char*, SDL_Rect, int, int);
		void setAnimation(const char*);
		void unsetAnimation();
		void update(Entity*);
};
