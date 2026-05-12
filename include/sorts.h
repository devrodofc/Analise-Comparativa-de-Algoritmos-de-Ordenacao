#ifndef SORTS_H
#define SORTS_H

#include <stddef.h>

/**
 * @brief Ordena um vetor utilizando o algoritmo Quick Sort.
 * @details Implementação baseada na estratégia de partição de Lomuto.
 * @param arr Ponteiro para o vetor de inteiros a ser ordenado.
 * @param n Número de elementos no vetor.
 */
void quickSort(int *arr, size_t n);

/**
 * @brief Ordena um vetor utilizando o algoritmo Heap Sort.
 * @details Implementação construída sobre a estrutura de um heap máximo.
 * @param arr Ponteiro para o vetor de inteiros a ser ordenado.
 * @param n Número de elementos no vetor.
 */
void heapSort(int *arr, size_t n);

/**
 * @brief Ordena um vetor utilizando o algoritmo Radix Sort.
 * @details Utiliza obrigatoriamente o Counting Sort como sub-rotina estável.
 * Suporta apenas números decimais inteiros não negativos.
 * @param arr Ponteiro para o vetor de inteiros a ser ordenado.
 * @param n Número de elementos no vetor.
 */
void radixSort(int *arr, size_t n);

#endif 