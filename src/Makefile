PROJDIR=..
SRCDIR=$(PROJDIR)/src
BINDIR=$(PROJDIR)/bin
OBJDIR=$(PROJDIR)/obj
RESDIR=$(PROJDIR)/res
CC=g++
CFLAGS=-Wall -Wextra
EXECNAME=sfml-app
LIBSFML=-lsfml-graphics -lsfml-window -lsfml-system
OBJECT=main.o Jeu.o GraphicModule.o PhysicModule.o SystemModule.o Map.o MapGraphic.o MapPhysic.o GameComponent.o
RESOURCES=$(RESDIR)/*
COBJECT=$(addprefix $(OBJDIR)/, $(OBJECT))
CEXECNAME=$(addprefix $(BINDIR)/, $(EXECNAME))
MKDEP=g++ -MM
SRCS=$(SRCDIR)/*.cpp
HDRS=*.h

all: $(OBJDIR) $(BINDIR) $(CEXECNAME)
	cp $(RESOURCES) $(BINDIR)

$(CEXECNAME):$(COBJECT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBSFML)

$(OBJDIR):
	mkdir $(OBJDIR)

$(BINDIR):
	mkdir $(BINDIR)

.depend: $(SRCS) $(HDRS)
	$(MKDEP) $(SRCS) > .depend

-include .depend

$(OBJDIR)/%.o:$(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: install
install:
	sudo apt-get install libsfml-dev

.PHONY: clean
clean:
	rm -rf $(OBJDIR)

.PHONY: clear
clear: clean
	rm -rf $(BINDIR)
