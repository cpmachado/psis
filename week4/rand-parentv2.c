/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/* MACROS */

#define N_CHILDREN 10


/* FUNCTION DEFINITIONS */

int
main(void) {
    pid_t pid;
    int i;
    long int t;


    for (i = 0; i < N_CHILDREN; i++) {
        t = random() % 10 + 1;
        if ((pid = fork()) < 0) {
            fprintf(stderr, "Error calling fork\n");
            exit(EXIT_FAILURE);
        } else if (!pid) {
            sleep(10);
            pid = getpid();
            printf("pid: %d, t: %ld s\n", pid, t);
            exit(EXIT_SUCCESS);
        }
    }

    /* wait for each of the children processes */
    for (i = 0; i < N_CHILDREN; i++) {
        wait(NULL);
    }
    return 0;
}

