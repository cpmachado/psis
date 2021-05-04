/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


/* FUNCTION DEFINITIONS */

int
main(void) {
    char buffer[BUFSIZ];
    pid_t pid;

    while (fgets(buffer, BUFSIZ, stdin)) {
        if ((pid = fork()) < 0) {
            fprintf(stderr, "Error calling fork\n");
            exit(EXIT_FAILURE);
        } else if (!pid) {
            printf("%s", buffer);
            exit(EXIT_SUCCESS);
        }
    }

    return 0;
}

