PROG = nirvana
CC = ccache g++
CPPFLAGS = -w -lSDL2 -lSDL2_image -lSDL2_gfx -Wall
OBJS = main.o collider-component.o input-component.o ecs.o graphics-component.o  physics-component.o jumping-component.o light-component.o tile.o entity-manager.o collision.o map.o sushi.o texture-manager.o defs.hpp components.hpp animation.hpp game.o light.cpp light.hpp camera-component.hpp projectile.o camera.o enemy.o health-component.o quadtree.o sword.o flying-component.o bird.o

$(PROG) : $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)
main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp
collider-component.o : collider-component.hpp collider-component.cpp
	$(CC) $(CPPFLAGS) -c collider-component.cpp
input-component.o : input-component.hpp input-component.cpp
	$(CC) $(CPPFLAGS) -c input-component.cpp
ecs.o : ecs.hpp ecs.cpp
	$(CC) $(CPPFLAGS) -c ecs.cpp
graphics-component.o : graphics-component.hpp graphics-component.cpp
	$(CC) $(CPPFLAGS) -c graphics-component.cpp
physics-component.o : physics-component.hpp physics-component.cpp
	$(CC) $(CPPFLAGS) -c physics-component.cpp
jumping-component.o : jumping-component.hpp jumping-component.cpp
	$(CC) $(CPPFLAGS) -c jumping-component.cpp
light-component.o : light-component.hpp light-component.cpp
	$(CC) $(CPPFLAGS) -c light-component.cpp
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
camera.o : camera.hpp camera.cpp
	$(CC) $(CPPFLAGS) -c camera.cpp
game.o : game.hpp game.cpp
	$(CC) $(CPPFLAGS) -c game.cpp
projectile.o : projectile.hpp projectile.cpp
	$(CC) $(CPPFLAGS) -c projectile.cpp
enemy.o : enemy.hpp enemy.cpp
	$(CC) $(CPPFLAGS) -c enemy.cpp
health-component.o : health-component.hpp health-component.cpp
	$(CC) $(CPPFLAGS) -c health-component.cpp
quadtree.o : quadtree.cpp quadtree.hpp
	$(CC) $(CPPFLAGS) -c quadtree.cpp
sword.o : sword.cpp sword.hpp
	$(CC) $(CPPFLAGS) -c sword.cpp
flying-component.o : flying-component.cpp flying-component.hpp
	$(CC) $(CPPFLAGS) -c flying-component.cpp
bird.o : bird.cpp bird.hpp
	$(CC) $(CPPFLAGS) -c bird.cpp
