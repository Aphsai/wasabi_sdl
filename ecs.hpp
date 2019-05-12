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

		template<typename T> T& getComponent(const int c) {
			auto ptr(components[c]);
			return *static_cast<T*>(ptr);
		}

		template<typename T, typename ... Args> void addComponent(const int c, Args ... TArgs) {
			if (components[c] == nullptr) {
				components[c] = new T(TArgs...);
			}
		}

		template<typename T> void deleteComponent(const int c) {
			if (components[c] != nullptr) {
				delete components[c];
				components[c] = nullptr;
			}
		}

		float xpos, ypos;
};
