#include "map.hpp"
#include "defs.hpp"
#include "game.hpp"
#include <iostream>
#include <fstream>


std::vector<std::vector<Tile*>> Map::map;
void Map::loadMap(const char* map_file) {
	std::fstream fmap(map_file);
    int a;
    Tile* t;
        for (int x = 0; x <= MAP_SIZE; x++) {
            std::vector<Tile*> tmp;
            for (int y = 0; y <= MAP_SIZE; y++) {
                fmap >> a;
                if (a == 1) {
                    t = new Tile(y*16 % (30 * 16), 16, y * TILESHEET_SIZE * SCALING, x * TILESHEET_SIZE * SCALING);
                    tmp.push_back(t);
                    Game::manager->addEntity(t);
                } else {
                    tmp.push_back(nullptr);
                }
            }
            map.push_back(tmp);
        }
	fmap.close();
}

Map::~Map() {
    for (std::vector<Tile*> a : map) {
        for (Tile* t : a) {
            delete t;
        }
    }
    
}
