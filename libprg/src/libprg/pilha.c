#include <stdlib.h>
#include <libprg/libprg.h>

//struct está definido no header

//criar a pilha na memória
pilha* criar_pilha(int capacidade) {
    pilha *ponteiro = malloc(sizeof(pilha));
    ponteiro->elementos = malloc(sizeof(int) * capacidade);
    ponteiro->topo = -1;
    ponteiro->capacidade = capacidade;
    return ponteiro;
}

//adiciona elemento na pilha
int adicionar_elemento(pilha *ponteiro, int elemento) {
    if (ponteiro->topo < ponteiro->capacidade - 1) {
        ponteiro->topo++;
        ponteiro->elementos[ponteiro->topo] = elemento;
        return 1;
    } else {
        return 0;
    }
}

//remover elemento da pilha
int remove_elemento(pilha *ponteiro) {
    if (ponteiro->topo >= 0) {
        int elemento = ponteiro->elementos[ponteiro->topo];
        ponteiro->topo--;
        return elemento;
    }
    else {
        return -1;
    }
}

//mostra o topo da pilha
int mostrar_topo(pilha *ponteiro) {
    if (ponteiro->topo >= 0) {
        return ponteiro->elementos[ponteiro->topo];
    } else {
        //se a pilha estiver vazia
        return -1;
    }
}

//mostrar pilha
int* mostra_pilha(pilha *ponteiro) {
    int* elementos_copia = malloc(sizeof(int) * (ponteiro->topo + 1));
    for (int i = 0; i <= ponteiro->topo; i++) {
        elementos_copia[i] = ponteiro->elementos[i];
    }
    return elementos_copia;
}

//destruir pilha
void destruir_pilha(pilha *ponteiro) {
    free(ponteiro->elementos);
    free(ponteiro);
}


