#include "../include/sorts.h"

/**
 * @brief Troca os valores de duas variáveis inteiras.
 */
static inline void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Realiza o particionamento do vetor utilizando a estratégia de Lomuto.
 * O último elemento é escolhido como pivô.
 * * @param arr Vetor a ser particionado.
 * @param low Índice inicial.
 * @param high Índice final (pivô).
 * @return O índice final onde o pivô foi posicionado.
 */
static int lomutoPartition(int *arr, int low, int high) {
    int pivot = arr[high]; //ultimo elemento do subvetor atual
    int i = low; //elementos menores que o pivo

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    
    swap(&arr[i], &arr[high]);
    
    return i;
}

/**
 * @brief Função recursiva interna para o Quick Sort.
 * * @param arr Vetor a ser ordenado.
 * @param low Índice inicial da partição atual.
 * @param high Índice final da partição atual.
 */
static void quickSortRec(int *arr, int low, int high) { //se chama recursivamente para metade esquerda e direita
    if (low < high) {
        int pi = lomutoPartition(arr, low, high);

        quickSortRec(arr, low, pi - 1);
        quickSortRec(arr, pi + 1, high);
    }
}

/**
 * @brief Interface pública do Quick Sort.
 */
void quickSort(int *arr, size_t n) {
    if (arr == NULL || n <= 1) { //verifica se o vetor é nulo ou se possui apenas um elemento já ordenado
        return;
    }
    
    quickSortRec(arr, 0, (int)(n - 1));
}