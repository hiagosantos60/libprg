//lab_10 - Implementar algoritimos de ordenação

#include <stdlib.h>
#include "libprg/libprg.h"

//bubble_sort
// preciso saber onde está o array e o tamanho dele
void bubble_sort(int* arr, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) { // valor do primeiro elemento
        for (int j = i + 1; j < tamanho; j++) { // valor do segundo elemento
            if (arr[i] > arr[j]) { // comparando os dois elementos e fazer a ordenação
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

// tenho que percorrer o array e ir comparando os valores




//insertion_sort()

//selection_sort()