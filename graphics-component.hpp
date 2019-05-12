#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <unordered_map>
#include "defs.hpp"
#include "ecs.hpp"
#include "texture-manager.hpp"
#include "animation.hpp"

class GraphicsComponent : public Component {
	public: 
		SDL_Rect src;
		SDL_RendererFlip flip = SDL_FLIP_NONE;
		std::vector<Animation*> animations;
		std::unordered_map<const char*, Animation*> animation_map;
		Animation* currentAnimation = nullptr;

		int frameDelay = 0;

		GraphicsComponent(SDL_Rect &r) {
			src = r;
		}

		void draw(Entity* entity) override {
			TextureManager::draw(src, SDL_Rect {entity->xpos, entity->ypos, src.w * SCALING, src.h * SCALING}, flip);
		}

		void addAnimation(const char* name, SDL_Rect src, int f, int s) {
			std::cout << "Animation " << name << " added!" << std::endl;
			animations.push_back(new Animation(src, f, s));
			animation_map.emplace(name, animations.back());
		}

		void setAnimation(const char* name) {
			if (animation_map.find(name) != animation_map.end()) {
				currentAnimation = animation_map[name];
			}
		}

		void unsetAnimation() {
			currentAnimation = nullptr;
		}

		void update(Entity* entity) override {
			if (currentAnimation != nullptr) {
				src = currentAnimation->src;
				src.x += TILESHEET_SIZE * currentAnimation->index;
				frameDelay++;
				if (frameDelay > currentAnimation->speed) {
					currentAnimation->index = (currentAnimation->index + 1) % currentAnimation->frames;
					frameDelay = 0;
				}
			}
		}
};
