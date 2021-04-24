/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "include/libra.h"
#include "include/constantsEV.h"


/* MACROS */
#define LENGTH 100
#define LIMIT  200


/* FUNCTION DECLARATIONS */

/* producerProcess: Generates numbers according and writes to pipe */
void producerProcess(void);

/* printProcess: Reads from results pipe and writes to screen*/
void printProcess(void);


/* FUNCTION DEFINITIONS */

int
main(void) {
    pid_t pid;
    if ((pid = fork()) < 0) {
        fprintf(stderr, "Error calling fork\n");
        exit(EXIT_FAILURE);
    } else if (!pid) {
        producerProcess();
        wait(NULL);
    } else {
        printProcess();
    }
    return 0;
}

void
producerProcess(void) {
    unsigned long *v;
    long int vlen = sizeof(unsigned long);
    int i;
    int fd;

    if ((fd = open(NUMBERS_PIPE_NAME, O_WRONLY)) < 0) {
        fprintf(stderr, "Couldn't open fd for %s\n", NUMBERS_PIPE_NAME);
        exit(EXIT_FAILURE);
    }

    if (!(v = randArrayULong(LENGTH, LIMIT))) {
        fprintf(stderr, "Failed to allocate array of integers\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < LENGTH; i++) {
        write(fd, &v[i], vlen);
    }

    sleep(1);

    free(v);
    close(fd);
}

void
printProcess(void) {
    unsigned long v;
    long int vlen = sizeof(unsigned long);
    int fd;

    if ((fd = open(RESULTS_PIPE_NAME, O_RDONLY)) < 0) {
        fprintf(stderr, "Couldn't open fd for %s\n", NUMBERS_PIPE_NAME);
        exit(EXIT_FAILURE);
    }

    while (read(fd, &v, vlen) == vlen) {
        printf("%lu\n", v);
    }


    close(fd);
}
