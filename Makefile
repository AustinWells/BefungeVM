befunge: dynamic_stack

static_stack: staticmake mainmake
	gcc build/stack.o build/driver.o -o befunge
	while(true); do sleep 100 & done

dynamic_stack: dynamicmake mainmake
	gcc build/stack.o build/driver.o -o befunge

linked_stack: linkedmake debug_mainmake
	gcc build/stack.o build/driver.o -o befunge

staticmake: mkbuild stacks/static_stack.c
	gcc -std=c99 -g -c -o build/stack.o -Wall stacks/static_stack.c

dynamicmake: mkbuild stacks/dynamic_stack.c
	gcc -std=c99 -g -c -o build/stack.o -Wall stacks/dynamic_stack.c

linkedmake:
	gcc -std=c99 -g -c -o build/stack.o -Wall stacks/linked_stack.c

mainmake: mkbuild main.c
	gcc -g -c -o build/driver.o -Wall main.c

debug_mainmake: mkbuild main.c
	gcc -g -c -o build/driver.o -Wall main.c -DDEBUG


mkbuild:
	mkdir -p build

clean:
	rm -rf build/*.o
