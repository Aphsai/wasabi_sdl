#include <SDL2/SDL.h>
#include <iostream>
#include "components.hpp"
#include "defs.hpp"

class Tile : public Entity {
	public:
		int sprite_x;
		int sprite_y;

		Tile(int x, int y, int xp, int yp) {
			sprite_x = x;
			sprite_y = y;
			xpos = xp;
			ypos = yp;

			generateTag();
			init();
		}

		void init() {
			std::cout << "Tile tag: " << tag << std::endl; 
			addComponent<GraphicsComponent>(GRAPHICS_COMPONENT, SDL_Rect { sprite_x * TILESHEET_SIZE, sprite_y * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE });
			addComponent<ColliderComponent>(COLLIDER_COMPONENT, SDL_Rect { xpos, ypos, TILESHEET_SIZE * SCALING, TILESHEET_SIZE * SCALING});

			initComponents();
		}

		void draw() {
			drawComponents();
		}

		void update() {
			updateComponents();
		}
};


