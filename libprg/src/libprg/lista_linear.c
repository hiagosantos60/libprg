#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libprg/libprg.h>

// --- Estrutura da Lista ---
typedef struct lista_linear {
    int *elementos; //ponteiro para apontar onde estão os elementos de fato
    int tamanho; //quantidade de elementos armazenados
    int capacidade; //capacidade total que cabe na lista
    bool ordenada; //flag para verificar se a lista é ordenada
} lista_t;


// Cria uma lista vazia
lista_t *criar_lista(int capacidade, bool ordenada) {
    lista_t *lista = malloc(sizeof(lista_t));
    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->capacidade = capacidade;
    lista->tamanho = 0;
    lista->ordenada = ordenada;
    return lista;
}

int tamanho_lista_linear(lista_t *lista) {
    return lista->tamanho;
}

//liberar a memória alocada para a lista
void destruir_lista(lista_t *lista) {
    free(lista->elementos);
    free(lista);
}

//verifica se a lista está vazia
bool verificar_lista_vazia(lista_t *lista) {
    return lista->tamanho == 0;
}

//verifica se a lista está cheia
bool verificar_lista_cheia(lista_t *lista) {
    return lista->tamanho == lista->capacidade;
}

void inserir_nao_ordenada(lista_t *lista, int valor_a_inserir) {
    if (verificar_lista_cheia(lista)) {
        // realocar se estiver cheia a memória
        lista->elementos = realloc(lista, sizeof(int) * lista->capacidade * 2);
    }

    //adiciona o elemento na primeira posição livre
    lista->elementos[lista->tamanho] = valor_a_inserir;
    lista->tamanho++;
}

void inserir_ordenada(lista_t *lista, int valor_a_inserir) {
    int i = 0;
    //encontra a posição correta para o novo valor
    while (i < lista->tamanho && lista->elementos[i] < valor_a_inserir) {
        i++;
    }
    //desloca os elementos maiores para a direita
    for (int j = lista->tamanho; j > i; j--) {
        lista->elementos[j] = lista->elementos[j - 1];
    }
    //insere o novo valor na posição correta
    lista->elementos[i] = valor_a_inserir;
    lista->tamanho++;
}

void inserir_lista(lista_t *lista, const int valor_a_inserir) {
    if (verificar_lista_cheia(lista)) {
        printf("Erro: A lista esta cheia!\n");
        return;
    }

    if (lista->ordenada) {
        inserir_ordenada(lista, valor_a_inserir);
    } else {
        inserir_nao_ordenada(lista, valor_a_inserir);
    }
}

int busca_linear(lista_t *lista, int valor_a_buscar) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == valor_a_buscar) {
            return i; //retorna o índice
        }
    }
    return -1;
}

int busca_binaria(lista_t *lista, int valor_a_buscar) {
    int esquerda = 0;
    int direita = lista->tamanho - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (lista->elementos[meio] == valor_a_buscar) {
            return meio;
        }
        if (lista->elementos[meio] < valor_a_buscar) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}


int buscar_elementos_lista(lista_t *lista, int valor_a_buscar) {
    if (lista->ordenada) {
        return busca_binaria(lista, valor_a_buscar);
    } else {
        return busca_linear(lista, valor_a_buscar);
    }
}

// int limitar_posicao(lista_t *lista, int posicao) {
//     if (posicao > lista->tamanho) {
//         return lista->tamanho;
//     }
//     if (posicao < 0) {
//         return 0;
//     }
// }

int buscar_na_posicao_lista(lista_t *lista, int posicao) {
    return lista->elementos[posicao]; // retornando o valor que o indice está indicando
}

void inserir_na_posicao_lista(lista_t *lista, int valor_a_inserir, int posicao) {
    int indicie = limitar_posicao(lista_t *lista, int posicao);

    if (lista->ordenada == false) {
        inserir_nao_ordenada(lista, lista->elementos[indicie]); // copiando o valor que está na posição para o final
        lista->elementos[indicie] = valor_a_inserir; // sobreescrevendo na posição desejada
    } else {
        // como é ordenada, não podemos colocar em qualquer lugar
        inserir_ordenada(lista, valor_a_inserir);
    }
}


void remover_elemento_lista(lista_t *lista, int valor_a_remover) {
    if (verificar_lista_vazia(lista)) {
        return;
    }

    int indice = buscar_elementos_lista(lista, valor_a_remover);

    if (indice < 0) {
        printf("Aviso: Valor %d nao encontrado para remocao.\n", valor_a_remover);
        return;
    }

    if (lista->ordenada) {
        for (int i = indice; i < lista->tamanho - 1; i++) {
            lista->elementos[i] = lista->elementos[i + 1];
        }
    } else {
        //para listas não ordenadas vamos substituir pelo último
        lista->elementos[indice] = lista->elementos[lista->tamanho - 1];
    }
    lista->tamanho--;
}

void remover_na_posicao_lista(lista_t *lista, int posicao) {

    int indicie = limitar_posicao(lista_t *lista, int posicao);

    int valor = lista->elementos[indicie];
    remover_elemento_lista(lista, valor);
}

//Imprime o primeiro elemento da lista e o tamanho da lista
//função necessária para o laboratório
void imprimir_primeiro_e_tamanho(lista_t *lista) {
    if (verificar_lista_vazia(lista)) {
        printf("A lista esta vazia.\n");
    } else {
        printf("Primeiro elemento: %d | Tamanho atual: %d\n", lista->elementos[0], lista->tamanho);
    }
}

//Imprime todos os números da lista
//função necessária para o lab
void imprimir_lista_completa(lista_t *lista) {
    if (verificar_lista_vazia(lista)) {
        printf("A lista esta vazia.\n");
        return;
    }
    printf("Elementos: [ ");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("]\n");
}
