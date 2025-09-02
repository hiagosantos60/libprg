#ifndef LIBPRG_H
#define LIBPRG_H

typedef struct pilha {
    int *elementos;
    int topo;
    int capacidade;
} pilha;

pilha* criar_pilha(int capacidade);
int empilhar(pilha *ponteiro, int elemento);
int remove_elemento(pilha* ponteiro);
int mostrar_topo(pilha *ponteiro);
int* mostra_pilha(pilha *ponteiro);
void destruir_pilha(pilha* ponteiro);

#endif // LIBPRG_H



