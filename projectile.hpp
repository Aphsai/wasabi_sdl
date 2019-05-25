#include "ecs.hpp"
#include "components.hpp"

class Projectile : public Entity {
    public:
        float velocity = 0;
        int parent = -1;
        void init();
        void update();
        void draw();
        Projectile(int, int, float);
        Projectile(int, int, int, float);
};
