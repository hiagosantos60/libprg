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

