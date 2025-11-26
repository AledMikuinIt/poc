#include <bits/time.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "ressourceManager.h"



static inline uint64_t ns() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}

int main() {

    RessourceManager *rm = create_rm(1000000);

    uint64_t start = ns();
    uint64_t s = traverse_next(rm);
    uint64_t end = ns();

    printf("Resultat: %lu\n", s);
    printf("Temps: %lu\n", end-start);

    // Free
    free_rm(rm);

    return 0;
}

