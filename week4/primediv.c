/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "include/libra.h"
#include "include/libra_divisors.h"


/* MACROS */
#define LENGTH 100
#define LIMIT  200


/* FUNCTION DEFINITIONS */

int
main(void) {
    pid_t pid;
    unsigned long ndiv = sizeof(divisors) / sizeof(unsigned long);
    unsigned long i, j, d;
    unsigned long *v;

    if (!(v = randArrayULong(LENGTH, LIMIT))) {
        fprintf(stderr, "Failed to allocate array of integers\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < ndiv; i++) {
        d = divisors[i];
        if ((pid = fork()) < 0) {
            fprintf(stderr, "Error calling fork\n");
            exit(EXIT_FAILURE);
        } else if (!pid) {
            for (j = 0; j < LENGTH; j++) {
                if (v[j] % d == 0) {
                    printf("%lu -> %lu\n", v[j], d);
                }
            }

            free(v);
            exit(EXIT_SUCCESS);
        }
    }

    /* wait for each of the children processes */
    for (i = 0; i < ndiv; i++) {
        wait(NULL);
    }

    free(v);
    return 0;
}
