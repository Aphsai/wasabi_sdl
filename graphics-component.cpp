#include <iostream>
#include "game.hpp"
#include "graphics-component.hpp"
#include "collider-component.hpp"
#include "texture-manager.hpp"
#include "defs.hpp"

GraphicsComponent::GraphicsComponent(SDL_Rect &r) {
	src = r;
	currentAnimation = nullptr;
	flip = SDL_FLIP_NONE;
}

void GraphicsComponent::draw(Entity* entity) {
	//TextureManager::draw(src, SDL_Rect { Game::camera.x + entity->xpos, Game::camera.y + entity->ypos, src.w * SCALING, src.h * SCALING }, flip)
	TextureManager::draw(src, SDL_Rect { entity->xpos, entity->ypos, src.w * SCALING, src.h * SCALING }, flip);
        ColliderComponent* c = &entity->getComponent<ColliderComponent>(COLLIDER_COMPONENT);
    if (c != nullptr) {
        SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(Game::renderer, &(entity->getComponent<ColliderComponent>(COLLIDER_COMPONENT).collider));
    }
}

void GraphicsComponent::addAnimation(const char* name, SDL_Rect src, int f, int s) {
	animations.push_back(new Animation(src, f, s));
	animation_map.emplace(name, animations.back());
}

void GraphicsComponent::setAnimation(const char* name) {
	if (animation_map.find(name) != animation_map.end()) {
		currentAnimation = animation_map[name];
	}
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
