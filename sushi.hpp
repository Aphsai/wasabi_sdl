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
			components[INPUT_COMPONENT] = new InputComponent();
			components[GRAPHICS_COMPONENT] = new GraphicsComponent(SDL_Rect { SPRITESHEET_LOCATION_X * TILESHEET_SIZE, SPRITESHEET_LOCATION_Y * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE });
			components[PHYSICS_COMPONENT] = new PhysicsComponent();
		}

		void update() {
			for (auto &c : components) {
				if (c != nullptr) {
					c->update(this);
				}
			}
		}

		~Sushi() {
			components.clear();
		}

		void draw() {
			components[GRAPHICS_COMPONENT]->draw(this);
		}
};
