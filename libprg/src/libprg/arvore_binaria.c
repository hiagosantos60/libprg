#include "libprg/libprg.h"
#include <stdlib.h>

typedef struct no_arvore {
    int valor;
    struct no_arvore *esquerda;
    struct no_arvore *direita;
} no_arvore;

