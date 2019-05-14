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
	std::cout << "Tile tag: " << tag << std::endl; 
	addComponent<GraphicsComponent>(GRAPHICS_COMPONENT, SDL_Rect { sprite_x * TILESHEET_SIZE, sprite_y * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE });
	addComponent<ColliderComponent>(COLLIDER_COMPONENT, "Terrain");

	initComponents();
}

void Tile::draw() {
	drawComponents();
}

void Tile::update() {
	updateComponents();
}
