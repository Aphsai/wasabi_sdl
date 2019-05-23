#include <iostream>
#include "sushi.hpp"
#include "defs.hpp"
#include "game.hpp"

Sushi::Sushi(int x, int y) {
	n_xpos = xpos = x;
	n_ypos = ypos = y;
    jump_height = 50;

	generateTag();
	init();
	addAnimations();
}

void Sushi::addAnimations() {
	GraphicsComponent* gc = &getComponent<GraphicsComponent>(GRAPHICS_COMPONENT);
	gc->addAnimation(WALK, SDL_Rect { SPRITESHEET_LOCATION_X * TILESHEET_SIZE, SPRITESHEET_LOCATION_Y * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE }, 3, 5);
	gc->addAnimation(JUMP, SDL_Rect { 21 * TILESHEET_SIZE, 9 * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE }, 1, 1);
	gc->addAnimation(LAND, SDL_Rect { 22 * TILESHEET_SIZE, 9 * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE }, 2, 10);
}

void Sushi::init() {
	addComponent<InputComponent>(INPUT_COMPONENT);
	addComponent<GraphicsComponent>(GRAPHICS_COMPONENT, SDL_Rect { SPRITESHEET_LOCATION_X * TILESHEET_SIZE, SPRITESHEET_LOCATION_Y * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE });
	addComponent<PhysicsComponent>(PHYSICS_COMPONENT);
	addComponent<ColliderComponent>(COLLIDER_COMPONENT, PLAYER);
	addComponent<JumpingComponent>(JUMPING_COMPONENT, jump_height);
    addComponent<CameraComponent>(CAMERA_COMPONENT);
	initComponents();
}

void Sushi::update() {
	updateComponents();
}

void Sushi::draw() {
	drawComponents();
}

Sushi::~Sushi() {
	components.clear();
}

