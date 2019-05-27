#include <iostream>
#include "game.hpp"
#include "map.hpp"
#include "defs.hpp"
#include "components.hpp"
#include "texture-manager.hpp"
#include "sushi.hpp"
#include "enemy.hpp"
#include "camera.hpp"
#include "light.hpp"
#include "tile.hpp"
#include "entity-manager.hpp"
#include "collision.hpp"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Entity* Game::camera;
Entity* light;
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
	screen = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    c = new Collision();
	TextureManager::loadTexture("assets/Tilesheet/test.png");
    camera = new Camera();
    Game::manager->addEntity(new Sushi(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - TILESHEET_SIZE * 2));
    Game::manager->addEntity(new Enemy(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - TILESHEET_SIZE * 2));
    Game::manager->addEntity(Game::camera);
	Map::loadMap("assets/map.map");
    light = new LightTest(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - TILESHEET_SIZE * 2);
}

Game::~Game() {
	SDL_DestroyRenderer(Game::renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::update() {
	checkCollision();
    Game::manager->updateEntities();
    Game::manager->refreshEntities();
}
void Game::draw() {
	clearScreen();
    light->draw();
    Game::manager->drawEntities();
	SDL_RenderPresent(Game::renderer);
}

void Game::checkCollision() {
    c->handleCollision(Game::manager->getComponentGroup(COLLIDER_COMPONENT));
//    ColliderComponent *a_c;
//	for (Entity* a : Game::manager->getComponentGroup(COLLIDER_COMPONENT)) {
//        if (a->mark_active == false) continue;
//        a_c = &a->getComponent<ColliderComponent>(COLLIDER_COMPONENT);
//        a_c->resetCollision();
//
//        //Resolve x-axis collisions
//        a->xpos = a->n_xpos;
//		for (Entity* b: Game::manager->getComponentGroup(COLLIDER_COMPONENT)) {
//			if (a_c->type != b->getComponent<ColliderComponent>(COLLIDER_COMPONENT).type) {
//				a_c->hasCollision(a, b, true);
//			}
//		}
//        a->n_xpos = a->xpos;
//        //Resolve y-axis collisions
//        a->ypos = a->n_ypos;
//        for (Entity* b: Game::manager->getComponentGroup(COLLIDER_COMPONENT)) {
//			if (a_c->type != b->getComponent<ColliderComponent>(COLLIDER_COMPONENT).type) {
//				a_c->hasCollision(a, b, false);
//			}
//		}
//        a->n_ypos = a->ypos;
//
//	}
}

void Game::clearScreen() {
	SDL_SetRenderDrawColor(Game::renderer, 47, 64, 81, 255);
    //#5e81a2
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
