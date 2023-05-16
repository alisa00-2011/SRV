all: main

main: main.o
		gcc lab5.o -o lab5
		
debug: debug.o
		gcc debug.o -o lab5_debug
		
debug.o: lab5.c
		gcc -g -c lab5.c -o debug.o
		
main.o:
		gcc -c lab5.c
		
clean:
		rm -rf *.o lab5 lab5_debug
