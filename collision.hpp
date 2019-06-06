#pragma once
#include <SDL2/SDL.h>
#include <set>
#include <unordered_map>
#include "ecs.hpp"

class ColliderComponent;
class QuadTree;

class Collision {

	public:
    	void collisionTable(bool, SDL_Rect&);
        void handleCollision(std::unordered_set<Entity*>);
        void hasCollision(bool, std::unordered_map<int, std::unordered_set<int>>&);
        QuadTree* quadtree = nullptr;

	private:
        void preventIntangibility(SDL_Rect&);
        void determineDirection(SDL_Rect&);

        ColliderComponent* a_c;
        ColliderComponent* b_c;

        Entity* a;
        Entity* b;

        bool left = false;
        bool right = false;
        bool top = false;
        bool bottom = false;
    	bool horizontal = false;
};
