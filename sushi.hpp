#pragma once
#include "components.hpp"

class Sushi : public Entity {
	public:
        int jump_height;

		Sushi(int x, int y);
		void addAnimations();
		void init();
		void update();
		void draw();
		~Sushi();
};
