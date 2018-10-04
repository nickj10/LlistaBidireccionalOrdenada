all: exercici1
	
main.o: main.c llista.h
	gcc -c main.c

llista.o: llista.c llista.h
	gcc -c llista.c

exercici1: main.o llista.o
	gcc main.o llista.o -o exercici1

clean: rm *.o exercici1
