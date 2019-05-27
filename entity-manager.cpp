#include <iostream>
#include "entity-manager.hpp"
#include "game.hpp"
#include "defs.hpp"
#include "ecs.hpp"

EntityManager::EntityManager() {
	component_groups = std::vector<std::unordered_set<Entity*>>(MAX_COMPONENTS);
	entities = std::unordered_set<Entity*>();
}

void EntityManager::addEntity(Entity* entity) {
	entities.insert(entity);
}

void EntityManager::refreshEntities() {
    for (auto it = entities.begin(); it != entities.end(); it++) {
        if ((*it)->mark_remove == true) {
            for (int x = 0; x < component_groups.size(); x++) {
                component_groups[x].erase(*it);
            }
            delete (*it);
            it = entities.erase(it);
        } else {
            if (Game::camera->xpos + (*it)->xpos > SCREEN_WIDTH || Game::camera->ypos + (*it)->ypos > SCREEN_HEIGHT) {
                (*it)->mark_active = false;
            } else {
                (*it)->mark_active = true;
            }
        }
    }
}

void EntityManager::addEntityToGroup(Entity* entity, const int COMPONENT) {
	component_groups[COMPONENT].insert(entity);
}

void EntityManager::removeEntityFromGroup(Entity* entity, const int COMPONENT) {
	int a = component_groups[COMPONENT].erase(entity);
}

std::unordered_set<Entity*> EntityManager::getComponentGroup(const int COMPONENT) {
	return component_groups[COMPONENT];
}

void EntityManager::updateEntities() {
	for (Entity* entity : entities) {
		if (entity != nullptr && entity->mark_active && !entity->mark_remove) {
			entity->priority_update();
		}
	}
	for (Entity* entity : entities) {
		if (entity != nullptr && entity->mark_active && !entity->mark_remove) {
			entity->update();
		}
	}
}

void EntityManager::drawEntities() { 
	for (Entity* entity : entities) {
		if (entity != nullptr && entity->mark_active == true && !entity->mark_remove) {
			entity->draw();
		}
	}
}
