#include "camera.hpp"
#include "game.hpp"
#include "defs.hpp"
#include "camera-component.hpp"

void Camera::priority_update() {

    int average_xpos = 0;
    int average_ypos = 0;
    int total_components = Game::manager->getComponentGroup(CAMERA_COMPONENT).size();
    for (Entity* entity : Game::manager->getComponentGroup(CAMERA_COMPONENT)) {
        average_xpos += entity->xpos;
        average_ypos += entity->ypos;
    }

    average_xpos /= total_components;
    average_ypos /= total_components;


    xpos += SMOOTH * ((SCREEN_WIDTH / 2 - average_xpos) - xpos);
    ypos += SMOOTH * ((SCREEN_HEIGHT / 2 - average_ypos) - ypos);

}
