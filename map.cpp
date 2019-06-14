#include "map.hpp"
#include "defs.hpp"
#include "game.hpp"
#include <iostream>
#include <fstream>


std::vector<Tile*> Map::map;

void Map::loadMap(const char* map_file) {
	std::fstream fmap(map_file);
    int a;
    Tile* t;
        for (int x = 0; x < MAP_SIZE; x++) {
            for (int y = 0; y < MAP_SIZE; y++) {
                fmap >> a;
                if (a == 1) {
                    t = new Tile( 12 * TILESHEET_SIZE, 1 * TILESHEET_SIZE, y * TILESHEET_SIZE * SCALING, x * TILESHEET_SIZE * SCALING);
                    Map::map.push_back(t);
                    Game::manager->addEntity(t);
		}
                else {
                }
            }
        }
	fmap.close();
}

void Map::generateMap() {

}

void Map::clearMap() {
    for (Tile* t: Map::map) {
        t->mark_remove = true;
    }
}

Map::~Map() {
    clearMap();
}
