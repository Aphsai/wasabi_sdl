#include "entity-manager.hpp"
#include <iostream>
#include "ecs.hpp"

EntityManager::EntityManager() {
	component_groups = std::vector<std::unordered_set<Entity*>>(MAX_COMPONENTS);
	entities = std::vector<Entity*>();
}

void EntityManager::addEntity(Entity* entity) {
	entities.push_back(entity);
}

void EntityManager::removeEntity(Entity* entity) {
	for (int x = 0; x < entities.size(); x++) {
		if (entities[x] == entity) {
			delete entities[x];
			entities[x] = nullptr;
			break;
		}
	}
}

void EntityManager::addEntityToGroup(Entity* entity, const int COMPONENT) {
	component_groups[COMPONENT].insert(entity);
}

void EntityManager::removeEntityFromGroup(Entity* entity, const int COMPONENT) {
	component_groups[COMPONENT].erase(entity);	
}

std::unordered_set<Entity*> EntityManager::getComponentGroup(const int COMPONENT) {
	return component_groups[COMPONENT];
}

void EntityManager::updateEntities() {
	for (Entity* entity : entities) {
		if (entity != nullptr) {
			entity->update();
		}
	}
}

void EntityManager::drawEntities() { 
	for (Entity* entity : entities) {
		if (entity != nullptr) {
			entity->draw();
		}
	}
}
