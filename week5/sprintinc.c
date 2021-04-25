/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


/* FUNCTION DECLARATIONS */

/* incrementThread: increment a given thread every random seconds */
void* incrementThread(void* data);


/* FUNCTION DEFINITIONS */

int
main(void) {
    pthread_t tid;
    unsigned long n = 0;
    void **data;

    if (!(data = (void**)malloc(sizeof(void*) * 2))) {
        fprintf(stderr, "Failed to allocate data array for thread\n");
        exit(EXIT_FAILURE);
    }

    data[0] = (void*)(random() % 10 + 1);
    data[1] = (void*)&n;

    if (pthread_create(&tid, NULL, incrementThread, (void*)data)) {
        fprintf(stderr, "Failed to create thread\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("%lu\n", n);
        sleep(1);
    }
    return 0;
}


void*
incrementThread(void* data) {
    void **v = (void**)data;
    unsigned long t = (unsigned long)v[0];
    unsigned long *n = (unsigned long*)v[1];

    free(data);
    while (1) {
        (*n)++;
        sleep(t);
    }

    return NULL;
}
