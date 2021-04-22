/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>


int
main(void) {
    int v[100];
    int i;

    for (i = 0; i < 100; i++) {
        v[i] = random();
    }

    printf("vector initialized at %p\n", v);

    return 0;
}
