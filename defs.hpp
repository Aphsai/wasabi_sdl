//Game specific
#pragma once
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define TILESHEET_SIZE 64
#define TILESHEET_X 64
#define TILESHEET_Y 64
#define MAP_SIZE 40
#define GRAVITY 10
#define NORMAL_FORCE -10
#define SCALING 1

// ANIMATIONS
enum { WALK, RUN, IDLE, JUMP, FLY, ATTACK, FALL, LAND, PERISH, HURT, WALL_GRAB };

// ANIMATION TYPES
enum { BOUNCE, LINEAR };

// ENTITY TYPES
enum { PLAYER, TERRAIN, PROJECTILE, ENEMY, SWORD, BIRD };
