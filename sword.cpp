#include "sword.hpp"
#include "defs.hpp"
#include "collider-component.hpp"

Sword::Sword(int x, int y, int p, int w, int h) {
    n_xpos = xpos = x;
    n_ypos = ypos = y;
    parent = p;
    width = w;
    height = h;
    generateTag();
    init();
}

void Sword::init() {
    addComponent<ColliderComponent>(COLLIDER_COMPONENT, SWORD);
    initComponents();
}

void Sword::update() {
    updateComponents();
}

void Sword::draw() {
    drawComponents();
}


