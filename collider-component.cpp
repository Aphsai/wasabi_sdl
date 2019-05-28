#include <iostream>
#include "collider-component.hpp"
#include "collision.hpp"
#include "defs.hpp"

//Collision ColliderComponent::c;

ColliderComponent::ColliderComponent(int t) {
	type = t;
}


void ColliderComponent::update(Entity *entity) {
    leftCollision = rightCollision = topCollision = bottomCollision = false;
}
