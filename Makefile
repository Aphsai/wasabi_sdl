OBJ = main.cpp game.hpp game.cpp defs.hpp texture-manager.hpp texture-manager.cpp sushi.hpp sushi.cpp animation.hpp map.hpp map.cpp tile.hpp tile.cpp entity-manager.hpp entity-manager.cpp collision.hpp collision.cpp

COMPONENTS = collider-component.hpp collider-component.cpp input-component.hpp input-component.cpp ecs.hpp ecs.cpp graphics-component.hpp graphics-component.cpp components.hpp physics-component.hpp physics-component.cpp jumping-component.hpp jumping-component.cpp

#yt.Gopa.o : pA.hpp$(CC) $(CPPFLAGS) -c pa.cpp``W
PROG = nirvana
CC = ccache g++
CPPFLAGS = -w -lSDL2 -lSDL2_image 
OBJS = main.o collider-component.o input-component.o ecs.o graphics-component.o  physics-component.o jumping-component.o tile.o entity-manager.o collision.o map.o sushi.o texture-manager.o defs.hpp components.hpp animation.hpp game.o 

$(PROG) : $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)
main.o :
	$(CC) $(CPPFLAGS) -c main.cpp
collider-component.o : collider-component.hpp collider-component.cpp
	$(CC) $(CPPFLAGS) -c collider-component.cpp
input-component.o : input-component.hpp input-component.cpp
	$(CC) $(CPPFLAGS) -c input-component.cpp
ecs.o : ecs.hpp
	$(CC) $(CPPFLAGS) -c ecs.cpp
graphics-component.o : graphics-component.hpp graphics-component.cpp
	$(CC) $(CPPFLAGS) -c graphics-component.cpp
physics-component.o : physics-component.hpp physics-component.cpp
	$(CC) $(CPPFLAGS) -c physics-component.cpp
jumping-component.o : jumping-component.hpp jumping-component.cpp
	$(CC) $(CPPFLAGS) -c jumping-component.cpp
tile.o : tile.hpp tile.cpp
	$(CC) $(CPPFLAGS) -c tile.cpp
entity-manager.o : entity-manager.hpp entity-manager.cpp
	$(CC) $(CPPFLAGS) -c entity-manager.cpp
collision.o : collision.hpp collision.cpp
	$(CC) $(CPPFLAGS) -c collision.cpp
map.o : map.hpp map.cpp
	$(CC) $(CPPFLAGS) -c map.cpp
sushi.o : sushi.hpp sushi.cpp
	$(CC) $(CPPFLAGS) -c sushi.cpp
texture-manager.o : texture-manager.hpp texture-manager.cpp
	$(CC) $(CPPFLAGS) -c texture-manager.cpp
game.o : game.hpp game.cpp
	$(CC) $(CPPFLAGS) -c game.cpp
