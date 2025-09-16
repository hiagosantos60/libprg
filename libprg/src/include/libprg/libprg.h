#ifndef LIBPRG_H
#define LIBPRG_H
#include <stdbool.h>

typedef struct pilha pilha_t;

//pilha
pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t *ponteiro, int elemento);
int desempilhar(pilha_t *ponteiro);
int mostrar_topo_pilha(pilha_t *ponteiro);
int* mostra_pilha(pilha_t *ponteiro);
void destruir_pilha(pilha_t* ponteiro);


//fila
typedef struct fila fila_t;

fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
int desenfileirar(fila_t *f);
void destruir_fila(fila_t *f);
bool fila_cheia(fila_t *f);
int tamanho_fila (fila_t *f);
int fim_fila(fila_t *f);
int inicio_fila(fila_t *f);
void mostrar_elementos(fila_t *f);


//lista não ordenada
typedef struct lista_linear lista_linear_t;
lista_linear_t* criar_lista_linear(int capacidade);
void destruir_lista_linear (lista_linear_t* lista);
bool verificar_lista_linear_cheia(lista_linear_t* lista);
bool verificar_lista_linear_vazia(lista_linear_t* lista);
void remover(lista_linear_t* lista, int valor_a_remover);
int buscar_elementos_lista_linear(lista_linear_t* lista, const int valor_a_comparar);
void inserir_lista_linear (lista_linear_t* lista, const int valor_a_inserir);
lista_linear_t* criar_lista_linear(const int capacidade);

#endif