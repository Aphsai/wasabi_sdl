#pragma once
#include <SDL2/SDL.h>
#include <vector>

#define MAX_COMPONENTS 32
enum { INPUT_COMPONENT, GRAPHICS_COMPONENT, PHYSICS_COMPONENT, COLLIDER_COMPONENT};

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
		int tag = -1;
		static int ENTITY_TAG_COUNTER;
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

		void updateComponents() {
			for (auto &c : components) {
				if (c != nullptr) {
					c->update(this);
				}
			}
		}

		void initComponents() {
			for (auto &c : components) {
				if (c != nullptr) {
					c->init(this);
				}
			}
				
		}

		void drawComponents() {
			for (auto &c : components) {
				if (c != nullptr) {
					c->draw(this);
				}
			}
		}

		void generateTag() {
			tag = Entity::ENTITY_TAG_COUNTER++;	
		}

		float xpos, ypos;
};

int Entity::ENTITY_TAG_COUNTER = 0;
