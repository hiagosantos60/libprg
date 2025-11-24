#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdbool.h>

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

bool buscar_valor_arvore(no_arvore *raiz, int valor) {
    if (raiz == NULL) return false;
    if (valor == raiz->valor) return true;
    if (valor < raiz->valor) return buscar_valor_arvore(raiz->esquerda, valor);
    return buscar_valor_arvore(raiz->direita, valor);
}

no_arvore* remover_valor_arvore(no_arvore *raiz, int valor) {
    if (raiz == NULL) return raiz; // se a arvore estiver vazia

    if (valor < raiz->valor) { // valores menores a esquerda
        raiz->esquerda = remover_valor_arvore(raiz->esquerda, valor);
    } else if (valor > raiz->valor) { // valores maiores a direita
        raiz->direita = remover_valor_arvore(raiz->direita, valor);
    } else { // caso o valor passado seja igual ao nó
        if (raiz->esquerda == NULL) { // sobe o da direita
            no_arvore *aux = raiz->direita;
            free(raiz);
            return aux;
        } else if (raiz->direita == NULL) { // sobe o da esquerda
            no_arvore *aux = raiz->esquerda;
            free(raiz);
            return aux;
        } else { // caso se o nó tiver dois filhos
            no_arvore *aux = raiz->direita;

            while (aux && aux->esquerda != NULL) { // vai descendo pela esquerda
                aux = aux->esquerda;
            }

            raiz->valor = aux->valor;
            raiz->direita = remover_valor_arvore(raiz->direita, aux->valor);
        }
    }
    return raiz;
}


int maior_valor_arvore(no_arvore *raiz) {
    if (raiz == NULL) return 0;

    no_arvore *aux = raiz;

    while (aux->direita != NULL) {
        aux = aux->direita;
    }

    return aux->valor;
}

int menor_valor_arvore(no_arvore *raiz) {
    if (raiz == NULL) return 0;

    no_arvore *aux = raiz;

    while (aux->esquerda != NULL) {
        aux = aux->esquerda;
    }

    return aux->valor;
}

int altura_arvore(no_arvore* raiz) {
    if (raiz == NULL) return 0;

    int pela_esquerda = altura_arvore(raiz->esquerda);
    int pela_direita = altura_arvore(raiz->direita);

    if (pela_direita > pela_esquerda) {
        return 1 + pela_direita;
    } else {
        return 1 + pela_esquerda;
    }
}