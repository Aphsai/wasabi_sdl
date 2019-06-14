#include "grab-component.hpp"
#include "jumping-component.hpp"
#include "collider-component.hpp"
#include "input-component.hpp"

void GrabComponent::init(Entity* entity) {
    jc = &entity->getComponent<JumpingComponent>(JUMPING_COMPONENT);
    cc = &entity->getComponent<ColliderComponent>(COLLIDER_COMPONENT);
    ic = &entity->getComponent<InputComponent>(INPUT_COMPONENT);
}

void GrabComponent::update(Entity* entity) {
    if (!cc->bottomCollision && !isGrabbing && (cc->leftCollision && ic->moving_backward || cc->rightCollision && ic->moving_forward)) {
        jc->resetJump();
        isGrabbing = true;
    }
    if (cc->bottomCollision) {
        isGrabbing = false;
    }
}

