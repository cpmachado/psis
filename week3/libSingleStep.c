/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>

#include "include/randarray.h"


/* FUNCTION DEFINITIONS */

void
printDivisible(long len, long* array) {
    long i, j;
    long divisorLen = 4;
    long divisor[] = { 2, 3, 5, 7};
    long n, d;

    for (i = 0; i < len; i++) {
        n = array[i];
        for (j = 0; j < divisorLen; j++) {
            d = divisor[j];
            if (n % d == 0) {
                printf("%ld -> %ld\n", n, d);
            }
        }
    }
}
