#pragma once
#include <SDL2/SDL.h>

class Game {
	public: 
		void gameLoop();
		Game();
		~Game();
		static SDL_Event event;
		static SDL_Renderer *renderer;

	private:
		void update();
		void draw();
		void clearScreen();

		SDL_Window *window;
		SDL_Rect screen;

};
