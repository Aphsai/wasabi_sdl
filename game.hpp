#pragma once
#include <SDL2/SDL.h>
#include "entity-manager.hpp"

class Entity;
class Collision;

class Game {
	public: 
		void gameLoop();
		Game();
		~Game();
		static SDL_Event event;
		static SDL_Renderer* renderer;
		static EntityManager* manager;
        static Entity* camera;

	private:
		void update();
		void draw();
		void clearScreen();
		void checkCollision();

		SDL_Window *window;
		SDL_Rect screen;
        Collision c;
};
