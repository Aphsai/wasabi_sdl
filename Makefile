OBJ = main.cpp game.hpp game.cpp defs.hpp texture-manager.hpp texture-manager.cpp sushi.hpp sushi.cpp animation.hpp map.hpp map.cpp tile.hpp tile.cpp entity-manager.hpp entity-manager.cpp collision.hpp collision.cpp

COMPONENTS = collider-component.hpp collider-component.cpp input-component.hpp input-component.cpp ecs.hpp ecs.cpp graphics-component.hpp graphics-component.cpp components.hpp physics-component.hpp physics-component.cpp jumping-component.hpp jumping-component.cpp

all : $(OBJ)
	ccache g++ $(OBJ) $(COMPONENTS) -w -lSDL2 -lSDL2_image -o nirvana
