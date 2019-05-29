#include <iostream>
#include "collider-component.hpp"
#include "collision.hpp"
#include "game.hpp"
#include "defs.hpp"

//Collision ColliderComponent::c;

ColliderComponent::ColliderComponent(int t) {
	type = t;
}

void ColliderComponent::draw(Entity* entity) {
    SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
    SDL_Rect ent = {Game::camera->xpos + entity->xpos, Game::camera->ypos + entity->ypos, entity->width, entity->height };
    SDL_RenderDrawRect(Game::renderer, &ent);
}

void ColliderComponent::update(Entity *entity) {
    leftCollision = rightCollision = topCollision = bottomCollision = false;
}
