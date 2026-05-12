#include "../include/sorts.h"
#include <stdlib.h>

/**
 * @brief Encontra o maior elemento do vetor para determinar o número de dígitos.
 * * @param arr Vetor a ser analisado.
 * @param n Tamanho do vetor.
 * @return O valor máximo contido no vetor.
 */
static int getMax(int *arr, size_t n) {
    int max = arr[0];
    for (size_t i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/**
 * @brief Sub-rotina estável de ordenação (Counting Sort) baseada em um dígito específico.
 * * @param arr Vetor a ser ordenado.
 * @param n Tamanho do vetor.
 * @param exp O expoente atual representando a casa decimal (1, 10, 100, ...).
 */
static void countingSortSubroutine(int *arr, size_t n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    if (output == NULL) {
        return; 
    }

    int count[10] = {0};

    for (size_t i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (size_t i = n; i > 0; i--) {
        int current_element = arr[i - 1];
        int digit = (current_element / exp) % 10;
        
        output[count[digit] - 1] = current_element;
        count[digit]--;
    }

    for (size_t i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

/**
 * @brief Interface pública do Radix Sort.
 */
void radixSort(int *arr, size_t n) {
    // Tratamento de segurança
    if (arr == NULL || n <= 1) {
        return;
    }

    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortSubroutine(arr, n, exp);
    }
}