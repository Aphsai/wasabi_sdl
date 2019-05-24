#include <iostream>
#include "game.hpp"
#include "graphics-component.hpp"
//#include "collider-component.hpp"
#include "texture-manager.hpp"
#include "defs.hpp"

GraphicsComponent::GraphicsComponent(SDL_Rect &r) {
	src = r;
	currentAnimation = nullptr;
	flip = SDL_FLIP_NONE;
}

void GraphicsComponent::draw(Entity* entity) {
	TextureManager::draw(src, SDL_Rect { Game::camera->xpos + entity->xpos, Game::camera->ypos + entity->ypos, src.w * SCALING, src.h * SCALING }, flip);
}

void GraphicsComponent::addAnimation(int name, SDL_Rect src, int f, int s) {
	animation_map.emplace(name, new Animation(src, f , s));
}

void GraphicsComponent::setAnimation(int name, SDL_RendererFlip f) {
	if (animation_map.find(name) != animation_map.end()) {
		currentAnimation = animation_map[name];
	}
    flip = f;
}

void GraphicsComponent::unsetAnimation() {
	currentAnimation = nullptr;
}

void GraphicsComponent::update(Entity* entity) {
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
