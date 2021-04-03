/* Copyright 2021 Carlos Pinto Machado */
/* See LICENSE for details */

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>


/* FUNCTION DEFINITIONS */

/* concatArgs: Allocates a buffer with all strings concatenated */
char* concatArgs(int n, char *strs[]);

/* lenstr: Computes length of NULL terminated string */
unsigned long lenstr(char *s);


/* FUNCTION IMPLEMENTATIONS */

int
main(int argc, char* argv[]) {
    char *result_str = concatArgs(argc, argv);

    if (!result_str) {
        fprintf(stderr, "main: Failed to get result_str\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", result_str);
    free(result_str);
    return 0;
}

/* concatArgs: Allocates a buffer with all strings concatenated */
char*
concatArgs(int n, char *strs[]) {
    unsigned long len = 0;
    int i;
    char **ptr = strs, *ptr_arg;
    char *ptr_res = NULL, *result_str = NULL;

    if (n < 0) {
        return NULL;
    }

    /* compute length */
    for (i = 0; i < n; i++) {
        len += lenstr(*ptr);
        ptr++;
    }

    len++;
    ptr = strs;
    if (!(result_str = malloc(len))) {
        return NULL;
    }
    *result_str = '\0';
    ptr_res = result_str;
    len = 0;

    /* copy to new buffer */
    for (i = 0; i < n; i++) {
        ptr_arg = *ptr;

        while ((*ptr_res = *ptr_arg)) {
            ptr_res++;
            ptr_arg++;
        }

        ptr++;
    }

    return result_str;
}


unsigned long
lenstr(char *s) {
    unsigned long len = 0;

    while (*s) {
        len++;
        s++;
    }

    return len;
}

