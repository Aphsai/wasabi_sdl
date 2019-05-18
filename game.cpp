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
SDL_Rect Game::camera;
EntityManager* Game::manager = new EntityManager();

Game::Game() {
	window = SDL_CreateWindow("Wasabi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		return;
	}
	Game::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (Game::renderer == NULL) {
		return;
	}
    camera = SDL_Rect { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	screen = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	TextureManager::loadTexture("assets/Tilesheet/chopped.png");

	manager->addEntity(new Sushi(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - TILESHEET_SIZE));
	Map::loadMap("assets/map.map");
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
    ColliderComponent *a_c;
	for (Entity* a : Game::manager->getComponentGroup(COLLIDER_COMPONENT)) {
        a_c = &a->getComponent<ColliderComponent>(COLLIDER_COMPONENT);
        a_c->resetCollision();
		for (Entity* b: Game::manager->getComponentGroup(COLLIDER_COMPONENT)) {
			if (a_c->type != b->getComponent<ColliderComponent>(COLLIDER_COMPONENT).type) {
				a_c->hasCollision(a, b);
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
	
	while(run) {
		frameStart = SDL_GetTicks();
		SDL_PollEvent(&event);

		if ((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q) || event.type == SDL_QUIT) run = false;

		update();
		draw();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
	}
}
