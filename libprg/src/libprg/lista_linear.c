#include <stdlib.h>
#include <threads.h>
#include <libprg/libprg.h>

typedef struct lista_linear {
    int *elementos; //ponteiro para apontar onde estão os elementos de fato
    int tamanho; //o que seria armazenado, mostrando o fim da lista
    int capacidade; //total que cabe na lista
    bool ordenada; //para quando a lista é ordenada, fazemos a verificação
} lista_t;

//criar lista não ordenada
lista_t *criar_lista(const int capacidade, const bool ordenada) {
    lista_t *lista = malloc(sizeof(lista_t));
    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->capacidade = capacidade;
    lista->tamanho = 0;
    lista->ordenada = ordenada;

    return lista;
}

//assinatura das funções usadas
void inserir_nao_ordenada(lista_t *lista, int valor_a_inserir);
void inserir_ordenada(lista_t *lista, int valor_a_inserir);
int busca_linear (lista_t* lista, int valor_a_buscar);
int busca_binaria (lista_t* lista, int valor_a_buscar);

//inserir elemento na lista, verificando se é ordenada ou não 
void inserir_nao_ordenada(lista_t *lista, int valor_a_inserir) {
    lista->tamanho = valor_a_inserir;
    lista->tamanho++;
}

void inserir_ordenada(lista_t *lista, int valor_a_inserir) {
    for (int i = lista->tamanho - 1; i >= 0; i--) {
        if (lista->elementos[i] < valor_a_inserir) {
            lista->elementos[i + 1] = valor_a_inserir;
            break;
        }
        lista->elementos[i + 1] = lista->elementos[i]; //jogando para frente se não for a posição desejada
    }
    lista->tamanho++;
}

void inserir_lista(lista_t *lista, const int valor_a_inserir) {
    if (verificar_lista_cheia(lista)) {
        return;
    } //erro para verifica se a lista está cheia

    if (lista->ordenada) {
        inserir_ordenada(lista, valor_a_inserir);
    } else {
        inserir_nao_ordenada(lista, valor_a_inserir);
    }
}

//buscar elemento na lista
int busca_linear (lista_t* lista, int valor_a_buscar) {
    int indice=0;
    while (indice<lista->tamanho) {
        if (lista->elementos[indice] == valor_a_buscar) {
            return indice;
        }
        indice++;
    }
    return -10;
}

int busca_binaria (lista_t* lista, int valor_a_buscar) {
    int indice_meio_lista = lista->tamanho/2;

    while (lista->elementos[indice_meio_lista] != valor_a_buscar) { //verificar loop infinito
        if (lista->elementos[indice_meio_lista] == valor_a_buscar) {
            return indice_meio_lista;
        } else if (lista->elementos[indice_meio_lista] > valor_a_buscar) {
            indice_meio_lista = indice_meio_lista/2;
        } else {
            //teminar depois
        }
    }
}

int buscar_elementos_lista(lista_t *lista, int valor_a_buscar) {
    if (lista->ordenada) {
        busca_linear(lista, valor_a_buscar);
    }
    

    return -1;
}

//remover elemento da lista não ordenada
void remover_elemento_lista(lista_t *lista, int valor_a_remover) {
    const int indice = buscar_elementos_lista(lista, valor_a_remover);

    if (indice < 0) {
        exit(EXIT_FAILURE);
    }

    lista->elementos[indice] = lista->elementos[lista->tamanho];
    lista->tamanho--;
}

//verificar se a lista não ordenada está vazia
bool verificar_lista_vazia(lista_t *lista) {
    return lista->tamanho == 0;
}

//verificar se a lista não ordenada está cheia
bool verificar_lista_cheia(lista_t *lista) {
    return lista->tamanho == lista->capacidade;
}

//destruir lista não ordenada
void destruir_lista(lista_t *lista) {
    free(lista->elementos);
    free(lista);
}

//----------------------------------------------------------------------------------------------//
//funções necessárias para o Lab 4:
//4. Imprima o primeiro elemento da lista e o tamanho da lista;
//6. Imprima todos os números da lista;
