//lab_10 - Implementar algoritimos de ordenação

#include <stdlib.h>
#include "libprg/libprg.h"

//selection_sort
// preciso saber onde está o array e o tamanho dele
void selection_sort(int* arr, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {

        // encontra o índice do menor elemento (não o valor)
        int min_idx = i; // assume que 'i' é o menor
        for (int j = i + 1; j < tamanho; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // encontramos um menor, atualiza o *índice*
            }
        }

        // faz a troca no final
        if (min_idx != i) {
            int aux = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = aux;
        }
    }
}

//insertion_sort()
void insertion_sort(int* arr, int tamanho) {
    int key = 0;
    int j = 0;

    for (int i=1; i<tamanho; i++) {
        key = arr[i];
        j = i - 1; // vai se o primeiro elemento e o loop começa no segundo elemento

        while (j >= 0 && arr[j] > key) { // enquanto j positivo e ter elementos para ordenar
            arr[j+1] = arr[j]; // vai jogando o elemento para frente até estar ordenado
            j = j - 1; // para o indice mudar
        }

        arr[j+1] = key; // a ultima posição vai receber o key
    }
}

//bubble_sort()
void bubble_sort(int* arr, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho-1; j++) {
            if (arr[j] > arr[j+1]) {
                int aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}