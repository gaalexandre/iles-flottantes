PROJECT_DIR=..
SRC_DIR=$(PROJECT_DIR)/src
BIN_DIR=$(PROJECT_DIR)/bin
OBJ_DIR=$(PROJECT_DIR)/obj
RES_DIR=$(PROJECT_DIR)/res

HDR_EXT=.h
SRC_EXT=.cpp
OBJ_EXT=.o

CC=g++
CFLAGS=-Wall -Wextra -std=c++17
EXECNAME=sfml-app
LIBSFML=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

#OBJECT=main.o Jeu.o GraphicModule.o PhysicModule.o SystemModule.o Map.o MapGraphic.o MapPhysic.o GameComponent.o PhysicComponent.o
RESOURCES=$(shell ls $(RES_DIR))
COBJECT=$(addprefix $(OBJ_DIR)/, $(OBJECT))
CEXECNAME=$(addprefix $(BIN_DIR)/, $(EXECNAME))
MKDEP=g++ -MM
SRCS=$(SRC_DIR)/*.cpp
HDRS=$(SRC_DIR)/*.h
OBJECT=$(shell ls *.cpp | sed s/\.cpp/.o/)

all: $(OBJ_DIR) $(BIN_DIR) $(CEXECNAME) $(addprefix $(BIN_DIR)/, $(RESOURCES)) .depend

$(CEXECNAME):$(COBJECT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBSFML)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%: $(RES_DIR)/%
	cp -r  $< $@

.depend: $(SRCS) $(HDRS)
	rm -f .depend; \
	for file in $(SRCS) ; do \
		echo "$(OBJ_DIR) \\" >> .depend ; \
		$(MKDEP) $$file >> .depend ; \
	done

-include .depend

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: install
install:
	sudo apt-get install libsfml-dev

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) .depend

.PHONY: clear
clear: clean
	rm -rf $(BIN_DIR)

.PHONY: run
run: all
	@(cd $(BIN_DIR) && ./$(EXECNAME))
