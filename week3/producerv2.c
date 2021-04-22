/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "include/libra.h"


/* MACROS */
#define LENGTH 100
#define LIMIT  200
#define FIFO_NAME "/tmp/exerciseV"


/* FUNCTION DEFINITIONS */

int
main(void) {
    unsigned long *v;
    unsigned long i;
    int fd;
    FILE *fp;

    if ((fd = open(FIFO_NAME, O_WRONLY)) < 0) {
        fprintf(stderr, "Couldn't open fd for %s\n", FIFO_NAME);
        exit(EXIT_FAILURE);
    }

    if (!(fp = fdopen(fd, "w"))) {
        fprintf(stderr, "Couldn't open %s\n", FIFO_NAME);
        exit(EXIT_FAILURE);
    }

    if (!(v = randArrayULong(LENGTH, LIMIT))) {
        fprintf(stderr, "Failed to allocate array of integers\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < LENGTH; i++) {
        fprintf(fp, "%lu\n", v[i]);
    }

    free(v);
    fclose(fp);
    return 0;
}
