/***********************************************************
 *
 * Autor: Daniel Espindola da Silva, RA: 11201720556
 *
 * Referências utilizadas: https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
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
    grafo_t *grafo = malloc(sizeof(grafo_t));
    grafo->n = n;
    grafo->m = m;

    grafo->adj = (int **)calloc(n,(sizeof(int *)));

    for(int i=0; i<n; i++)
      grafo->adj[i] = (int *)calloc(n,sizeof(int));

    return grafo;
}

/* adiciona_aresta:
 *    - recebe um grafo G, e dois vértices u e v
 *    - adiciona a aresta uv no grafo 
 */
void adiciona_aresta(grafo_t *G, int u, int v) {
   G->m++;
   G->adj[u][v] = 1;
   G->adj[v][u] = 1;
}

/* imprime_grafo:
 *    - recebe um grafo G
 *    - imprime a vizinhança de cada vértice de G no formato:
 *          v: a b c d e
 */
void imprime_grafo(grafo_t *G) {
    int n = G->n;

    for(int i=0; i<n; i++) {
        printf("%d:",i);
        for(int j=n;j>-1; j--){
            if(G->adj[i][j] == 1)
                printf(" %d",j);
        }
        printf("\n");
    }
}

void remove_aresta(grafo_t *G, int u, int v) {
    G->m--;
    G->adj[u][v] = 0;
    G->adj[v][u] = 0;
}

/* deleta_grafo:
 *    - recebe um grafo G
 *    - desaloca memória utilizada por G 
 */
void deleta_grafo(grafo_t *G) {
    int n = G->n;

    for(int i=0; i<n; i++)
        free(G->adj[i]);
    free(G->adj);
    free(G);
}

/* grau:
 *    - recebe um grafo G e um vértice v
 *    - retorna o grau de v
 */
int grau(grafo_t *G, int v) {
    int vg =0;

    for(int i=0; i<G->n;i++)
        vg+=G->adj[v][i];

    return vg;
}

/* grau_maximo:
 *    - recebe um grafo G
 *    - retorna o grau máximo de G
 */
int grau_maximo(grafo_t *G) {
    int vgMax = 0;

    for(int i=0; i<G->n; i++)
        vgMax = vgMax > grau(G,i) ? vgMax : grau(G,i);
    return vgMax;
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
