/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* libss: implements single step printDivisible */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/libra.h"

/* FUNCTION DEFINITIONS */

unsigned long*
randArrayULong(unsigned long len, unsigned long limit) {
    unsigned long *v;
    unsigned long i;

    if (!(v = (unsigned long*)malloc(sizeof(unsigned long) * len))) {
        fprintf(stderr, "libra: Failed to allocate array\n");
        return NULL;
    }

    srandom(time(NULL));

    for (i = 0; i < len; i++) {
        v[i] = random() % limit;
    }

    return v;
}
