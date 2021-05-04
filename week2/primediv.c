/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "include/libra.h"


/* MACROS */
#define LENGTH 100
#define LIMIT  200


/* FUNCTION DEFINITIONS */

int
main(int argc, char* argv[]) {
    char library_name[BUFSIZ];
    unsigned long *v;
    char *error;

    if (argc > 2) {
        fprintf(stderr, "This program takes at most 1 argument\n");
        exit(EXIT_FAILURE);
    }

    if (argc == 2 && strlen(argv[1]) != 1) {
        fprintf(stderr, "This program takes either 's' or 'm' as argument\n");
        exit(EXIT_FAILURE);
    }

    if (argc == 1 || *argv[1] == 's') {
        strcpy(library_name, "./libss.so");
    } else if (*argv[1] == 'm') {
        strcpy(library_name, "./libms.so");
    } else {
        fprintf(stderr, "This program takes either 's' or 'm' as argument\n");
        exit(EXIT_FAILURE);
    }

    if (!(v = randArrayULong(LENGTH, LIMIT))) {
        fprintf(stderr, "Failed to allocate array of integers\n");
        exit(EXIT_FAILURE);
    }

    /* load library from name library_name */
    void *handle = dlopen(library_name, RTLD_NOW);

    if (!handle) {
        fprintf(stderr, "main: Failed to load %s\n", library_name);
        exit(EXIT_FAILURE);
    }

    /* declare pointers to functions */
    void (*printDivisible)(unsigned long, unsigned long*);

    /*load func_1 from loaded library */
    printDivisible = (void (*)(unsigned long, unsigned long*))
        dlsym(handle, "printDivisible");

    if ((error = dlerror())) {
        fprintf(stderr, "main: %s", error);
        exit(EXIT_FAILURE);
    }

    printDivisible(LENGTH, v);

    free(v);
    dlclose(handle);
    return 0;
}
