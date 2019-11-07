all:
	@(cd src && $(MAKE))

%:
	@(cd src && make $@)