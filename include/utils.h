#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @brief Preenche um vetor com números inteiros aleatórios não negativos.
 * @param arr Ponteiro para o vetor pre-alocado.
 * @param n Tamanho do vetor.
 */
void fillRandom(int *arr, size_t n);

/**
 * @brief Preenche um vetor com valores sequenciais crescentes de 1 até n.
 * Ideal para testar o pior caso do Quick Sort com partição de Lomuto.
 * @param arr Ponteiro para o vetor pre-alocado.
 * @param n Tamanho do vetor.
 */
void fillAscending(int *arr, size_t n);

/**
 * @brief Preenche um vetor com valores sequenciais decrescentes de n até 1.
 * Ideal para testar o pior caso do Quick Sort com partição de Lomuto.
 * @param arr Ponteiro para o vetor pre-alocado.
 * @param n Tamanho do vetor.
 */
void fillDescending(int *arr, size_t n);

/**
 * @brief Copia o conteúdo de um vetor origem para um vetor destino.
 * Utiliza memcpy em baixo nível para máxima performance.
 * @param src Vetor de origem.
 * @param dest Vetor de destino (deve estar previamente alocado).
 * @param n Número de elementos a serem copiados.
 */
void copyArray(const int *src, int *dest, size_t n);

/**
 * @brief Verifica se um vetor está ordenado de forma crescente (Sanity Check).
 * @param arr Vetor a ser verificado.
 * @param n Tamanho do vetor.
 * @return true se ordenado, false caso contrário.
 */
bool isSorted(const int *arr, size_t n);

/**
 * @brief Obtém o tempo atual em segundos com alta precisão (nanossegundos).
 * @return Tempo decorrido em segundos.
 */
double getCurrentTimeSec(void);

#endif /* UTILS_H */