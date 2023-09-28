#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "read_file.h"

int count_size_file(FILE* fp) {
    struct stat buff;
    fstat(fileno(fp), &buff);
    return buff.st_size;
}

int count_num_of_strings(int size_of_file, char* buffer) {
    int counter_strings = 0;
    for (int i = 0; i < size_of_file; i++) {
        if (*(buffer + i) == '\n') {
            counter_strings++;
        }
    }
    return counter_strings;
}

void part_strings (char** ptr2, char* buffer, int size_of_file) {
    int k = 1;
    *ptr2 = buffer;
    for (int i = 0; i < size_of_file; i++) {
        if (*(buffer + i) == '\n') {
            *(ptr2 + k) = (buffer + i + 1);
            *(buffer + i) = '\0';
            k++;
        }
    }
}
