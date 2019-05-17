#include <iostream>
#include "defs.hpp"
#include "tile.hpp"

Tile::Tile(int x, int y, int xp, int yp) {
	sprite_x = x;
	sprite_y = y;
	xpos = xp;
	ypos = yp;

	generateTag();
	init();
}

void Tile::init() {
	addComponent<GraphicsComponent>(GRAPHICS_COMPONENT, SDL_Rect { sprite_x, sprite_y, TILESHEET_SIZE, TILESHEET_SIZE });
    addComponent<ColliderComponent>(COLLIDER_COMPONENT, TERRAIN);
	initComponents();
}

void Tile::draw() {
	drawComponents();
}

void Tile::update() {
	updateComponents();
}
