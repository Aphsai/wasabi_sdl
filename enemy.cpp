#include "enemy.hpp"
#include "components.hpp"
#include "defs.hpp"

Enemy::Enemy(int x, int y) {
    original_x = n_xpos = xpos = x;
    original_y = n_ypos = ypos = y;
    width = TILESHEET_SIZE * SCALING;
    height = TILESHEET_SIZE * SCALING;

    generateTag();
    init();
    addAnimations();
}

void Enemy::addAnimations() {
    GraphicsComponent* gc = &getComponent<GraphicsComponent>(GRAPHICS_COMPONENT);
    gc->addAnimation(WALK, SDL_Rect { 20 * TILESHEET_SIZE, 12 * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE }, 2, 10);
    gc->addAnimation(PERISH, SDL_Rect { 0 * TILESHEET_SIZE, 13 * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE }, 10, 10);
}

void Enemy::init() {
    addComponent<GraphicsComponent>(GRAPHICS_COMPONENT, SDL_Rect { 20 * TILESHEET_SIZE, 12 * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE });
    addComponent<PhysicsComponent>(PHYSICS_COMPONENT);
    addComponent<ColliderComponent>(COLLIDER_COMPONENT, ENEMY);
    addComponent<HealthComponent>(HEALTH_COMPONENT, 30, 10);
    addAnimations();
    initComponents();
}

void Enemy::update() {
    GraphicsComponent* gc = &getComponent<GraphicsComponent>(GRAPHICS_COMPONENT);
    if (getComponent<HealthComponent>(HEALTH_COMPONENT).dead) {
        gc->setAnimation(PERISH);
        if (gc->animation_complete) {
            mark_remove = true;
        }
    }
    updateComponents();
}

void Enemy::draw() {
    drawComponents();
}

Enemy::~Enemy() {}
