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
 * @brief Garante a propriedade de Max-Heap para uma subárvore.
 * * @param arr Vetor que representa a árvore binária completa.
 * @param n Tamanho atual do heap.
 * @param root Índice da raiz da subárvore a ser analisada.
 */
static void maxHeapify(int *arr, size_t n, size_t root) { //array comum tratado como array de arvore binaria quase completa
    size_t largest = root;      
    size_t left = 2 * root + 1;  
    size_t right = 2 * root + 2; 

    if (left < n && arr[left] > arr[largest]) { 
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        swap(&arr[root], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

/**
 * @brief 
 */
void heapSort(int *arr, size_t n) {
    if (arr == NULL || n <= 1) {
        return;
    }

    for (size_t i = n / 2; i > 0; i--) {
        maxHeapify(arr, n, i - 1);
    }

    // Extrai os elementos do heap um a um
    for (size_t i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        
        // Chama o maxHeapify na raiz com o tamanho do heap reduzido
        maxHeapify(arr, i, 0);
    }
}