#pragma once
#include <SDL2/SDL.h>
#include <vector>

#define MAX_COMPONENTS 32
enum { INPUT_COMPONENT, GRAPHICS_COMPONENT, PHYSICS_COMPONENT };

class Component;
class Entity;

class Component {
	public:
		virtual void update(Entity*) {}
		virtual void draw(Entity*) {}
		virtual void init(Entity*) {}
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
