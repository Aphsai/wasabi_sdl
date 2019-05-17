#include <iostream>
#include "sushi.hpp"
#include "defs.hpp"
#include "game.hpp"

Sushi::Sushi(int x, int y) {
	p_xpos = xpos = x;
	p_ypos = ypos = y;
    jump_height = 50;

	generateTag();
	init();
	addAnimations();
}

void Sushi::addAnimations() {
	GraphicsComponent* gc = &getComponent<GraphicsComponent>(GRAPHICS_COMPONENT);
	gc->addAnimation(WALK, SDL_Rect { SPRITESHEET_LOCATION_X * TILESHEET_SIZE, SPRITESHEET_LOCATION_Y * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE }, 3, 15);
	gc->addAnimation(JUMP, SDL_Rect { 21 * TILESHEET_SIZE, 9 * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE }, 1, 1);
	gc->addAnimation(LAND, SDL_Rect { 22 * TILESHEET_SIZE, 9 * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE }, 2, 10);
}

void Sushi::init() {
	addComponent<InputComponent>(INPUT_COMPONENT);
	addComponent<GraphicsComponent>(GRAPHICS_COMPONENT, SDL_Rect { SPRITESHEET_LOCATION_X * TILESHEET_SIZE, SPRITESHEET_LOCATION_Y * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE });
	addComponent<PhysicsComponent>(PHYSICS_COMPONENT);
	addComponent<ColliderComponent>(COLLIDER_COMPONENT, PLAYER);
	addComponent<JumpingComponent>(JUMPING_COMPONENT, jump_height);
	initComponents();
}

void Sushi::update() {
	updateComponents();
}

void Sushi::draw() {
    Game::camera.x = SCREEN_WIDTH / 2 - xpos;
    Game::camera.y = SCREEN_HEIGHT / 2 - TILESHEET_SIZE - ypos;
	drawComponents();
}

Sushi::~Sushi() {
	components.clear();
}

