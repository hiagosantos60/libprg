#ifndef LIBPRG_H
#define LIBPRG_H
#include <stdbool.h>

//pilha
typedef struct pilha pilha_t;
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
typedef struct lista_linear lista_t;
lista_t* criar_lista(int capacidade, bool ordenada);
void destruir_lista (lista_t* lista);
bool verificar_lista_cheia(lista_t* lista);
bool verificar_lista_vazia(lista_t* lista);
void remover_elemento_lista(lista_t* lista, int valor_a_remover);
int buscar_elementos_lista(lista_t* lista, int valor_a_buscar);
void inserir_lista (lista_t* lista, int valor_a_inserir);
void imprimir_primeiro_e_tamanho(lista_t *lista);
void imprimir_lista_completa(lista_t *lista);

//lista ligada
typedef struct no no_t;
no_t* criar_lista_encadeada (int valor);
void inserir_elemento_lista_encadeada(no_t** inicio, int valor_a_inserir);
void remover_elementos_lista_encadeada(no_t** inicio, int valor_a_remover);
no_t *buscar_elementos_lista_encadeada(no_t **inicio, int valor_a_buscar);
void destruir_lista_ligada (no_t **inicio);

//lista_circular
no_t *criar_lista_encadeada_circular(int valor);
void inserir_elemento_lista_encadeada_circular(no_t **inicio, int valor_a_inserir);
void destruir_lista_ligada_circular (no_t **inicio);

#endif
