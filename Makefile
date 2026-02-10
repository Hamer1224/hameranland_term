OBJ = core.c utils.c
APPNAME = test_app

compile:
	echo "Starting to compile"
	gcc $(OBJ) -o  $(APPNAME)

$(APPNAME):
	./$@

clean:
	rm -f $(APPNAME)