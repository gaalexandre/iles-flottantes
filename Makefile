all:sfml-app

install:
	sudo apt-get install libsfml-dev

sfml-app:main.o
	g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

%.o:%.c
	g++ -c main.c


