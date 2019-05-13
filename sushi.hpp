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

		Sushi(int x, int y) {

			xpos = x;
			ypos = y;

			generateTag();
			init();
			addAnimations();
		}

		void addAnimations() {
			GraphicsComponent* gc = &getComponent<GraphicsComponent>(GRAPHICS_COMPONENT);
			gc->addAnimation(WALK, SDL_Rect { SPRITESHEET_LOCATION_X * TILESHEET_SIZE, SPRITESHEET_LOCATION_Y * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE }, 3, 15);
			gc->addAnimation(JUMP, SDL_Rect { 21 * TILESHEET_SIZE, 9 * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE }, 1, 1);
			gc->addAnimation(LAND, SDL_Rect { 22 * TILESHEET_SIZE, 9 * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE }, 2, 10);
		}

		void init() {
			std::cout << "Sushi tag: " << tag << std::endl;

			addComponent<InputComponent>(INPUT_COMPONENT);
			addComponent<GraphicsComponent>(GRAPHICS_COMPONENT, SDL_Rect { SPRITESHEET_LOCATION_X * TILESHEET_SIZE, SPRITESHEET_LOCATION_Y * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE });
			addComponent<PhysicsComponent>(PHYSICS_COMPONENT);
			addComponent<ColliderComponent>(COLLIDER_COMPONENT, SDL_Rect { xpos, ypos, TILESHEET_SIZE * SCALING, TILESHEET_SIZE * SCALING });

			initComponents();
		}

		

		void update() {
			updateComponents();
		}

		void draw() {
			drawComponents();
		}

		~Sushi() {
			components.clear();
		}

};
