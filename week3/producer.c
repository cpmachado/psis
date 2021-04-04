/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "include/randarray.h"


/* MACROS */
#define ARRAY_LEN 100
#define ARRAY_RANGE 200


/* FUNCTION DEFINITIONS */

int
main(void) {
    long *array = randArrayLong(ARRAY_LEN, ARRAY_RANGE);
    long i;

    if (!array) {
        fprintf(stderr, "main: Failed to allocate array\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < ARRAY_LEN; i++) {
        printf("%ld\n", array[i]);
    }
    free(array);
    return 0;
}

