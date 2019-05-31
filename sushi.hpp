#pragma once
#include "ecs.hpp"

class PhysicsComponent;
class GraphicsComponent;
class JumpingComponent;
class ColliderComponent;
class HealthComponent;
class InputComponent;

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
        SDL_RendererFlip flip;

	    const int LATERAL_SPEED = 30;
        const int PROJECTILE_SPEED = 30;
};
