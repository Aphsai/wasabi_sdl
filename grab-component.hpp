#pragma once
#include "ecs.hpp"

class JumpingComponent;
class ColliderComponent;
class InputComponent;

class GrabComponent : public Component {
    public:
        void init(Entity*);
        void update(Entity*);
        void resetGrab();
        bool isGrabbing = false;

    private:
        JumpingComponent* jc;
        ColliderComponent* cc;
        InputComponent* ic;
};
