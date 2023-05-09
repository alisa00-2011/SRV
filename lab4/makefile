all: main

main: main.o
		gcc lab4.o -o lab4
		
debug: debug.o
		gcc debug.o -o lab4_debug
		
debug.o: main.c
		gcc -g -c main.c -o debug.o
		
main.o:
		gcc -c lab4.c
		
clean:
		rm -rf *.o lab4 lab4_debug