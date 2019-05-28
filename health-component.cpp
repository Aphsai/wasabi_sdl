#include <iostream>
#include <SDL2/SDL.h>
#include "game.hpp"
#include "defs.hpp"
#include "health-component.hpp"
#include "graphics-component.hpp"

HealthComponent::HealthComponent(int h) {
    health_points = h;
    health_capacity = h;
}

void HealthComponent::receiveDamage(Entity* entity, int d) {
    std::cout << entity->tag << " CURRENT HP: " << health_points << std::endl;
    health_points -= d;
    dead = health_points <= 0; 
}

void HealthComponent::restoreHealth(int r) {
    health_points += r;
    health_points = fmax(health_points, health_capacity);
}

void HealthComponent::draw(Entity* entity) {
    SDL_Rect health_point_rect = { Game::camera->xpos + entity->xpos, Game::camera->ypos + entity->ypos - 30, health_points, 20};
    SDL_Rect health_capacity_rect = { Game::camera->xpos + entity->xpos, Game::camera->ypos + entity->ypos - 30, health_capacity, 20};
    SDL_SetRenderDrawColor(Game::renderer, 100, 0, 0, 255);
    SDL_RenderFillRect(Game::renderer, &health_capacity_rect);
    SDL_SetRenderDrawColor(Game::renderer, 220, 0, 0, 255);
    SDL_RenderFillRect(Game::renderer, &health_point_rect);
}
