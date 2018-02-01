befunge: dynamic_stack

static_stack: staticmake mainmake
	clang build/stack.o build/driver.o -o befunge

dynamic_stack: dynamicmake mainmake
	clang build/stack.o build/driver.o -o befunge

linked_stack: linkedmake mainmake
	clang build/stack.o build/driver.o -o befunge

staticmake: mkbuild stacks/static_stack.c
	clang -std=c99 -g -c -o build/stack.o -Wall stacks/static_stack.c

dynamicmake: mkbuild stacks/dynamic_stack.c
	clang -std=c99 -g -c -o build/stack.o -Wall stacks/dynamic_stack.c

linkedmake:
	clang -std=c99 -g -c -o build/stack.o -Wall stacks/linked_stack.c

mainmake: mkbuild main.c
	clang -g -c -o build/driver.o -Wall main.c

debug_mainmake: mkbuild main.c
	clang -g -c -o build/driver.o -Wall main.c -DDEBUG

mkbuild:
	mkdir -p build

clean:
	rm -rf build/*.o
