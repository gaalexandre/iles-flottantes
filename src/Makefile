PROJECT_DIR=..
SRC_DIR=$(PROJECT_DIR)/src
BIN_DIR=$(PROJECT_DIR)/bin
OBJ_DIR=$(PROJECT_DIR)/obj
RES_DIR=$(PROJECT_DIR)/res
MAP_DIR=$(RES_DIR)/Map
AUDIO_DIR=$(RES_DIR)/audio

HDR_EXT=.h
SRC_EXT=.cpp
OBJ_EXT=.o

CC=g++
CFLAGS=-Wall -Wextra -std=c++17
EXECNAME=sfml-app
LIBSFML=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

#OBJECT=main.o Jeu.o GraphicModule.o PhysicModule.o SystemModule.o Map.o MapGraphic.o MapPhysic.o GameComponent.o PhysicComponent.o Menu.o MenuGraphic.o MenuSystem.o
RESOURCES=$(shell cd $(RES_DIR); find -type f)
DIR_IN_RESOURCES=$(shell cd $(RES_DIR); find -type d)
AUDIORESOURCES=$(shell ls $(RES_DIR))
MAPRESOURCES=$(shell ls $(RES_DIR))
COBJECT=$(addprefix $(OBJ_DIR)/, $(OBJECT))
CEXECNAME=$(addprefix $(BIN_DIR)/, $(EXECNAME))
MKDEP=g++ -MM
SRCS=$(SRC_DIR)/*.cpp
HDRS=$(SRC_DIR)/*.h
OBJECT=$(shell ls *.cpp | sed s/\.cpp/.o/)

all: $(OBJ_DIR) $(BIN_DIR) $(CEXECNAME) copy_resources .depend

$(CEXECNAME):$(COBJECT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBSFML)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

.PHONY: copy_resources
copy_resources: $(addprefix $(BIN_DIR)/, $(DIR_IN_RESOURCES)) $(addprefix $(BIN_DIR)/, $(RESOURCES)) 

$(BIN_DIR)/%: $(RES_DIR)/%
	cp -r $< $@


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
