/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#include "include/libra.h"
#include "include/libra_divisors.h"


/* MACROS */
#define LENGTH 100
#define LIMIT  200


/* FUNCTION DECLARATIONS */

/* divisorThread: prints numbers that are divisible, returns number of
 * divisible numbers found
 */
void* divisorThread(void* data);


/* FUNCTION DEFINITIONS */

int
main(void) {
    pthread_t *tid;
    unsigned long ndiv = sizeof(divisors) / sizeof(unsigned long);
    unsigned long i, d;
    unsigned long *v, *res;
    void **data;

    if (!(v = randArrayULong(LENGTH, LIMIT))) {
        fprintf(stderr, "Failed to allocate array of integers\n");
        exit(EXIT_FAILURE);
    }

    if (!(tid = (pthread_t*)malloc(ndiv * sizeof(pthread_t*)))) {
        fprintf(stderr, "Failed to allocate array of pthread_t\n");
        exit(EXIT_FAILURE);
    }

    if (!(res = (unsigned long*)malloc(ndiv * sizeof(unsigned long)))) {
        fprintf(stderr, "Failed to allocate array of pthread_t\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < ndiv; i++) {
        d = divisors[i];
        if (!(data = (void**)malloc(sizeof(void*) * 2))) {
            fprintf(stderr, "Failed to allocate data array for thread\n");
            exit(EXIT_FAILURE);
        }

        data[0] = (void*)v;
        data[1] = (void*)d;
        if (pthread_create(&tid[i], NULL, divisorThread, (void*)data)) {
            fprintf(stderr, "Failed to create thread\n");
            exit(EXIT_FAILURE);
        }
    }

    /* wait for each of the children processes */
    for (i = 0; i < ndiv; i++) {
        pthread_join(tid[i], (void*)&res[i]);
    }

    for (i = 0; i < ndiv; i++) {
        printf("d: %lu, n = %lu\n", divisors[i], res[i]);
    }

    free(tid);
    free(res);
    free(v);
    return 0;
}


void*
divisorThread(void* data) {
    void **v = (void**)data;
    unsigned long *arr = (unsigned long*)v[0];
    unsigned long d = (unsigned long)v[1];
    unsigned long n = 0;
    int i;

    free(data);
    for (i = 0; i < LENGTH; i++) {
        if (arr[i] % d == 0) {
            printf("%lu -> %lu\n", arr[i], d);
            n++;
        }
    }

    return (void*)n;
}
