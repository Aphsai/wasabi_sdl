#include "ecs.hpp"

class LightTest : public Entity {
    public:
        LightTest(int x, int y);
        void init();
        void update();
        void draw();
};
