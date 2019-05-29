#include <iostream>
#include <SDL2/SDL.h>
#include "game.hpp"
#include "defs.hpp"
#include "health-component.hpp"
#include "graphics-component.hpp"

HealthComponent::HealthComponent(int h, int i) {
    health_points = h;
    health_capacity = h;
    iframe_capacity = i;
}

void HealthComponent::receiveDamage(Entity* entity, int d) {
    if (iframes == 0 && !dead) {
        health_points -= d;
        dead = health_points <= 0; 
        iframes = iframe_capacity;
        entity->getComponent<GraphicsComponent>(GRAPHICS_COMPONENT).alpha = 120;
        entity->getComponent<GraphicsComponent>(GRAPHICS_COMPONENT).setAnimation(HURT);
    }
}

void HealthComponent::restoreHealth(int r) {
    health_points += r;
    health_points = fmax(health_points, health_capacity);
}

void HealthComponent::update(Entity* entity) {
    if (iframes > 0) {
        iframes--;
        entity->getComponent<GraphicsComponent>(GRAPHICS_COMPONENT).alpha = 120;
    }
}

void HealthComponent::draw(Entity* entity) {
    SDL_Rect health_point_rect = { Game::camera->xpos + entity->xpos, Game::camera->ypos + entity->ypos - 30, health_points, 20};
    SDL_Rect health_capacity_rect = { Game::camera->xpos + entity->xpos, Game::camera->ypos + entity->ypos - 30, health_capacity, 20};
    SDL_SetRenderDrawColor(Game::renderer, 100, 0, 0, 255);
    SDL_RenderFillRect(Game::renderer, &health_capacity_rect);
    if (iframes > 0) {
        SDL_SetRenderDrawColor(Game::renderer, 0, 220, 0, 255);
    } else {
        SDL_SetRenderDrawColor(Game::renderer, 220, 0, 0, 255);
    }
    SDL_RenderFillRect(Game::renderer, &health_point_rect);
}
