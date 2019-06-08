#include <iostream>
#include "game.hpp"
#include "graphics-component.hpp"
#include "texture-manager.hpp"
#include "defs.hpp"

GraphicsComponent::GraphicsComponent(SDL_Rect &r) {
	src = r;
	currentAnimation = nullptr;
	flip = SDL_FLIP_NONE;
}

void GraphicsComponent::draw(Entity* entity) {
	TextureManager::draw(src, SDL_Rect { Game::camera->xpos + entity->xpos, Game::camera->ypos + entity->ypos, src.w * SCALING, src.h * SCALING }, alpha, flip);
    alpha = 255;
}

void GraphicsComponent::addAnimation(int name, SDL_Rect src, int f, int s) {
	animation_map[name] = new Animation(src, f , s);
}

void GraphicsComponent::addAnimation(int name, SDL_Rect src, int f, int s, int t) {
    animation_map[name] = new Animation(src, f, s);
    animation_map[name]->type = t;
}

void GraphicsComponent::addAnimation(int name, SDL_Rect src, int f, int s, int x_off, int y_off) {
	animation_map[name] = new Animation(src, f , s);
    x_offset = x_off;
    y_offset = y_off;
}

void GraphicsComponent::setAnimation(int name, SDL_RendererFlip f) {
	if (animation_map.find(name) != animation_map.end()) {
        if (currentAnimation != nullptr && currentAnimation != animation_map[name]) {
            animation_complete = false;
            frameIndex = 0;
        }
        animationIndex = name;
		currentAnimation = animation_map[name];
	}
    flip = f;
}

void GraphicsComponent::setAnimation(int name) {
	if (animation_map.find(name) != animation_map.end()) {
        if (currentAnimation != nullptr && currentAnimation != animation_map[name]) {
            animation_complete = false;
            frameIndex = 0;
        }
        animationIndex = name;
		currentAnimation = animation_map[name];
	}
}

void GraphicsComponent::unsetAnimation() {
	currentAnimation = nullptr;
}

void GraphicsComponent::update(Entity* entity) {
	if (currentAnimation != nullptr) {
		src = currentAnimation->src;
		src.x += TILESHEET_SIZE * frameIndex;
		frameDelay++;
		if (frameDelay > currentAnimation->speed) {
            if (currentAnimation->type == LINEAR) {
			    frameIndex = (frameIndex + 1) % currentAnimation->frames;
            }
            else if (currentAnimation->type == BOUNCE) {
                frameIndex = frameIndex + 1 - bounce * 2;
                std::cout << bounce << std::endl;
                if (frameIndex == (currentAnimation->frames - 1)) bounce = true;
                else if (frameIndex == 0) bounce = false;
            }
            animation_complete = (frameIndex == 0);
			frameDelay = 0;
		}
	}
}
