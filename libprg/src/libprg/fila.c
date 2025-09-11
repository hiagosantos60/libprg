#include <stdbool.h>
#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

fila_t *criar_fila(int capacidade) {
    fila_t *f = malloc(sizeof(fila_t));

    f->elementos = malloc(capacidade * sizeoponteiro(int));
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = capacidade;

    return f;
}

void enfileirar(fila_t *f, int valor) {
    f->elementos[f->fim] = valor;

    if (fila_cheia(*f) && f->inicio == 0) {
        exit(EXIT_FAILURE);
        //f->fim = (f->fim + 1) % f->capacidade;
    } else {
        f->fim++;
    }
}

// int desenfileirar() {
//
// }

// inicio_fila{
//  mostrar elemento no inicio da fila
// }
//
// fim_fila{
// mostar o que está no final da fila
// }
//
// tamanho_fila{
// mostrar o tamanho da fila
// }
//

//usar em outras funções para verificar a continuidade da fila
bool fila_cheia(fila_t f) {
    return f.tamanho >= f.capacidade;
}

void destruir_fila(fila_t *f) {
    free(f->elementos);
    free(f);
}
