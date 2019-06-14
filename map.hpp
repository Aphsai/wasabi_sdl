#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "tile.hpp"

class Map {
	public:
		static void loadMap(const char*);
        static void generateMap();
        static void clearMap();
        static std::vector<Tile*> map;
        ~Map();
};

