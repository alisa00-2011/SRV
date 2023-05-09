all: main
main: main.o
	gcc main.o -o main
debug: debug.o
	gcc debug.o -o main_debug
debug.o: main.c
	gcc -g -c main.c -o debug.o
main.o:
	gcc -c main.c
clean:
	rm -f *.o main main_debug
