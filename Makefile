OBJ = main.cpp game.hpp game.cpp defs.hpp texture-manager.hpp texture-manager.cpp ecs.hpp input-component.hpp sushi.hpp animation.hpp components.hpp map.hpp map.cpp tile.hpp collider-component.hpp

all : $(OBJ)
	g++ $(OBJ) -w -lSDL2 -lSDL2_image -o wasabi
