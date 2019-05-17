#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "tile.hpp"
#define MAP_SIZE 40

class Map {
	public:
		static void loadMap(const char*);
        static std::vector<std::vector<Tile*>> map;
        ~Map();
};

