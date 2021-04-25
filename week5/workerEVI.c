/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#include "include/libra.h"
#include "include/constantsEVI.h"


/* MACROS */
#define LENGTH 100
#define LIMIT  200


/* FUNCTION DECLARATIONS */


/* isPrime: Returns if number is prime */
int isPrime(unsigned long n);

/* workerProcess: Writes prime numbers from NUMBERS_PIPE_NAME to
 * RESULTS_PIPE_NAME
 */
void workerProcess(void);


/* FUNCTION DEFINITIONS */

int
main(void) {
    workerProcess();
    return 0;
}


int
isPrime(unsigned long n) {
    unsigned long i, t = 9;

    if (n % 2 == 0) {
        return 0;
    }

    for (i = 3; t <= n; t = i * i) {
        if (n % i == 0) {
            return 0;
        }
        i += 2;
    }

    return 1;
}


void
workerProcess(void) {
    unsigned long v;
    long int vlen = sizeof(unsigned long);
    int fd, fw;


    if ((fd = open(NUMBERS_PIPE_NAME, O_RDONLY)) < 0) {
        fprintf(stderr, "Couldn't open fd for %s\n", NUMBERS_PIPE_NAME);
        exit(EXIT_FAILURE);
    }

    if ((fw = open(RESULTS_PIPE_NAME, O_WRONLY)) < 0) {
        fprintf(stderr, "Couldn't open fd for %s\n", RESULTS_PIPE_NAME);
        exit(EXIT_FAILURE);
    }

    while (read(fd, &v, vlen) == vlen) {
        if (isPrime(v)) {
            write(fw, &v, vlen);
        }
        fprintf(stderr, "[LOG] Processed %lu\n", v);
    }

    close(fd);
    close(fw);
}

