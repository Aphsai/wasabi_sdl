#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <unordered_map>
#include "components.hpp"
#include "animation.hpp"

class GraphicsComponent : public Component {

	public: 
		SDL_RendererFlip flip;
		GraphicsComponent(SDL_Rect&);
		void draw(Entity*);
		void addAnimation(const char*, SDL_Rect, int, int);
		void setAnimation(const char*);
		void unsetAnimation();
		void update(Entity*);
	private:
		std::vector<Animation*> animations;
		std::unordered_map<const char*, Animation*> animation_map;
		Animation* currentAnimation;
		SDL_Rect src;
		int frameDelay = 0;
};	
