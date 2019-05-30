#include "ecs.hpp"

class Enemy : public Entity {
    public:
        Entity* player;
        Enemy(int, int, Entity*);
        void addAnimations();
        void init();
        void update();
        void draw();
        ~Enemy();
};
