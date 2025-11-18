#include "libprg/libprg.h"
#include <stdlib.h>

typedef struct no_arvore {
    int valor;
    struct no_arvore *esquerda;
    struct no_arvore *direita;
} no_arvore;

no_arvore* criar_no_arvore(int valor) {
    no_arvore *no = (no_arvore*)malloc(sizeof(no_arvore));
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

void destruir_no_arvore(no_arvore *no) {
    if (no != NULL) {
        destruir_no_arvore(no->esquerda);
        destruir_no_arvore(no->direita);
        free(no);
    }
}

no_arvore* inserir_valor_arvore(no_arvore *raiz, int valor) {
    if (raiz == NULL) {
        return criar_no_arvore(valor);
    } else if (valor < raiz->valor) {
        raiz->esquerda = inserir_valor_arvore(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_valor_arvore(raiz->direita, valor);
    }
    return raiz;
}