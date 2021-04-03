/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


/* FUNCTION IMPLEMENTATION */
int
main(void) {
    char line[100];
    int n;

    printf("Student number: ");
    if (!fgets(line, 100, stdin)) {
        printf("Failed to read number\n");
        exit(EXIT_FAILURE);
    }

    if (sscanf(line, "%d", &n) != 1) {
        printf("invalid Number\n");
        exit(-1);
    }
    srandom(n);
    printf("your own random number: %ld\n", random());

    return 0;
}

