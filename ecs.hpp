#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include "game.hpp"

#define MAX_COMPONENTS 32
enum { INPUT_COMPONENT, GRAPHICS_COMPONENT, PHYSICS_COMPONENT, COLLIDER_COMPONENT, JUMPING_COMPONENT };

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
		std::vector<Component*> components = std::vector<Component*>(MAX_COMPONENTS, nullptr);
		bool active = true;

		int xpos = 0, ypos = 0;
		int p_xpos = 0, p_ypos = 0;

		int tag;

		virtual void update() {}
		virtual void draw() {}

		template<typename T> T& getComponent(const int c) {
			auto ptr(components[c]);
			return *static_cast<T*>(ptr);
		}
		
		template<typename T, typename ... Args> void addComponent(const int c, Args ... TArgs) {
			if (components[c] == nullptr) {
				components[c] = new T(TArgs...);
                Game::manager->addEntityToGroup(this, c);
			}
		}
		
		template<typename T> void deleteComponent(const int c) {
			if (components[c] != nullptr) {
				delete components[c];
				components[c] = nullptr;
			}
		}

		void updateComponents();
		void initComponents();
		void drawComponents();
		void generateTag();
};

namespace std
{
	template<>
	struct hash<Entity>
	{
		size_t operator()(const Entity& k) const
		{
			return hash<int>()(k.tag);
		}
	};
}
