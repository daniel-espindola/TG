/**********************************************************
 * Created: Mon 04 Nov 2019 08:47:06 PM -03
 *
 * Author: Carla N. Lintzmayer, carla.negri@ufabc.edu.br
 *
 **********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

typedef struct node {
    int rotulo;
    int prioridade;
} node_t;

struct heap {
    int capacidade;
    int tamanho;
    int* posicoes;
    node_t* fila;
};

int heap_vazia(heap_t* heap) {
    return heap->tamanho == 0;
}

int maior_prioridade(heap_t* heap) {
    return heap->fila[0].prioridade;
}

int prioridade_elemento(heap_t* heap, int elem) {
    return heap->fila[heap->posicoes[elem]].prioridade;
}

void imprime_heap(heap_t* heap) {
    for (int i = 0; i < heap->tamanho; i++) {
        printf("elem %d, prior %d\n", heap->fila[i].rotulo, heap->fila[i].prioridade);
    }
}

void corrige_descendo(heap_t* heap, int pai) {
    int esq = pai*2 + 1;
    int dir = pai*2 + 2;
    int rotulo, prioridade;
    int min = pai;

    if (esq < heap->tamanho && heap->fila[esq].prioridade < heap->fila[min].prioridade)
        min = esq;
    if (dir < heap->tamanho && heap->fila[dir].prioridade < heap->fila[min].prioridade)
        min = dir;

    if (min != pai) {
        heap->posicoes[heap->fila[pai].rotulo] = min;
        heap->posicoes[heap->fila[min].rotulo] = pai;

        rotulo = heap->fila[min].rotulo;
        heap->fila[min].rotulo = heap->fila[pai].rotulo;
        heap->fila[pai].rotulo = rotulo;

        prioridade = heap->fila[min].prioridade;
        heap->fila[min].prioridade = heap->fila[pai].prioridade;
        heap->fila[pai].prioridade = prioridade;

        corrige_descendo(heap, min);
    }
}

void corrige_subindo(heap_t* heap, int pos) {
    int rotulo, prioridade;
    int pai = (pos-1)/2;
    
    if (pai >= 0 && heap->fila[pai].prioridade > heap->fila[pos].prioridade) {
        heap->posicoes[heap->fila[pai].rotulo] = pos;
        heap->posicoes[heap->fila[pos].rotulo] = pai;

        rotulo = heap->fila[pai].rotulo;
        heap->fila[pai].rotulo = heap->fila[pos].rotulo;
        heap->fila[pos].rotulo = rotulo;

        prioridade = heap->fila[pai].prioridade;
        heap->fila[pai].prioridade = heap->fila[pos].prioridade;
        heap->fila[pos].prioridade = prioridade;

        corrige_subindo(heap, pai);
    }
}

heap_t* cria_heap(int capacidade) {
    heap_t* heap = malloc(sizeof(heap_t));
    heap->fila = malloc(capacidade * sizeof(node_t));
    heap->posicoes = malloc(capacidade * sizeof(int));
    heap->capacidade = capacidade;
    heap->tamanho = 0; 
    return heap;
}

void adiciona_na_heap(heap_t* heap, int elem, int valor_pri) {
    if (heap->capacidade != heap->tamanho) {
        heap->fila[heap->tamanho].rotulo = elem;
        heap->fila[heap->tamanho].prioridade = valor_pri;
        heap->posicoes[elem] = heap->tamanho;
        heap->tamanho++;
        corrige_subindo(heap, heap->tamanho-1);
    }
}

int remove_da_heap(heap_t* heap) {
    int pop_rotulo;
    int pop_prioridade;

    if (heap->tamanho == 0) {
        return -1;
    }

    heap->posicoes[heap->fila[0].rotulo] = heap->tamanho-1;
    heap->posicoes[heap->fila[heap->tamanho-1].rotulo] = 0;

    pop_rotulo = heap->fila[0].rotulo;
    heap->fila[0].rotulo = heap->fila[heap->tamanho-1].rotulo;
    heap->fila[heap->tamanho-1].rotulo = pop_rotulo;

    pop_prioridade = heap->fila[0].prioridade;
    heap->fila[0].prioridade = heap->fila[heap->tamanho-1].prioridade;
    heap->fila[heap->tamanho-1].prioridade = pop_prioridade;

    heap->tamanho--;
    corrige_descendo(heap, 0);

    return pop_rotulo;
}

int posicao_na_heap(heap_t* heap, int elem) {
    return heap->posicoes[elem];
}

void altera_heap(heap_t* heap, int pos, int novo_valor_pri) {
    int prioridade_atual = heap->fila[pos].prioridade;
    heap->fila[pos].prioridade = novo_valor_pri;
    if (prioridade_atual > novo_valor_pri)
        corrige_subindo(heap, pos);
    else
        corrige_descendo(heap, pos);
}

void deleta_heap(heap_t* heap) {
    free(heap->fila);
    free(heap->posicoes);
    free(heap);
}
