static_stack: staticmake mainmake
	gcc build/stack.o build/driver.o -o befunge

dynamic_stack: dynamicmake mainmake
	gcc build/stack.o build/driver.o -o befunge

staticmake: mkbuild stacks/static_stack.c
	gcc -g -c -o build/stack.o -Wall stacks/static_stack.c

dynamicmake: mkbuild stacks/dynamic_stack.c
	gcc -g -c -o build/stack.o -Wall stacks/dynamic_stack.c

mainmake: mkbuild main.c
	gcc -g -c -o build/driver.o -Wall main.c

mkbuild:
	mkdir build

clean:
	rm -rf build/*.o
