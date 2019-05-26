#include "light.hpp"
#include "light-component.hpp"
#include "camera-component.hpp"

LightTest::LightTest(int x, int y) {
    n_xpos = xpos = x;
    n_ypos = ypos = y;

    generateTag();
    init();
}

void LightTest::init() {
    addComponent<LightComponent>(LIGHT_COMPONENT, 100, 0.3);
    //addComponent<CameraComponent>(CAMERA_COMPONENT);
}

void LightTest::update() {
    updateComponents();
}

void LightTest::draw() {
    drawComponents();
}

