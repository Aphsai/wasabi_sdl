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
		src.x += TILESHEET_X * frameIndex;
		frameDelay++;
		if (frameDelay > currentAnimation->speed) {
			frameIndex = (frameIndex + 1) % currentAnimation->frames;
            animation_complete = (frameIndex == 0);
			frameDelay = 0;
		}
	}
}
