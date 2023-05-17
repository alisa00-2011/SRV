all: main

main: main.o
		gcc lab7.o -o lab7
		
debug: debug.o
		gcc debug.o -o lab7_debug
		
debug.o: lab7.c
		gcc -g -c lab7.c -o debug.o
		
main.o:
		gcc -c lab7.c
		
clean:
		rm -rf *.o lab7 lab7_debug