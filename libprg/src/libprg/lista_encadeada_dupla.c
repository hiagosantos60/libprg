// #include "libprg/libprg.h"
// #include <stdio.h>
// #include <stdlib.h>
//
// typedef struct no_duplo { //definindo o que é um nó duplamente ligada
//     int valor; // valor do nó
//     struct no_duplo *anterior; // ponteiro para o nó anterior ao atual
//     struct no_duplo *proximo; // ponteiro para o próximo nó da lista
// }no_duplo_t;
//
// no_duplo_t *criar_lista_encadeada_dupla(int valor)
// {
//     no_duplo_t* no_duplo = malloc(sizeof(no_duplo_t)); // alocando memória
//     no_duplo->valor = valor; // declarando o valor
//     no_duplo->proximo = NULL; // não temos o próximo
//     no_duplo->anterior = NULL; // não temos anterior será usado depois
//
//     return no_duplo; // retorna o nó criado
// }
//
// void adicionar_na_lista_encadeada_dupla(no_duplo_t **inicio, int valor) {
//     no_duplo_t* novo_no_duplo = criar_lista_encadeada(valor); // criando um novo nó com os parâmetros de no_duplo
//     novo_no_duplo->proximo = *inicio;  // o novo nó vai começar a apontar para o que já existia
//     (*inicio)->anterior = novo_no_duplo; // o nó antigo vai ter como próximo o nó que adicionamos agora
//     novo_no_duplo->anterior = NULL; // o anterior do novo nó vai ser NULL
//     *inicio = novo_no_duplo; // o novo inicio é o novo nó
// }
//
// no_duplo_t* buscar_na_lista_encadeada_dupla(no_t** inicio, int valor)
// {
//     no_duplo_t* atual = *inicio;
//
//     while (atual)
//     {
//         if (atual->valor == valor)
//         {
//             return atual;
//         }
//         atual = atual->proximo;
//     }
//     return NULL;
// }
//
// void remover_da_lista_encadeada_dupla(no_duplo_t** inicio, int valor)
// {
//     no_duplo_t* atual = *inicio;
//
//     while (atual)
//     {
//         if (atual->valor == valor)
//         {
//             if ((atual->anterior))
//             {
//                 atual->proximo->anterior = atual->proximo;
//                 atual->anterior->proximo = atual->anterior;
//             }
//             else // se não tiver anterior
//             {
//                 *inicio = atual->proximo;
//                 (*inicio)->anterior = NULL;
//             }
//             free(atual);
//             break;
//         }
//         atual = atual->proximo;
//     }
// }