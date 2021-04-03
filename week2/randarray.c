/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdlib.h>
#include <time.h>


/* FUNCTION DEFINITIONS */

long*
randArrayLong(long len, long topLimit) {
    long *arr = NULL;
    long i;

    if (len < 0) {
        return NULL;
    }

    if (!(arr = malloc(sizeof(long) * len))) {
        return NULL;
    }

    srandom(time(NULL));

    for (i = 0; i < len; i++) {
        arr[i] = random() % topLimit + 1;
    }
    return arr;
}
