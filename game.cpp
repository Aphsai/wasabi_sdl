#include "game.hpp"
#include "map.hpp"
#include "defs.hpp"
#include "components.hpp"
#include "texture-manager.hpp"
#include "sushi.hpp"
#include "tile.hpp"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Entity* sushi = nullptr;
Entity* ace = nullptr;
Entity* two = nullptr;
Game::Game() {
	window = SDL_CreateWindow("Wasabi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		std::cout << "Error initialized SDL_Window! " << SDL_GetError() << std::endl;
		return;
	}
	std::cout << "Window initialized" << std::endl;
	Game::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(Game::renderer, 32, 45, 59, 255);
	if (Game::renderer == NULL) {
		std::cout << "Error initializing SDL_Renderer! " << SDL_GetError() << std::endl;
		return;
	}
	std::cout << "Renderer initialized" << std::endl;
	screen = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	TextureManager::loadTexture("assets/Tilesheet/chopped.png");
	Map::loadMap("assets/map.map");
	sushi = new Sushi(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	ace = new Tile(20, 16, SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2);
	two = new Tile(21, 16, SCREEN_WIDTH / 3 * 2, SCREEN_HEIGHT / 2);
}

Game::~Game() {
	delete sushi;
	SDL_DestroyRenderer(Game::renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::update() {
	sushi->update();
	ace->update();
	two->update();
	checkCollision();
}
void Game::draw() {
	clearScreen();
	sushi->draw();
	ace->draw();
	two->draw();
	SDL_RenderPresent(Game::renderer);
}

void Game::checkCollision() {
	sushi->getComponent<ColliderComponent>(COLLIDER_COMPONENT).hasCollision(ace->getComponent<ColliderComponent>(COLLIDER_COMPONENT));
	sushi->getComponent<ColliderComponent>(COLLIDER_COMPONENT).hasCollision(two->getComponent<ColliderComponent>(COLLIDER_COMPONENT));
}

void Game::clearScreen() {
	SDL_RenderClear(Game::renderer);
}

void Game::gameLoop() {
	bool run = true;

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	unsigned int frameStart;
	int frameTime;
	std::cout << "Game loop initialized" << std::endl;
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
