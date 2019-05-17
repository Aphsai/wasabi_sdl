#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <unordered_set>

class Entity;

class EntityManager {
	public: 
		EntityManager();
		void addEntity(Entity*);
		void removeEntity(Entity*);
		void drawEntities();
		void updateEntities();
		void addEntityToGroup(Entity*, const int);
		void removeEntityFromGroup(Entity*, const int);
		std::unordered_set<Entity*> getComponentGroup(const int);

	private:
		std::vector<std::unordered_set<Entity*>> component_groups;
		std::vector<Entity*> entities;
};
