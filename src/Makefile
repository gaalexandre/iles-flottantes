PROJDIR=..
SRCDIR=$(PROJDIR)/src
BINDIR=$(PROJDIR)/bin
OBJDIR=$(PROJDIR)/obj
RESDIR=$(PROJDIR)/res
CC=g++
CFLAGS=-Wall -Wextra -std=c++17
EXECNAME=sfml-app
LIBSFML=-lsfml-graphics -lsfml-window -lsfml-system

OBJECT=main.o Jeu.o GraphicModule.o PhysicModule.o SystemModule.o Map.o MapGraphic.o PhysicComponent.o MapPhysic.o GameComponent.o Perso.o PersoGraphic.o PlayerPhysic.o PersoSystem.o MapPhysic.o 

RESOURCES=$(shell ls $(RESDIR))
COBJECT=$(addprefix $(OBJDIR)/, $(OBJECT))
CEXECNAME=$(addprefix $(BINDIR)/, $(EXECNAME))
MKDEP=g++ -MM
SRCS=$(SRCDIR)/*.cpp
HDRS=*.h

all: $(OBJDIR) $(BINDIR) $(CEXECNAME) $(addprefix $(BINDIR)/, $(RESOURCES))

$(CEXECNAME):$(COBJECT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBSFML)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR) -p

$(BINDIR)/%: $(RESDIR)/%
	cp $< $@

.depend: $(SRCS) $(HDRS)
	rm -f .depend; \
	for file in $(SRCS) ; do \
		echo "$(OBJDIR) \\" >> .depend ; \
		$(MKDEP) $$file >> .depend ; \
	done

-include .depend

$(OBJDIR)/%.o:$(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: install
install:
	sudo apt-get install libsfml-dev

.PHONY: clean
clean:
	rm -rf $(OBJDIR) .depend

.PHONY: clear
clear: clean
	rm -rf $(BINDIR)

.PHONY: run
run: all
	@(cd $(BINDIR) && ./$(EXECNAME))
