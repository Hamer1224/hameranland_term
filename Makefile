OBJ = core.c utils.c screen.c
APPNAME = test_app

compile:
	echo "Starting to compile"
	gcc $(OBJ) -o  $(APPNAME) `pkg-config --cflags --libs gtk+-3.0`

run: compile
	./$(APPNAME)

clean:
	rm -f $(APPNAME)