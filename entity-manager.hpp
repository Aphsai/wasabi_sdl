#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <unordered_set>

class Entity;

class EntityManager {
	public: 
		EntityManager();
        ~EntityManager();
		void addEntity(Entity*);
        void refreshEntities();
		void drawEntities();
		void updateEntities();
		void addEntityToGroup(Entity*, const int);
		void removeEntityFromGroup(Entity*, const int);
		std::unordered_set<Entity*> getComponentGroup(const int);

	private:
		std::vector<std::unordered_set<Entity*>> component_groups;
		std::unordered_set<Entity*> entities;
};
