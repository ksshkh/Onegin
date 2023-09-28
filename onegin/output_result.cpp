#include <stdio.h>
#include "output_result.h"

void print_orig(char* buffer, int size_of_file, FILE* output) {
    fprintf(output, "Original version:\n");
    for (int i = 0; i < size_of_file; i++) {
        if (*(buffer + i) == '\0') {
            *(buffer + i) = '\n';
        }
        fprintf(output, "%c", *(buffer + i));
    }
}

void print_sort(char** ptr2, int counter_strings, FILE* output) {
    for (int i = 0; i < counter_strings; i++) {
        fprintf(output, "%s\n", *(ptr2 + i));
    }
}
