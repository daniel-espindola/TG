/***********************************************************
 *
 * Autor: Daniel Espindola da Silva, RA: 11201720556
 *
 * Referências utilizadas:
 *
 ***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct grafo
{ 
    int n; // numero de vértices
    int m; // numero de arestas
    int ** adj; // matriz de adjancecia 
};

/* cria_grafo:
 *    - recebe número n de vértices e m de arestas
 *    - devolve um novo grafo vazio (aloca memória necessária)
 */
grafo_t* cria_grafo(int n, int m) {
    grafo_t grafo;
    grafo.n = n;
    grafo.m = m;

    grafo.adj = (int **)malloc(n*(sizeof(int *)));

    for(int i=0; i<n; i++)
      grafo.adj[i] = (int *)malloc(n*sizeof(int));

    return grafo;
}

/* adiciona_aresta:
 *    - recebe um grafo G, e dois vértices u e v
 *    - adiciona a aresta uv no grafo 
 */
void adiciona_aresta(grafo_t *G, int u, int v) {
    /* IMPLEMENTE-ME */
}

/* imprime_grafo:
 *    - recebe um grafo G
 *    - imprime a vizinhança de cada vértice de G no formato:
 *          v: a b c d e
 */
void imprime_grafo(grafo_t *G) {
    /* IMPLEMENTE-ME */
}

void remove_aresta(grafo_t *G, int u, int v) {
    /* IMPLEMENTE-ME */
}

/* deleta_grafo:
 *    - recebe um grafo G
 *    - desaloca memória utilizada por G 
 */
void deleta_grafo(grafo_t *G) {
    /* IMPLEMENTE-ME */
}

/* grau:
 *    - recebe um grafo G e um vértice v
 *    - retorna o grau de v
 */
int grau(grafo_t *G, int v) {
    /* IMPLEMENTE-ME */
    return 0;
}

/* grau_maximo:
 *    - recebe um grafo G
 *    - retorna o grau máximo de G
 */
int grau_maximo(grafo_t *G) {
    /* IMPLEMENTE-ME */
    return 0;
}

/* DFS:
 *    - recebe um grafo G e um vértice s
 *    - aplica a busca em largura em G a partir de s
 *    - retorna um vetor indexado por vértices que indica se um vértice foi visitado ou não
 */
int* DFS(grafo_t *G, int s) {
    /* IMPLEMENTE-ME */
    return NULL;
}

/* eh_aresta_corte:
 *    - recebe um grafo G e dois vértices u e v
 *    - retorna 0 se a aresta uv não é de corte
 *    - retorna 1 caso contrário
 *    (utilize a função DFS)
 */
int eh_aresta_corte(grafo_t *G, int u, int v) {
    /* IMPLEMENTE-ME */
    return 0;
}
