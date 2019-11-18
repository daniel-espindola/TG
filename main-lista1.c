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
    int n, m;
    int u, v;
    int *visitados;
    grafo_t *G;

    /* Esperado: dois nÃºmeros indicando qtd vÃ©rtices e de arestas */
    scanf("%d %d", &n, &m);
    G = cria_grafo(n, m);

    /* Esperado: m arestas dadas por dois inteiros cada: u, v */
    while (m--) {
        scanf("%d %d", &u, &v);
        adiciona_aresta(G, u, v);
    }

    printf("O seguinte grafo foi recebido:\n");
    imprime_grafo(G);

    printf("\nEle tem grau maximo %d.\n", grau_maximo(G));

    /* Esperado: vÃ©rtice inicial da busca */
    scanf("%d", &u);
    printf("\nAplicando a DFS a partir de %d:\n", u);

    visitados = DFS(G, u);
    for (v = 0; v < n; v++) {
        if (visitados[v])
            printf("%d foi visitado;\n", v);
        else
            printf("%d nao foi visitado;\n", v);
    }
    
    /* Esperado: nÃºmero de arestas a serem testadas para corte */
    printf("\n");
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &u, &v);
        if (eh_aresta_corte(G, u, v))
            printf("A aresta (%d,%d) eh de corte.\n", u, v);
        else
            printf("A aresta (%d,%d) nao eh de corte.\n", u, v);
    }

    deleta_grafo(G);

    return 0;
}
