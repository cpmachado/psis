/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>


/* FUNCTION DEFINITIONS */
int
main(void) {
    char line[100];
    int n;

    printf("Student number: ");
    if (!fgets(line, 100, stdin)) {
        fprintf(stderr, "Failed to read number\n");
        exit(EXIT_FAILURE);
    }

    if (sscanf(line, "%d", &n) != 1) {
        fprintf(stderr, "Invalid Number\n");
        exit(EXIT_FAILURE);
    }

    srandom(n);
    printf("your own random number: %ld\n", random());

    return 0;
}

