/**********************************************************
 * Created: Sun 29 Sep 2019 07:00:26 PM -03
 *
 * Author: Carla N. Lintzmayer, carla.negri@ufabc.edu.br
 *
 **********************************************************/
 
 
#ifndef __GRAFO_H
#define __GRAFO_H

typedef struct grafo grafo_t;

/* cria_grafo:
 *    - recebe numero n de vertices e m de arestas
 *    - devolve um novo grafo vazio (aloca memoria necessaria)
 */
grafo_t* cria_grafo(int n, int m);

/* adiciona_aresta:
 *    - recebe um grafo G, e dois vertices u e v
 *    - adiciona a aresta uv no grafo 
 */
void adiciona_aresta(grafo_t *G, int u, int v);

/* imprime_grafo:
 *    - recebe um grafo G
 *    - imprime a vizinhanca de cada vertice de G
 */
void imprime_grafo(grafo_t *G);

/* deleta_grafo:
 *    - recebe um grafo G
 *    - desaloca memoria utilizada por G 
 */
void deleta_grafo(grafo_t *G);

/* grau:
 *    - recebe um grafo G e um vertice v
 *    - retorna o grau de v
 */
int grau(grafo_t *G, int v);

/* grau_maximo:
 *    - recebe um grafo G
 *    - retorna o grau maximo de G
 */
int grau_maximo(grafo_t *G);

/* DFS:
 *    - recebe um grafo G e um vertice s
 *    - aplica a busca em profundidade em G a partir de s
 *
 *      DFS(G, s)
 *          marque todos os vertices como nao visitados
 *          DSFRec(G, s)
 *
 *      DFSRec(G, s)
 *          marque s como visitado
 *          para todo vizinho v de s
 *              se v nao esta visitado
 *                  DFSRec(G, v)
 *
 *      (explicacao completa da busca em profundidade: Secao 20.2 de http://professor.ufabc.edu.br/~carla.negri/cursos/materiais/Livro-Analise.de.Algoritmos.pdf)
 *
 *    - retorna um vetor indexado por vertices que indica se um vertice foi visitado ou nao */
int* DFS(grafo_t *G, int s);

/* eh_aresta_corte:
 *    - recebe um grafo G e dois vertices u e v
 *    - retorna 0 se a aresta uv nao e de corte
 *    - retorna 1 caso contrario
 *    (utilize a funcao DFS)
 */
int eh_aresta_corte(grafo_t *G, int u, int v);

/* eh_par:
 *    - recebe um grafo G
 *    - retorna 1 se G e impar
 *    - retorna 0 caso contrario
 */
int eh_par(grafo_t *G);

/* Fleury:
 *    - recebe um grafo G *PAR* e um vertice v
 *    - retorna um vetor que contem a sequencia de vertices de uma trilha euleriana em G
 *      - em particular, esse vetor contem v na primeira e ultima posicoes
 *    - IMPORTANTE: quando houver dois ou mais vertices possiveis de serem escolhidos, comece pelo de menor indice
 */
int* Fleury(grafo_t *G, int v);
 
#endif /* __GRAFO_H */

