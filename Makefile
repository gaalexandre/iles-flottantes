CC=g++
CFLAGS=-Wall -Wextra
EXECNAME=sfml-app
LIBSFML=-lsfml-graphics -lsfml-window -lsfml-system
OBJECT=main.o Jeu.o GraphicModule.o PhysicModule.o SystemModule.o Map.o MapGraphic.o MapPhysic.o GameComponent.o
MKDEP=g++ -MM -o .depend
SRCS=*.cpp
HDRS=*.h

all: $(EXECNAME)

$(EXECNAME):$(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBSFML)

.depend: $(SRCS) $(HDRS)
	$(MKDEP) $(CFLAGS) $(SRCS)

-include .depend

%.o:%.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: install
install:
	sudo apt-get install libsfml-dev

.PHONY: clean
clean:
	rm -rf *.o

.PHONY: clear
clear: clean
	rm -rf $(EXECNAME)
	rm .depend
