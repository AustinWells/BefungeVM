static_stack: staticmake mainmake
	gcc build/stack.o build/driver.o -o befunge

dynamic_stack: dynamicmake mainmake
	gcc build/stack.o build/driver.o -o befunge

staticmake: stacks/static_stack.c
	gcc -g -c -o build/stack.o -Wall stacks/static_stack.c

dynamicmake: stacks/dynamic_stack.c
	gcc -g -c -o build/stack.o -Wall stacks/dynamic_stack.c

mainmake: main.c
	gcc -g -c -o build/driver.o -Wall main.c

clean:
	rm -rf build/*.o
