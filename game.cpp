#include "game.hpp"

Game::Game() {
	window = SDL_CreateWindow("Wasabi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	screen = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
}

Game::~Game() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::update() {}
void Game::draw() {
	SDL_Texture *testTexture = TextureManager::loadTexture("assets/Tilesheet/colored.png", renderer);
	clearScreen();
	SDL_RenderPresent(renderer);
}
void Game::clearScreen() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Game::gameLoop() {
	bool run = true;

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	unsigned int frameStart;
	int frameTime;

	while(run) {
		frameStart = SDL_GetTicks();
		SDL_PollEvent(&event);
		if ((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q) || event.type == SDL_QUIT) run = false;

		draw();
		update();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
	}
}
