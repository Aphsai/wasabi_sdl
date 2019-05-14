#include "collider-component.hpp"
#include "game.hpp"

ColliderComponent::ColliderComponent(const char* t) {
	type = t;
	collider.w = collider.h = TILESHEET_SIZE * SCALING;
}

ColliderComponent::ColliderComponent(const char* t, int w, int h) {
	type = t;
	collider.w = w;
	collider.h = h;
}

void ColliderComponent::init(Entity *entity){
	tag = entity->tag;
	collider.x = entity->xpos;
	collider.y = entity->ypos;
}

void ColliderComponent::update(Entity *entity) {
	collider.x = entity->xpos;
	collider.y = entity->ypos;
}

void ColliderComponent::hasCollision(ColliderComponent a) {
	if (SDL_HasIntersection(&a.collider, &collider)) {
		std::cout << a.tag << " intersection  " << tag << std::endl;
	}
}
