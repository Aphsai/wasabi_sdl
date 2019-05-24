#include "ecs.hpp"

class Enemy : public Entity {
    public:
        int original_x, original_y;
        Enemy(int, int);
        void addAnimations();
        void init();
        void update();
        void draw();
        ~Enemy();
};
