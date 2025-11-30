#include <math.h>
#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct arvore_avl_t {
    int valor;
    int altura;
    struct arvore_avl_t *esquerda;
    struct arvore_avl_t *direita;
} no_avl_t;

no_avl_t* criar_arvore_avl(int valor, int altura) {
    no_avl_t* u = (no_avl_t*) malloc(sizeof(no_avl_t));
    u->valor = valor;
    u->altura = altura;
    u->esquerda = NULL;
    u->direita = NULL;
    return u;
}

no_avl_t* rotacao_avl_esquerda(no_avl_t* v) {
    no_avl_t* u = v->direita;
    v->direita = u->esquerda;
    u->esquerda = v;

    v->altura = max(altura_arvore_avl(v->esquerda), altura_arvore_avl(v->direita)) + 1;
    u->altura = max(altura_arvore_avl(u->esquerda), altura_arvore_avl(u->direita)) + 1;

    return u;
}

no_avl_t* rotacao_avl_direita(no_avl_t* v) {
    no_avl_t* u = v->esquerda;
    v->esquerda = u->direita;
    u->direita = v;

    v->altura = max(altura_arvore_avl(v->esquerda), altura_arvore_avl(v->direita)) + 1;
    u->altura = max(altura_arvore_avl(u->esquerda), altura_arvore_avl(u->direita)) + 1;

    return u;
}

no_avl_t* rotacao_dupla_direita(no_avl_t* v) {
    v->esquerda = rotacao_avl_esquerda(v->esquerda);
    return rotacao_avl_direita(v);
}

no_avl_t* rotacao_dupla_esquerda(no_avl_t* v) {
    v->direita = rotacao_avl_direita(v->direita);
    return rotacao_avl_esquerda(v);
}

int altura_arvore_avl(no_avl_t* v) {
    if (v == NULL) {
        return 0;
    } else {
        return v->altura;
    }
}

// negativo se a subárvore direita for maior
int fator_balanceamento(no_avl_t* v) {
    if (v == NULL) {
        return 0;
    } else {
        return altura_arvore_avl(v->esquerda) - altura_arvore_avl(v->direita);
    }
}

no_avl_t* balancear(no_avl_t* v) {
    int fb = fator_balanceamento(v);
    if (fb > 1){// nó desregulado tem filho desregulado à esquerda
        if (fator_balanceamento(v->esquerda) > 0) {
            // caso esquerda−esquerda
            return rotacao_avl_direita(v);
        } else {
            // caso esquerda−direita
            return rotacao_dupla_direita(v);
        }
    } else if (fb < -1) { // nó desregulado tem filho desregulado à direita
        if (fator_balanceamento(v->direita) < 0) {
            // caso direita−direita
            return rotacao_avl_esquerda(v);
        } else {
            // caso direita−esquerda
            return rotacao_dupla_esquerda(v);
        }
    }
    return v;
}

no_avl_t* inserir_na_arvore_avl(no_avl_t* raiz, int valor) {
    if (raiz == NULL) {
        return criar_arvore_avl(valor, 0);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir_na_arvore_avl(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_na_arvore_avl(raiz->direita, valor);
    } else {
        return raiz; // valor duplicado não é inserido
    }

    //ajustar altura da arvore
    raiz->altura = 1 + max(altura_arvore_avl(raiz->esquerda), altura_arvore_avl(raiz->direita));

    return balancear(raiz);
}

no_avl_t* remover_da_arvore_avl(no_avl_t* raiz, int valor) {
    if (raiz == NULL) return raiz;

    if (valor < raiz->valor) {
        raiz->esquerda = remover_da_arvore_avl(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover_da_arvore_avl(raiz->direita, valor);
    } else {

        // no com dois filhos
        // encontrar o menor valor para subir
        if (raiz->esquerda != NULL && raiz->direita != NULL) {

            no_avl_t* sucessor = raiz->direita;
            while (sucessor->esquerda != NULL) {
                sucessor = sucessor->esquerda;
            }

            raiz->valor = sucessor->valor;

            raiz->direita = remover_da_arvore_avl(raiz->direita, sucessor->valor);
        }
        else {
            no_avl_t *temp;

            if (raiz->esquerda != NULL) {
                temp = raiz->esquerda; // pega o filho da esquerda
            } else {
                temp = raiz->direita;  // se não tem esquerda, pega o da direita
            }

            if (temp == NULL) {
                free(raiz);
                return NULL;
            } else {
                no_avl_t* aux = temp;
                free(raiz);
                return aux;
            }
        }
    }

    // se a arvore ficou vazia
    if (raiz == NULL) return raiz;

    raiz->altura = 1 + max(altura_arvore_avl(raiz->esquerda), altura_arvore_avl(raiz->direita));

    return balancear(raiz);
}

void destruir_arvore_avl(no_avl_t* raiz) {
    if (raiz)
    {
        destruir_arvore_avl(raiz->esquerda);
        destruir_arvore_avl(raiz->direita);
        free(raiz);
    }
}