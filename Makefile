static_stack: staticmake mainmake
	ld stack.o driver.o -o befunge

staticmake: stacks/static_stack.c
	gcc -g -c -o stack.o -Wall stacks/static_stack.c

mainmake: main.c
	gcc -g -c -o driver.o -Wall main.c
