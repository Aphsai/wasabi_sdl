#pragma once
#include <SDL2/SDL.h>
#include "components.hpp"

class Tile : public Entity {
	public:
		int sprite_x = 0;
		int sprite_y = 0;

		Tile(int x, int y, int xp, int yp);
		void init();
		void draw();
		void update();
};


