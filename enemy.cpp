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
}

void Enemy::init() {
    addComponent<GraphicsComponent>(GRAPHICS_COMPONENT, SDL_Rect { 20 * TILESHEET_SIZE, 12 * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE });
    addComponent<PhysicsComponent>(PHYSICS_COMPONENT);
    addComponent<ColliderComponent>(COLLIDER_COMPONENT, ENEMY);
    //addComponent<CameraComponent>(CAMERA_COMPONENT);
    addComponent<HealthComponent>(HEALTH_COMPONENT, 30);
    addAnimations();
    getComponent<PhysicsComponent>(PHYSICS_COMPONENT).xvel = 20;
    initComponents();
}

void Enemy::update() {
    if (fabs(xpos - original_x) > 3 * TILESHEET_SIZE) {
        getComponent<PhysicsComponent>(PHYSICS_COMPONENT).xvel *= -1;
        if (getComponent<PhysicsComponent>(PHYSICS_COMPONENT).xvel < 0) {
            getComponent<GraphicsComponent>(GRAPHICS_COMPONENT).setAnimation(WALK, SDL_FLIP_NONE);
        } else {
            getComponent<GraphicsComponent>(GRAPHICS_COMPONENT).setAnimation(WALK, SDL_FLIP_HORIZONTAL);
        }
    }
    updateComponents();
}

void Enemy::draw() {
    drawComponents();
}

Enemy::~Enemy() {
    components.clear();
}
