#include "map.hpp"
#include <iostream>
#include <fstream>

void Map::loadMap(const char* map_file) {
	std::fstream map(map_file);

	map.close();
}
