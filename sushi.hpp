#pragma once
#include <iostream>
#include "defs.hpp"
#include "input-component.hpp"
#include "graphics-component.hpp"
#include "physics-component.hpp"

class Sushi : public Entity {
	public:
		Sushi() {
			components.push_back(new InputComponent());
			components.push_back(new GraphicsComponent(SDL_Rect { 19 * TILESHEET_SIZE, 8 * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE }));
			components.push_back(new PhysicsComponent());
		}

		void update() {
			for (auto &c : components) {
				c->update(this);
			}
		}

		void draw() {
			for (auto &c : components) {
				c->draw(this);
			}
		}

		void handleA() {
			std::cout << "Handling A" << std::endl;
		}

};
