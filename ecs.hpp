#pragma once
#include <SDL2/SDL.h>
#include <vector>

class Component;
class Entity;

class Component {
	public:
		virtual void update(Entity*) {}
		virtual void draw(Entity*) {}
		virtual void init(Entity*) {}
		int id;
};

class Entity {
	public:
		std::vector<Component*> components;
		bool active = true;
		virtual void update() {}
		virtual void draw() {}

		float xpos, ypos;
		float xvel, yvel;
};
