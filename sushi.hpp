#pragma once
#include "components.hpp"

class Sushi : public Entity {
	public:
		const int SPRITESHEET_LOCATION_X = 18;
		const int SPRITESHEET_LOCATION_Y = 9;

		Sushi(int x, int y);
		void addAnimations();
		void init();
		void update();
		void draw();
		~Sushi();
};
