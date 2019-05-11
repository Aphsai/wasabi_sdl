#pragma once
#include "SDL2/SDL.h"

class Entity;
class Game;

class Component {
	public:
		virtual void execute(Entity*) = 0;
		int id;
};
