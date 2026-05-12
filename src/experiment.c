#include "../include/experiment.h"
#include "../include/sorts.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

static const size_t SIZES[] = {
    10, 25, 50, 75, 100, 250, 500, 750, 1000, 2500, 5000, 
    7500, 10000, 25000, 50000, 75000, 100000, 250000, 500000, 750000, 1000000
};
static const int NUM_SIZES = sizeof(SIZES) / sizeof(SIZES[0]);

#define NUM_RUNS 5 

typedef void (*SortFunction)(int*, size_t);
typedef void (*FillFunction)(int*, size_t);

typedef struct {
    SortFunction func;
    const char *name;
} Algorithm;

typedef struct {
    FillFunction func;
    const char *name;
} Distribution;

/**
 * @brief Executa e mede um algoritmo específico para uma configuração.
 */
static double benchmarkAlgorithm(SortFunction sortFunc, const char* algoName, 
                                 const char* distName, const int *arr_base, size_t n) {
    if (sortFunc == quickSort && (distName[0] == 'C' || distName[0] == 'D') && n > 10000) {
        return -1.0;
    }

    int *arr_work = (int *)malloc(n * sizeof(int));
    if (!arr_work) {
        fprintf(stderr, "Erro de alocação de memória para tamanho %zu\n", n);
        exit(EXIT_FAILURE);
    }

    double total_time = 0.0;

    for (int run = 0; run < NUM_RUNS; run++) {
        copyArray(arr_base, arr_work, n);

        double start = getCurrentTimeSec();
        sortFunc(arr_work, n);
        double end = getCurrentTimeSec();

        total_time += (end - start);

        if (run == 0 && !isSorted(arr_work, n)) {
            fprintf(stderr, "ALERTA: %s falhou ao ordenar %s de tamanho %zu!\n", algoName, distName, n);
        }
    }

    free(arr_work);
    return total_time / NUM_RUNS; 
}

void runExperiments(void) {
    Algorithm algorithms[] = {
        {quickSort, "QuickSort"},
        {heapSort,  "HeapSort"},
        {radixSort, "RadixSort"}
    };
    int num_algos = sizeof(algorithms) / sizeof(algorithms[0]);

    Distribution distributions[] = {
        {fillRandom,     "Aleatorio"},
        {fillAscending,  "Crescente"},
        {fillDescending, "Decrescente"}
    };
    int num_dists = sizeof(distributions) / sizeof(distributions[0]);

    printf("Algoritmo,Distribuicao,Tamanho,TempoMedio_Segundos\n");

    for (int i = 0; i < NUM_SIZES; i++) {
        size_t n = SIZES[i];

        int *arr_base = (int *)malloc(n * sizeof(int));
        if (!arr_base) {
            fprintf(stderr, "Erro alocando array base de tamanho %zu\n", n);
            exit(EXIT_FAILURE);
        }

        for (int d = 0; d < num_dists; d++) {
            distributions[d].func(arr_base, n);

            for (int a = 0; a < num_algos; a++) {
                double avg_time = benchmarkAlgorithm(
                    algorithms[a].func, algorithms[a].name, 
                    distributions[d].name, arr_base, n
                );

                printf("%s,%s,%zu,%.6f\n", 
                       algorithms[a].name, distributions[d].name, n, avg_time);
            }
        }
        free(arr_base);
    }
}