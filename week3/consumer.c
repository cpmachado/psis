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
    char buf[BUFSIZ];
    long n;
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
    while (fgets(buf, BUFSIZ, stdin)) {
        if (sscanf(buf, "%ld", &n) != 1) {
            fprintf(stderr, "main: Invalid line %s", buf);
            exit(EXIT_FAILURE);
        }
        printDivisible(1, &n);
    }


    dlclose(handle);
    return 0;
}

