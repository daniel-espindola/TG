/***********************************************************
 * Created: Sun 29 Sep 2019 19:10:42 PM -03
 *
 * Author: Carla N. Lintzmayer, carla.negri@ufabc.edu.br
 *
 ***********************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(int argc, char *argv[]) {
    int n, m, i;
    int u, v, w;
    int *distancia;
    int **pesos;
    grafo_t *G;

    /* Esperado: dois numeros indicando qtd vertices e de arestas */
    scanf("%d %d", &n, &m);
    G = cria_grafo(n, m);

    /*  Matriz para armazenar os pesos das arestas */
    pesos = malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++) {
        pesos[i] = malloc(sizeof(int) * n);
    }

    /* Esperado: m arestas dadas por tres inteiros cada: u, v, w */
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adiciona_aresta(G, u, v);
        pesos[u][v] = w;
        pesos[v][u] = w;
    }

    /* Esperado: vertice inicial do Dijkstra */
    scanf("%d", &u);

    distancia = Dijkstra(G, u, pesos);
    for (v = 0; v < n; v++) {
        printf("distancia de %d a %d = %d\n", u, v, distancia[v]);
    }
    deleta_grafo(G);
    for (i = 0; i < n; i++)
        free(pesos[i]);
    free(pesos);

    return 0;
}
