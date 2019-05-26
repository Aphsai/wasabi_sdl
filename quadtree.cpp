#include <SDL2/SDL.h>
#include "quadtree.hpp"
#include "defs.hpp"
#include "game.hpp"

QuadTree::QuadTree(short x, short y, short w, short h) {
    xpos = x;
    ypos = y;
    height = h;
    width = w;
    north_west = nullptr;
    north_east = nullptr;
    south_west = nullptr;
    south_east = nullptr;
}

bool QuadTree::insert(Entity* entity) {
    int relative_xpos = Game::camera->xpos + entity->xpos;
    int relative_ypos = Game::camera->ypos + entity->ypos;
    //Out of bounds, not part of this quadtree
    if (relative_xpos + entity->width < xpos || relative_xpos > xpos + width || relative_ypos + entity->height < ypos || relative_ypos > ypos + height) {
        return false;
    }
    //Check for capacity and if there are no subdivisions in this quadtree
    if (entities.size() < MAX_OBJECTS && north_west == nullptr) {
        entities.insert(entity);
        return true;
    }

    if (north_west == nullptr) subdivide();

    if (north_west->insert(entity)) return true;
    if (north_east->insert(entity)) return true;
    if (south_west->insert(entity)) return true;
    if (south_east->insert(entity)) return true;

    return false;
}

void QuadTree::subdivide() {
    north_west = new QuadTree(xpos, ypos, width / 2, height / 2);
    north_east = new QuadTree(xpos + width / 2, ypos, width / 2, height / 2);
    south_west = new QuadTree(xpos, ypos + height / 2, width / 2, height / 2);
    south_west = new QuadTree(xpos + width / 2, ypos + height / 2, width / 2, height / 2);
}
void QuadTree::construct(std::unordered_set<Entity*> collideable_entities) {
    for (Entity* entity : collideable_entities) {
        insert(entity);
    }
}
