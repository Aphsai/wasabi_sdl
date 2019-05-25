#include "ecs.hpp"

class HealthComponent : public Component {
    public:
        HealthComponent(int);
        void receiveDamage(Entity* entity, int);
        void restoreHealth(int);
        void draw(Entity* entity);

    private:
        int health_points;
        int health_capacity;
        bool dead = false;
};
