/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "include/libra.h"


/* MACROS */
#define FIFO_NAME "/tmp/exerciseV"



/* FUNCTION DEFINITIONS */

int
main(void) {
    char buffer[BUFSIZ];
    unsigned long v;
    int fd, dummyfw;
    FILE *fp;

    if ((fd = open(FIFO_NAME, O_RDONLY)) < 0) {
        fprintf(stderr, "Couldn't open fd for %s\n", FIFO_NAME);
        exit(EXIT_FAILURE);
    }

    if ((dummyfw = open(FIFO_NAME, O_WRONLY)) < 0) {
        fprintf(stderr, "Couldn't open dummy fd for %s\n", FIFO_NAME);
        exit(EXIT_FAILURE);
    }

    if (!(fp = fdopen(fd, "r"))) {
        fprintf(stderr, "Couldn't open %s\n", FIFO_NAME);
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFSIZ, fp)) {
        if (sscanf(buffer, "%lu", &v) == 1) {
            printDivisible(1, &v);
        }
    }

    close(dummyfw);
    fclose(fp);
    return 0;
}
