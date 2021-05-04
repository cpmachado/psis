/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int
main(void) {
    char v1[100];
    char *v2;
    int i;

    printf("Write a word: ");
    fgets(v1, 100, stdin);

    if (!(v2 = (char*)malloc(sizeof(char)*(strlen(v1) + 1)))) {
        fprintf(stderr, "Failed to allocate v2\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; v1[i]; i++) {
        v2[i] = toupper(v1[i]);
    }

    printf("Converted string: %s", v2);

    free(v2);
    return 0;
}

