
main1: grafo.o
	gcc main-lista1.c grafo.o -o main1

main2: grafo.o
	gcc main-lista2.c grafo.o -o main2

main3: grafo.o heap.o
	gcc main-lista3.c grafo.o heap.o -o main3

clean:
	rm *.o

