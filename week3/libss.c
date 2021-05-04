/* See LICENSE for details */

/* libss: implements single step printDivisible */

/* HEADERS */
#include <stdio.h>

#include "include/libra.h"
#include "include/libra_divisors.h"

/* FUNCTION DEFINITIONS */

void
printDivisible(unsigned long len, unsigned long *array) {
    unsigned long len_divisors = sizeof(divisors) / sizeof(unsigned long);
    unsigned long i, j;
    unsigned long n, d;

    for (i = 0; i < len; i++) {
        n = array[i];
        for (j = 0; j < len_divisors; j++) {
            d = divisors[j];

            if (n % d == 0) {
                printf("%lu -> %lu\n", n, d);
            }
        }
    }
}
