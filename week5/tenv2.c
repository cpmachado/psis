/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>


/* MACROS */
#define N_THREADS 10


/* FUNCTION DECLARATIONS */

/* incrementThread: increment a given thread every random seconds */
void* pidTidThread(void* data);


/* FUNCTION DEFINITIONS */

int
main(void) {
    pthread_t tid[N_THREADS];
    unsigned long t[N_THREADS];
    int i;
    void *res;



    for (i = 0; i < N_THREADS; i++) {
        t[i] = random() % 11;
        if (pthread_create(&tid[i], NULL, pidTidThread, (void*)&t[i])) {
            fprintf(stderr, "Failed to create thread\n");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < N_THREADS; i++) {
        pthread_join(tid[i], &res);
    }
    return 0;
}


void*
pidTidThread(void* data) {
    unsigned long t = *(unsigned long*)data;
    pid_t pid = getpid();
    pthread_t tid = pthread_self();

    sleep(t);
    printf("pid: %d, tid: %lu, t: %lu\n", pid, (unsigned long)tid, t);

    return NULL;
}
