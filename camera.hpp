#include "ecs.hpp"

class Camera : public Entity {
    public: 
        Camera() = default;
        void priority_update();
        const float SMOOTH = 0.1;
};
