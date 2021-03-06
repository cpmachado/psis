/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/libra.h"


/* FUNCTION DEFINITIONS */

int
main(void) {
    char buffer[BUFSIZ];
    unsigned long v;

    while (fgets(buffer, BUFSIZ, stdin)) {
        if (sscanf(buffer, "%lu", &v) == 1) {
            printDivisible(1, &v);
        }
    }

    return 0;
}
