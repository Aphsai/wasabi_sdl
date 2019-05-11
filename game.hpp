#pragma once
#include <SDL2/SDL.h>
#include "defs.hpp"
#include "texture-manager.hpp"

class Game {
	public: 
		void gameLoop();
		Game();
		~Game();
		static SDL_Event event;

	private:
		void update();
		void draw();
		void clearScreen();

		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Rect screen;

};
