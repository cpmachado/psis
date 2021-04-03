/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/* FUNCTION DEFINITIONS */
int
main(void) {
    char v1[100];
    char v2[100];
    int i;

    printf("Write a word: ");
    if (!fgets(v1, 100, stdin)) {
        fprintf(stderr, "main: Failed to read buffer\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; v1[i]; i++) {
        v2[i] = toupper(v1[i]);
    }

    printf("Converted string: %s", v2);
    return 0;
}

