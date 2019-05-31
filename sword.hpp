#include "ecs.hpp"

class Sword : public Entity {
    public:
        Sword(int, int, int, int, int);
        void init();
        void draw();
        void update();
        int parent;
};
