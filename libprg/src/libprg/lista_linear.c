#include <stdlib.h>
#include <threads.h>
#include <libprg/libprg.h>

typedef struct lista_linear {
    int* elementos; //ponteiro para apontar onde estão os elementos de fato
    int tamanho; //o que seria armazenado, mostando o fim da lista
    int capacidade; //total que cabe na lista
}lista_linear_t;

//criar lista não ordenada
lista_linear_t* criar_lista_linear(const int capacidade) {

    lista_linear_t* lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof (int) * capacidade);
    lista->capacidade = capacidade;
    lista->tamanho = 0;

    return lista;
}

//inserir elemento na lista não ordenada
void inserir_lista_linear (lista_linear_t* lista, const int valor_a_inserir) {
    if (lista->capacidade >= lista->tamanho) {
        exit(EXIT_FAILURE);
    } //erro para verifica se a lista está cheia

    lista->tamanho = valor_a_inserir; //inserir o elemento
    lista->tamanho++; //pula para a próxima casa da lista_linear
}

//buscar elemento na lista não ordenada
int buscar_elementos_lista_linear(lista_linear_t* lista, const int valor_a_comparar) {
    for (int indice = 0; indice<lista->tamanho; indice++) {
        if (valor_a_comparar == lista->elementos[indice]) {
            return indice; //retona o índice que está o valor que está na lista e foi comparado
        }
    }

    // opção com while
    // int indice=0;
    // while (indice<lista->tamanho) {
    //     if (lista->elementos[indice] == valor_a_comparar) {
    //         return indice;
    //     }
    //     indice++;
    // }

    return -1;
}

//remover elemento da lista não ordenada
void remover(lista_linear_t* lista, int valor_a_remover) {
    const int indice = buscar_elementos_lista_linear(lista, valor_a_remover);

    if (indice < 0) {
        exit(EXIT_FAILURE);
    }

    lista->elementos[indice] = lista->elementos[lista->tamanho];
    lista->tamanho--;
}

//verificar se a lista não ordenada está vazia
bool verificar_lista_linear_vazia(lista_linear_t* lista) {
    return lista->tamanho == 0;
}

//verificar se a lista não ordenada está cheia
bool verificar_lista_linear_cheia(lista_linear_t* lista) {
    return lista->tamanho == lista->capacidade;
}

//destruir lista não ordenada
void destruir_lista_linear (lista_linear_t* lista) {
    free(lista->elementos);
    free(lista);
}
