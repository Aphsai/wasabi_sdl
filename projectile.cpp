#include "projectile.hpp"
#include "defs.hpp"

Projectile::Projectile(int x, int y, float v) {
    n_xpos = xpos = x;
    n_ypos = ypos = y;
    velocity = v;

    generateTag();
    init();
}

Projectile::Projectile(int x, int y, int p, float v) {
    n_xpos = xpos = x;
    n_ypos = ypos = y;
    parent = p;
    velocity = v;

    generateTag();
    init();
}

void Projectile::init() {
    addComponent<ColliderComponent>(COLLIDER_COMPONENT, PROJECTILE);
    addComponent<GraphicsComponent>(GRAPHICS_COMPONENT, SDL_Rect { 16 * TILESHEET_SIZE, 3 * TILESHEET_SIZE, TILESHEET_SIZE, TILESHEET_SIZE});
    addComponent<PhysicsComponent>(PHYSICS_COMPONENT);
    getComponent<PhysicsComponent>(PHYSICS_COMPONENT).xvel = velocity;
    getComponent<PhysicsComponent>(PHYSICS_COMPONENT).yvel = 0;
}

void Projectile::draw() {
    drawComponents();
}

void Projectile::update() {
    getComponent<PhysicsComponent>(PHYSICS_COMPONENT).applyNormalForce();
    updateComponents();
}
