CC=g++
CFLAGS=-Wall -Wextra
EXECNAME=sfml-app
LIBSFML=-lsfml-graphics -lsfml-window -lsfml-system



all: $(EXECNAME)



$(EXECNAME):main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBSFML)

%.o:%.c
	$(CC) $(CFLAGS) -c $<


install:
	sudo apt-get install libsfml-dev

clean:
	rm -rf *.o

clear: clean
	rm -rf $(EXECNAME)
