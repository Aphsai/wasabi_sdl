#pragma once
#include "ecs.hpp"

class HealthComponent : public Component {
    public:
        HealthComponent(int, int);
        void receiveDamage(Entity* entity, int);
        void restoreHealth(int);
        void draw(Entity* entity);
        void update(Entity* entity);
        bool dead = false;
        int iframes = 0;
        int iframe_capacity = 0; 

    private:
        int health_points;
        int health_capacity;
};
