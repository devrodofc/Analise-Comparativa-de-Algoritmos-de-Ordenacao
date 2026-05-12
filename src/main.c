#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/experiment.h"

/**
 * @brief Ponto de entrada principal do projeto de análise de algoritmos.
 * * Responsabilidades:
 * 1. Inicializar o gerador de números pseudo-aleatórios.
 * 2. Invocar o motor de experimentos.
 * 3. Garantir o encerramento gracioso do programa.
 */
int main(int argc, char *argv[]) {
    srand((unsigned int)time(NULL));

    fprintf(stderr, "[INFO] Iniciando experimentos de ordenação...\n");
    fprintf(stderr, "[INFO] Os dados serão impressos em formato CSV no console.\n");

    runExperiments();

    fprintf(stderr, "[INFO] Experimentos concluídos com sucesso.\n");

    return EXIT_SUCCESS;
}