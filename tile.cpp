#include <iostream>
#include "defs.hpp"
#include "tile.hpp"

Tile::Tile(int x, int y, int xp, int yp) {
	sprite_x = x;
	sprite_y = y;
	n_xpos = xpos = xp;
	n_ypos = ypos = yp;
    width = 32;
    height = 32;
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
