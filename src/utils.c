#define _POSIX_C_SOURCE 199309L

#include "../include/utils.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

void fillRandom(int *arr, size_t n) {
    if (!arr) return;
    
    for (size_t i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }
}

void fillAscending(int *arr, size_t n) {
    if (!arr) return;
    
    for (size_t i = 0; i < n; i++) {
        arr[i] = (int)(i + 1);
    }
}

void fillDescending(int *arr, size_t n) {
    if (!arr) return;
    
    for (size_t i = 0; i < n; i++) {
        arr[i] = (int)(n - i);
    }
}

void copyArray(const int *src, int *dest, size_t n) {
    if (src && dest && n > 0) {
        memcpy(dest, src, n * sizeof(int));
    }
}

bool isSorted(const int *arr, size_t n) {
    if (!arr || n <= 1) {
        return true;
    }
    
    for (size_t i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

double getCurrentTimeSec(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
}