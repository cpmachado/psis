/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "include/lib.h"


/* FUNCTION IMPLEMENTATIONS */

int main() {
    int a;
    char line[100];
    char library_name[100];
    char *error;

    printf("What version of the functions you whant to use?\n");
    printf("\t1 - Normal    (lib1)\n");
    printf("\t2 - Optimized (lib2)\n");

    if (!fgets(line, 100, stdin) || sscanf(line, "%d", &a) != 1) {
        fprintf(stderr, "main: Failed to read option\n");
        exit(EXIT_FAILURE);
    }

    if (a == 1) {
        strcpy(library_name, "./lib1.so");
    } else if (a == 2) {
        strcpy(library_name, "./lib2.so");
    } else {
        fprintf(stderr, "main: Not running anything\n");
        exit(EXIT_FAILURE);
    }

    printf("running the normal versions from %s\n", library_name);

    /* load library from name library_name */
    void *handle = dlopen(library_name, RTLD_NOW);

    if (!handle) {
        fprintf(stderr, "main: Failed to load %s\n", library_name);
        exit(EXIT_FAILURE);
    }

    /* declare pointers to functions */
    void (*func_1p)(void);
    void (*func_2p)(void);

    /*load func_1 from loaded library */
    func_1p = (void (*)())dlsym(handle, "func_1");

    if ((error = dlerror())) {
        fprintf(stderr, "main: %s", error);
        exit(EXIT_FAILURE);
    }

    /*load func_2 from loaded library */
    func_2p = (void (*)())dlsym(handle, "func_2");
    if ((error = dlerror())) {
        fprintf(stderr, "main: %s", error);
        exit(EXIT_FAILURE);
    }

    /* call func_1 from whichever library was loaded */
    func_1p();

    /* call func_2 from whichever library was loaded */
    func_2p();

    return 0;
}
