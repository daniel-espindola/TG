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
    int u, v;
    int *trilha;
    grafo_t *G;

    /* Esperado: dois numeros indicando qtd vertices e de arestas */
    scanf("%d %d", &n, &m);
    G = cria_grafo(n, m);

    /* Esperado: m arestas dadas por dois inteiros cada: u, v */
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adiciona_aresta(G, u, v);
    }

    if (!eh_par(G)) {
        printf("Grafo dado nao eh par.\n");
    } else {
        /* Esperado: vertice inicial do Fleury */
        scanf("%d", &u);
        imprime_grafo(G);
        trilha = Fleury(G, u);
        for (v = 0; v < m; v++) {
            printf("%d, ", trilha[v]);
        }
        printf("%d\n", trilha[m]);
        free(trilha);
    }

    deleta_grafo(G);

    return 0;
}
