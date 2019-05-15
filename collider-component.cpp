#include "collider-component.hpp"
#include "collision.hpp"
#include "defs.hpp"

Collision ColliderComponent::c;

ColliderComponent::ColliderComponent(int t) {
	type = t;
	collider.w = collider.h = TILESHEET_SIZE * SCALING;
}

ColliderComponent::ColliderComponent(int t, int w, int h) {
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

void ColliderComponent::hasCollision(Entity* a, Entity* b) {
	c.handleCollision(a, b);
}
