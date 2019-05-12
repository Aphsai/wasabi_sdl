#pragma once
#include <iostream>
#include "defs.hpp"
#include "input-component.hpp"
#include "graphics-component.hpp"
#include "physics-component.hpp"

class Sushi : public Entity {
	public:
		const int SPRITESHEET_LOCATION_X = 18;
		const int SPRITESHEET_LOCATION_Y = 9;

		Sushi() {
			xpos = SCREEN_WIDTH / 2;
			ypos = SCREEN_HEIGHT / 2;

			components = std::vector<Component*>(MAX_COMPONENTS, nullptr);

			//components[INPUT_COMPONENT] = new InputComponent();
			addComponent<InputComponent>(INPUT_COMPONENT);
			addComponent<GraphicsComponent>(GRAPHICS_COMPONENT, SDL_Rect { SPRITESHEET_LOCATION_X * TILESHEET_SIZE, SPRITESHEET_LOCATION_Y * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE });
			components[PHYSICS_COMPONENT] = new PhysicsComponent();
			
			init();
			addAnimations();
		}

		void addAnimations() {
			GraphicsComponent* gc = &getComponent<GraphicsComponent>(GRAPHICS_COMPONENT);
			gc->addAnimation(WALK, SDL_Rect { SPRITESHEET_LOCATION_X * TILESHEET_SIZE, SPRITESHEET_LOCATION_Y * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE }, 3, 15);
		}

		void init() {
			for (auto &c : components) {
				if (c != nullptr) {
					c->init(this);
				}
			}
		}

		

		void update() {
			for (auto &c : components) {
				if (c != nullptr) {
					c->update(this);
				}
			}
		}

		void draw() {
			for (auto &c : components) {
				if (c != nullptr) {
					c->draw(this);
				}
			}
		}

		~Sushi() {
			components.clear();
		}

};
