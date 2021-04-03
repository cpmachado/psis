/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "include/randarray.h"


/* MACROS */
#define LIBRARY_NAME "./libSingleStep.so"


/* FUNCTION DEFINITIONS */

int
main(void) {
    long *array = randArrayLong(100, 200);

    if (!array) {
        fprintf(stderr, "main: Failed to allocate array\n");
        exit(EXIT_FAILURE);
    }

    /* load library from name library_name */
    void *handle = dlopen(LIBRARY_NAME, RTLD_NOW);
    char *error;

    if ((error = dlerror())) {
        fprintf(stderr, "main: %s", error);
        exit(EXIT_FAILURE);
    }

    /* Declare function and load it */
    void (*printDivisible)(long, long*);

    printDivisible = (void (*)(long, long*))dlsym(handle, "printDivisible");

    if ((error = dlerror())) {
        fprintf(stderr, "main: %s", error);
        exit(EXIT_FAILURE);
    }

    /* run it */
    printDivisible(100, array);

    free(array);
    dlclose(handle);
    return 0;
}

