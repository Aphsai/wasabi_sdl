#pragma once
#include <set>
#include <vector>
#include "ecs.hpp"

struct QuadTree {

    const short MAX_OBJECTS = 10;
    const short MAX_DEPTH = 5;

    std::unordered_set<Entity*> entities;

    short xpos;
    short ypos;
    short width;
    short height;
    short depth;

    QuadTree *north_west;
    QuadTree *north_east;
    QuadTree *south_west;
    QuadTree *south_east;
    
    QuadTree(short, short, short, short, short);
    bool insert(Entity*);
    void subdivide();
    void clean();
    void construct(std::unordered_set<Entity*>);
    void getLeaves (std::vector<QuadTree*>&);

};
