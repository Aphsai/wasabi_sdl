OBJ = main.cpp game.hpp game.cpp defs.hpp texture-manager.hpp texture-manager.cpp ecs.hpp input-component.hpp sushi.hpp animation.hpp components.hpp

all : $(OBJ)
	g++ $(OBJ) -w -lSDL2 -lSDL2_image -o wasabi
