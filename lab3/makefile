all: main

main: client.o server.o
	gcc client.o -o client
	gcc server.o -o server
	
debug: debug.o
	gcc server_d.o -o server_debug
	gcc client_d.o -o client_debug
	
debug.o:
	gcc -g -c server.c -o server_d.o
	gcc -g -c client.c -o client_d.o
	
main.o:
	gcc -c client.c
	gcc -c server.c
	
clean:
	rm -rf *.o client server client_debug server_debug