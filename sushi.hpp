#pragma once
#include "ecs.hpp"

class PhysicsComponent;
class GraphicsComponent;
class JumpingComponent;
class ColliderComponent;
class HealthComponent;
class InputComponent;
class Sword;

class Sushi : public Entity {
	public:
        int jump_height;
        int x_offset, y_offset;
		void addAnimations();
		void init();
		void update();
		void draw();
		Sushi(int x, int y);
		~Sushi();

    private:
		PhysicsComponent* pc;
		GraphicsComponent* gc;
		JumpingComponent* jc;
        ColliderComponent* cc;
        HealthComponent* hc;
        InputComponent* ic;
        Sword* sword;

        SDL_RendererFlip flip;

	    const int LATERAL_SPEED = 30;
        const int PROJECTILE_SPEED = 30;
        const int JUMP_HEIGHT = 50;
        const int WIDTH = 64;
        const int HEIGHT = 64;
        const int X_OFFSET = 0;
        const int Y_OFFSET = 0;
        bool is_grabbing_wall = false;
};
