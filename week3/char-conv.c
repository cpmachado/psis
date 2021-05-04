/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int
main(void) {
    char v1[100];
    char v2[100];
    int i;

    printf("Write a word: ");
    fgets(v1, 100, stdin);

    for (i = 0; v1[i] ; i++) {
        v2[i] = toupper(v1[i]);
    }

    printf("Converted string: %s", v2);

    return 0;
}
