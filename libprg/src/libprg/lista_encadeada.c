#include <libprg/libprg.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    no_t* proximo;
}no_t;

//criar lista e nós
no_t criar_lista_encadeada (int valor) {
    no_t* no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL;

    return no;
}

//inserir elemento | nó
no_t* inserir_elemento_lista_encadeada(int* inicio, int valor_a_inserir) {

    no_t* novo_no = criar_lista_encadeada(valor_a_inserir);
    novo_no->proximo = inicio;
    inicio = novo_no;

    return inicio;
}


//remover elemento | nó



//buscar elemento | nó



//destruir lista | destruir nós