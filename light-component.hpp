#include "ecs.hpp"
class LightComponent : public Component {
    public:
        LightComponent(int, float);
        void draw(Entity* entity);
        void init(Entity* entity);

    private:
        float brightness;
        int radius;
};
