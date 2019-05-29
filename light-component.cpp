#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <time.h>
#include "light-component.hpp"
#include "defs.hpp"
#include "game.hpp"
#include "stdlib.h"

LightComponent::LightComponent(int r, float b) {
    brightness = b;
}
void LightComponent::init(Entity* entity) {
    srand (time(NULL));
}
void LightComponent::draw(Entity* entity) {}


