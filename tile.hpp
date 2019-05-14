#include <SDL2/SDL.h>
#include <iostream>
#include "components.hpp"
#include "defs.hpp"

class Tile : public Entity {
	public:
		int sprite_x;
		int sprite_y;

		Tile(int x, int y, int xp, int yp);
		void init();
		void draw();
		void update();
};


