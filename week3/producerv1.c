/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>

#include "include/libra.h"


/* MACROS */
#define LENGTH 100
#define LIMIT  200


/* FUNCTION DEFINITIONS */

int
main(void) {
    unsigned long *v;
    unsigned long i;

    if (!(v = randArrayULong(LENGTH, LIMIT))) {
        fprintf(stderr, "Failed to allocate array of integers\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < LENGTH; i++) {
        fprintf(stdout, "%lu\n", v[i]);
    }

    free(v);
    return 0;
}
