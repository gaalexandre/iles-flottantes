CC=g++
CFLAGS=-Wall -Wextra
EXECNAME=sfml-app
LIBSFML=-lsfml-graphics -lsfml-window -lsfml-system
OBJECT=main.o Jeu.o GraphicModule.o PhysicModule.o SystemModule.o Map.o MapGraphic.o MapPhysic.o GameComponent.o

all: $(EXECNAME)

$(EXECNAME):$(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBSFML)

%.o:%.cpp
	$(CC) $(CFLAGS) -c $<

install:
	sudo apt-get install libsfml-dev

clean:
	rm -rf *.o

clear: clean
	rm -rf $(EXECNAME)
