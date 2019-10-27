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
int FleuryAux(grafo_t *G, int v, int *trilha, int k);
int* DFSRec(grafo_t *G, int s, int* visitados);

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
   G->adj[u][v]++;
   G->adj[v][u]++;
}

/* imprime_grafo:
 *    - recebe um grafo G
 *    - imprime a vizinhança de cada vértice de G no formato:
 *          v: a b c d e
 */
void imprime_grafo(grafo_t *G) {
    int n = G->n;
    int k = 0;

    for(int i=0; i<n; i++) {
        printf("%d:",i);
        for(int j=0;j<n; j++){
            k = 0;
            while(G->adj[i][j]>k){
                printf(" %d",j);
                k++;
            }
        }
        printf("\n");
    }
}

void remove_aresta(grafo_t *G, int u, int v) {
    G->m--;
    G->adj[u][v]--;
    G->adj[v][u]--;
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
    int * visitados = calloc(G->n, sizeof(int));

    return DFSRec(G,s,visitados);
}

int* DFSRec(grafo_t *G, int s, int* visitados){
    visitados[s] = 1;

    for(int i=0; i<G->n; i++) {
        if(G->adj[s][i] > 0 && visitados[i] == 0) // é vizinho de 's' e ainda não foi visitado 
            DFSRec(G, i, visitados);
    }

    return visitados;
}

/* eh_aresta_corte:
 *    - recebe um grafo G e dois vértices u e v
 *    - retorna 0 se a aresta uv não é de corte
 *    - retorna 1 caso contrário
 *    (utilize a função DFS)
 */
int eh_aresta_corte(grafo_t *G, int u, int v) {
    int * visitados1 = DFS(G,u);
    
    G->adj[u][v]--;
    G->adj[v][u]--;
    int * visitados2 = DFS(G,u);

    G->adj[u][v]++;
    G->adj[v][u]++;
    for(int i=0; i<G->n; i++) {
        if(visitados1[i] != visitados2[i]){
            free(visitados1);
            free(visitados2);
            return 1;
        }
    }

    free(visitados1);
    free(visitados2);
    return 0;
}

int eh_par(grafo_t *G) {
    for(int i=0; i<G->n; i++){
        if((grau(G,i) % 2) != 0)
            return 0;
    }
    return 1;
}

/* Fleury:
 *    - recebe um grafo G *PAR* e um vertice v
 *    - retorna um vetor que contem a sequencia de vertices de uma trilha euleriana em G
 *      - em particular, esse vetor contem v na primeira e ultima posicoes
 *    - IMPORTANTE: quando houver dois ou mais vertices possiveis de serem escolhidos, comece pelo de menor indice
 */
int* Fleury(grafo_t *G, int v) {
    int* trilha = calloc(sizeof(int),(G->n)+1);
    int k = 1;
    trilha[0] = v;
    int aux = v;
    int m = G->m;

    for(int i=0;i<m;i++){
        aux = FleuryAux(G,aux,trilha,k);
        k++;
    }
    
    trilha[k] = v;
    exit(404);
    //return trilha;
}

int eh_aresta(grafo_t *G, int v, int u){
    if(G->adj[u][v] >0)
       return 1;
    return 0;
}

int FleuryAux(grafo_t *G, int v, int *trilha, int k){
    for(int i=0; i < G->n;i++){
        printf("\n(%d,%d) = %d, %d |",v,i,eh_aresta(G,v,i),!eh_aresta_corte(G,v,i));
        if(eh_aresta(G,v,i) && !eh_aresta_corte(G,v,i)) {
            printf("**%d**\n",k);
            trilha[k] = i;
            remove_aresta(G, v, i);
            return i;
        }
    }
    return 0;
}