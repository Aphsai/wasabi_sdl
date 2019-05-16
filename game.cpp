#include <iostream>
#include "game.hpp"
#include "map.hpp"
#include "defs.hpp"
#include "components.hpp"
#include "texture-manager.hpp"
#include "sushi.hpp"
#include "tile.hpp"
#include "entity-manager.hpp"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
EntityManager* Game::manager;

Game::Game() {
	window = SDL_CreateWindow("Wasabi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		std::cout << "Error initialized SDL_Window! " << SDL_GetError() << std::endl;
		return;
	}
	std::cout << "Window initialized" << std::endl;
	Game::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (Game::renderer == NULL) {
		std::cout << "Error initializing SDL_Renderer! " << SDL_GetError() << std::endl;
		return;
	}
	std::cout << "Renderer initialized" << std::endl;
	screen = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	TextureManager::loadTexture("assets/Tilesheet/chopped.png");
	Map::loadMap("assets/map.map");
	Game::manager = new EntityManager();
	Entity* sushi = new Sushi(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	Entity* ace = new Tile(20, 16, SCREEN_WIDTH / 3 + TILESHEET_SIZE * 2 * SCALING, SCREEN_HEIGHT / 2 + TILESHEET_SIZE * SCALING);
	Entity* two = new Tile(21, 16, SCREEN_WIDTH / 3 + TILESHEET_SIZE * 3 * SCALING, SCREEN_HEIGHT / 2+ TILESHEET_SIZE * 2 * SCALING);
	Entity* three = new Tile(22, 16, SCREEN_WIDTH / 3 + TILESHEET_SIZE * 4 * SCALING, SCREEN_HEIGHT / 2 + TILESHEET_SIZE * 2 * SCALING);
	Entity* four = new Tile(23, 16, SCREEN_WIDTH / 3 + TILESHEET_SIZE * 5 * SCALING, SCREEN_HEIGHT / 2 + TILESHEET_SIZE * 2 * SCALING);
	Entity* five = new Tile(24, 16, SCREEN_WIDTH / 3 + TILESHEET_SIZE * 6 * SCALING, SCREEN_HEIGHT / 2 + TILESHEET_SIZE * 2 * SCALING);
	Entity* six = new Tile(25, 16, SCREEN_WIDTH / 3 + TILESHEET_SIZE * 7 * SCALING, SCREEN_HEIGHT / 2 + TILESHEET_SIZE * SCALING);

	manager->addEntity(sushi);
	manager->addEntity(ace);
	manager->addEntity(two);
	manager->addEntity(three);
	manager->addEntity(four);
	manager->addEntity(five);
	manager->addEntity(six);
	manager->addEntityToGroup(sushi, COLLIDER_COMPONENT);
	manager->addEntityToGroup(ace, COLLIDER_COMPONENT);
	manager->addEntityToGroup(two, COLLIDER_COMPONENT);
	manager->addEntityToGroup(three, COLLIDER_COMPONENT);
	manager->addEntityToGroup(four, COLLIDER_COMPONENT);
	manager->addEntityToGroup(five, COLLIDER_COMPONENT);
	manager->addEntityToGroup(six, COLLIDER_COMPONENT);
}

Game::~Game() {
	SDL_DestroyRenderer(Game::renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::update() {
	manager->updateEntities();
	checkCollision();
}
void Game::draw() {
	clearScreen();
	manager->drawEntities();
	SDL_RenderPresent(Game::renderer);
}

void Game::checkCollision() {
	for (Entity* a : Game::manager->getComponentGroup(COLLIDER_COMPONENT)) {
		for (Entity* b: Game::manager->getComponentGroup(COLLIDER_COMPONENT)) {
			if (a->tag != b->tag) {
				a->getComponent<ColliderComponent>(COLLIDER_COMPONENT).hasCollision(a, b);
			}
		}
	}
}

void Game::clearScreen() {
	SDL_SetRenderDrawColor(Game::renderer, 32, 45, 59, 255);
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
