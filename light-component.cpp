#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <time.h>
#include "light-component.hpp"
#include "defs.hpp"
#include "game.hpp"
#include "stdlib.h"

LightComponent::LightComponent(int r, float b) {
    radius = r;
    brightness = b;
}
void LightComponent::init(Entity* entity) {
    srand (time(NULL));
}
void LightComponent::draw(Entity* entity) {
    const int FLICKER = 3;
    const int DIVISIONS = 5;
    SDL_SetRenderDrawBlendMode(Game::renderer, SDL_BLENDMODE_ADD);
    for (int x = radius/DIVISIONS; x < radius; x+=radius/DIVISIONS) {
        filledCircleRGBA(Game::renderer, entity->xpos + rand() % FLICKER, entity->ypos + rand() % FLICKER, x, 80, 120, 255, brightness * (float)(radius - x)/radius * 255);
    }
}

