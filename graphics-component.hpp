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
        int lastSeen;

		void draw(Entity*);
		void addAnimation(int, SDL_Rect, int, int);
		void setAnimation(int, SDL_RendererFlip);
		void unsetAnimation();
		void update(Entity*);
	private:
		std::unordered_map<int, Animation*> animation_map;
		Animation* currentAnimation;
		SDL_Rect src;
		int frameDelay = 0;
};	
