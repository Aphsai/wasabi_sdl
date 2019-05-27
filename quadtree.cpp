#include <iostream>
#include <SDL2/SDL.h>
#include "quadtree.hpp"
#include "defs.hpp"
#include "game.hpp"

QuadTree::QuadTree(short x, short y, short w, short h, short d) {

    xpos = x;
    ypos = y;
    height = h;
    width = w;
    depth = d;

    north_west = nullptr;
    north_east = nullptr;
    south_west = nullptr;
    south_east = nullptr;

    //std::cout << "QuadTree initialized" << std::endl;
}

bool QuadTree::insert(Entity* entity) {

    //Out of bounds, not part of this quadtree
    if (entity->xpos + entity->width < xpos || entity->xpos > xpos + width || entity->ypos + entity->height < ypos || entity->ypos > ypos + height) {
        //std::cout << entity->tag << " was out of bounds." << std::endl;
        return false;
    }

    //Check for capacity and if there are no subdivisions in this quadtree
    if (depth == MAX_DEPTH || (entities.size() < MAX_OBJECTS && north_west == nullptr)) {
        //std::cout <<  entity->tag <<  " has been inserted at depth: " << depth << std::endl;
        entities.insert(entity);
        return true;
    } 
    if (entities.size() > 0) {
        entities.clear();
    }

    if (north_west == nullptr) subdivide();

    north_west->insert(entity); 
    north_east->insert(entity); 
    south_west->insert(entity); 
    south_east->insert(entity); 

    return true;
}

void QuadTree::subdivide() {
    north_west = new QuadTree(xpos, ypos, width / 2, height / 2, depth + 1);
    north_east = new QuadTree(xpos + width / 2, ypos, width / 2, height / 2, depth + 1);
    south_west = new QuadTree(xpos, ypos + height / 2, width / 2, height / 2, depth + 1);
    south_east = new QuadTree(xpos + width / 2, ypos + height / 2, width / 2, height / 2, depth + 1);
}

void QuadTree::clean() {
    for (auto it = entities.begin(); it != entities.end();) {
        if ((*it)->mark_remove) {
            std::cout << "Entity will be deleted!" << std::endl;
            it = entities.erase(it);
            continue;
        }
        Entity* e = *it;
        int relative_xpos = Game::camera->xpos + e->xpos;
        int relative_ypos = Game::camera->ypos + e->ypos;
        if (e->xpos + e->width < xpos || e->xpos > xpos + width || e->ypos + e->height < ypos || e->ypos > ypos + height) {
            it = entities.erase(it);
        } else {
            ++it;
        }
    }
}

void QuadTree::construct(std::unordered_set<Entity*> collideable_entities) {
    for (Entity* entity : collideable_entities) {
        if (entity != nullptr && !entity->mark_remove) {
            insert(entity);
        }
    }
}

void QuadTree::combine() {
    if (north_west == nullptr) {
        return;
    }
    
    north_west->combine();
    north_east->combine();
    south_west->combine();
    south_east->combine();

    // if it's a leaf node
    if (north_west->north_west == nullptr) {
        // all empty
        if (north_west->entities.size() == 0 && north_east->entities.size() == 0 && south_west->entities.size() == 0 && south_east->entities.size() == 0) {

            delete north_west;
            delete north_east;
            delete south_east;
            delete south_west;

            north_west = nullptr;
            north_east = nullptr;
            south_west = nullptr;
            south_east = nullptr;

        }
    } 

}

void QuadTree::getLeaves (std::vector<QuadTree*>& v) {
    if (north_west == nullptr) {
        v.push_back(this);
    } else {
        north_west->getLeaves(v);
        north_east->getLeaves(v);
        south_west->getLeaves(v);
        south_east->getLeaves(v);
    }
}
