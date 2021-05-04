/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* FUCTION DECLARATIONS */

/* sumlen: sum of the length of all strings */
unsigned long sumlen(int n, char* strs[]);


/* combinestrs: aggregate all strings in a single allocated buffer */
char* combinestrs(int n, char* strs[]);


/* FUNCTION DEFINITIONS */

int
main(int argc, char* argv[]) {
    char *result_str = combinestrs(argc, argv);

    if (!result_str) {
        exit(EXIT_FAILURE);
    }

    printf("%s\n", result_str);

    free(result_str);
    return 0;
}


unsigned long
sumlen(int n, char* strs[]) {
    int i;
    unsigned long sum = 0;

    for (i = 0; i < n; i++) {
        sum += strlen(strs[i]);
    }

    return sum;
}


char*
combinestrs(int n, char* strs[]) {
    int i;
    char *s;
    unsigned long len = sumlen(n, strs) + 1;

    if (!(s = (char*)malloc(sizeof(char) * len))) {
        fprintf(stderr, "combinestrs: failed to allocate string\n");
        return NULL;
    }

    *s = '\0';

    for (i = 0; i < n; i++) {
        s = strcat(s, strs[i]);
    }

    return s;
}

