#ifndef LIBPRG_H
#define LIBPRG_H

typedef struct pilha pilha_t;

pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t *ponteiro, int elemento);
int desempilhar(pilha_t *ponteiro);
int mostrar_topo_pilha(pilha_t *ponteiro);
int* mostra_pilha(pilha_t *ponteiro);
void destruir_pilha(pilha_t* ponteiro);

#endif