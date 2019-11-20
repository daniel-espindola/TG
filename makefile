main: grafo.o heap.o
	gcc main.c -g grafo.o heap.o -o main

clean:
	rm *.o

