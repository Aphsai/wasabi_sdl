#include "game.hpp"
#include "defs.hpp"
#include "ecs.hpp"
#include "texture-manager.hpp"
#include "sushi.hpp"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Entity* sushi = nullptr;

Game::Game() {
	window = SDL_CreateWindow("Wasabi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	Game::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	screen = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	TextureManager::loadTexture("assets/Tilesheet/chopped.png");
	sushi = new Sushi();
}

Game::~Game() {
	SDL_DestroyRenderer(Game::renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::update() {
	sushi->update();
}
void Game::draw() {
	clearScreen();
	sushi->draw();
	SDL_RenderPresent(Game::renderer);
}
void Game::clearScreen() {
	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
	SDL_RenderClear(Game::renderer);
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
