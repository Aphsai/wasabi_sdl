OBJ = main.cpp game.hpp game.cpp defs.hpp texture-manager.hpp texture-manager.cpp components.hpp entity.hpp input-component.hpp input-component.cpp ecs.hpp sushi.hpp

all : $(OBJ)
	g++ $(OBJ) -w -lSDL2 -lSDL2_image -o wasabi
