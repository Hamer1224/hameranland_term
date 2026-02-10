OBJ = core.c utils.c screen.c
APPNAME = ide

compile:
	@echo "Starting to compile"
	gcc `pkg-config --cflags gtk+-3.0 gtksourceview-3.0` $(OBJ) -o $(APPNAME) `pkg-config --libs gtk+-3.0 gtksourceview-3.0`

run: clean compile
	./$(APPNAME)

clean:
	rm -f $(APPNAME) build.log temp.c