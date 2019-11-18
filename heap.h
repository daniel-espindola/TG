/**********************************************************
 * Created: Mon 04 Nov 2019 08:47:06 PM -03
 *
 * Author: Carla N. Lintzmayer, carla.negri@ufabc.edu.br
 *
 **********************************************************/


#ifndef __HEAP_H
#define __HEAP_H

typedef struct heap heap_t;

/**************************************
 *
 * Essa estrutura armazena um elemento e sua prioridade por meio de um par
 * (rotulo, valor_prioridade).
 *
 * Aqui, um elemento tem maior prioridade quanto menor for seu valor_prioridade.
 * 
 * Espera-se que os rotulos sejam valores entre 0 e n-1, onde n eh a quantidade
 * de elementos armazenados na estrutura. *
 *
 **************************************/

/* Cria uma heap que ira armazenar *capacidade* elementos
 * Inicialmente ela estah vazia */
heap_t* cria_heap(int capacidade);

/* Devolve 0 se a heap estiver vazia */
int heap_vazia(heap_t* heap);

/* Adiciona um elemento de rotulo *elem* com prioridade *valor_pri* */
void adiciona_na_heap(heap_t* heap, int elem, int valor_pri);

/* Devolve o valor de prioridade do elemento de maior prioridade armazenado */
int maior_prioridade(heap_t* heap);

/* Devolve o valor de prioridade do elemento *elem* */
int prioridade_elemento(heap_t* heap, int elem);

/* Remove o elemento de maior prioridade e devolve seu rotulo */
int remove_da_heap(heap_t* heap);

/* Devolve a posicao em que *elem* esta armazenado */
int posicao_na_heap(heap_t* heap, int elem);

/* Altera o valor de prioridade do elemento armazenado na posicao *pos* */
void altera_heap(heap_t* heap, int pos, int novo_valor_pri);

/* Libera memoria alocada */
void deleta_heap(heap_t* heap); 

/* Imprime o conteudo da heap */
void imprime_heap(heap_t* heap);

#endif /* __GRAFO_H */
