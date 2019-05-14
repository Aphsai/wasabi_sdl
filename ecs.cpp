#include "ecs.hpp"

void Entity::updateComponents() {
	for (auto &c : components) {
		if (c != nullptr) {
			c->update(this);
		}
	}
}

void Entity::initComponents() {
	for (auto &c : components) {
		if (c != nullptr) {
			c->init(this);
		}
	}
}
void Entity::drawComponents() {
	for (auto &c : components) {
		if (c != nullptr) {
			c->draw(this);
		}
	}
}
void Entity::generateTag() {
	static int entity_tag_counter = 0;
	tag = entity_tag_counter++;	
}
