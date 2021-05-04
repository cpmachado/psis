/* See LICENSE for details */

/* HEADERS */
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "include/libra.h"
#include "include/constantsEVI.h"


/* MACROS */
#define LENGTH 100
#define LIMIT  200


/* FUNCTION DECLARATIONS */

/* producerThread: Generates numbers according and writes to pipe */
void* producerThread(void* data);

/* printerThread: Reads from results pipe and writes to screen*/
void* printerThread(void* data);


/* FUNCTION DEFINITIONS */

int
main(void) {
    pthread_t tid[2];
    long res;

    if (pthread_create(&tid[0], NULL, producerThread, NULL)) {
        fprintf(stderr, "Failed to create producer thread\n");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&tid[1], NULL, printerThread, NULL)) {
        fprintf(stderr, "Failed to create printer thread\n");
        exit(EXIT_FAILURE);
    }
    pthread_join(tid[0], (void*)&res);
    pthread_join(tid[1], (void*)&res);
    return 0;
}

void*
producerThread(void* data) {
    unsigned long *v;
    long int vlen = sizeof(unsigned long);
    int i;
    int fd;

    (void)data;

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
    return NULL;
}

void*
printerThread(void* data) {
    unsigned long v;
    long int vlen = sizeof(unsigned long);
    int fd;

    (void)data;

    if ((fd = open(RESULTS_PIPE_NAME, O_RDONLY)) < 0) {
        fprintf(stderr, "Couldn't open fd for %s\n", NUMBERS_PIPE_NAME);
        exit(EXIT_FAILURE);
    }

    while (read(fd, &v, vlen) == vlen) {
        printf("%lu\n", v);
    }


    close(fd);
    return NULL;
}
