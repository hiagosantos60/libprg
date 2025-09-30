#include <libprg/libprg.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} no_t;

//criar lista e nós
no_t *criar_lista_encadeada(int valor) {
    no_t *no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL;

    return no;
}

//criar lista encadeada circular
no_t *criar_lista_encadeada_circular(int valor) {
    no_t *no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = no;

    return no;
}

//inserir elemento | nó
void inserir_elemento_lista_encadeada(no_t **inicio, int valor_a_inserir) {
    no_t *novo_no = criar_lista_encadeada(valor_a_inserir); //cria um novo nó
    novo_no->proximo = *inicio; // o novo nó aponta para o endereço do que já existia
    *inicio = novo_no; //o início agora é o nó que foi inserido
}

void inserir_elemento_lista_encadeada_circular(no_t **inicio, int valor_a_inserir) {
    no_t* novo_no = criar_lista_encadeada_circular(valor_a_inserir);
    novo_no->proximo = *inicio;

    no_t* ultimo = *inicio; //"o último é o inicio"

    while (ultimo->proximo != *inicio) {
        ultimo = ultimo->proximo; //enquanto for diferente, vou para o próximo
    }

    ultimo->proximo = novo_no; //o ultimo elementos passa a apontar para o inicio
    *inicio = novo_no;
}


//buscar elementos na lista
no_t *buscar_elementos_lista_encadeada(no_t **inicio, int valor_a_buscar) {
    no_t *atual = *inicio; //variável auxiliar que serve para indicar

    while (atual) {
        if ((*inicio)->valor == valor_a_buscar) {
            //se o valor que estamos buscando for encontrado
            return atual; //retorna o endereço de onde está o valor
        }
        atual = atual->proximo; //vou para o próximo nó caso nao retorne nada
    }

    return NULL;
}

//remover elementos da lista encadeada
void remover_elementos_lista_encadeada(no_t **inicio, int valor_a_remover) {
    no_t *atual = *inicio;
    //se refere ao nó que estamos removendo, buscamos, encontramos e vamos fazer as alterações nos ponteiros de próximo do anterior
    no_t *anterior = NULL;

    while (atual) {
        if (atual->valor == valor_a_remover) {
            anterior->proximo = atual->proximo;
            if (anterior) {
                anterior->proximo = atual->proximo;
            } else {
                *inicio = atual->proximo;
            }
            free(atual); //destroi o nó que estamos removendo, as conexões já foram feitas anteriormente
            break;
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

//void ordenar_lista_encadeada