#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

const int MAX_STR = 100;

static void bubble_sort(char** ptr, int counter_strings);

int count_size_file(FILE* fp);

int count_num_of_strings(int size_of_file, char* buffer);

int main(void) {

    FILE* fp = fopen("testonegin.txt", "rb");
    int size_of_file = 0;
    size_of_file = count_size_file(fp);
    printf("%ld\n", size_of_file);

    char* buffer = (char*)calloc(size_of_file + 1, sizeof(char));
    fread(buffer, sizeof(char), size_of_file, fp);
    printf("%s\n", buffer);

    int counter_strings = 0;
    char c = 0;
    for (int i = 0; i < size_of_file; i++) {
        printf("%c", *(buffer + i));
    }

    counter_strings = count_num_of_strings(size_of_file, buffer);
    printf("number of strings = %d\n", counter_strings);
    char** ptr2 = (char**)calloc(counter_strings + 1, sizeof(char*));

    int k = 1;
    *ptr2 = buffer;
    for (int i = 0; i < size_of_file; i++) {
        if (*(buffer + i) == '\n') {
            *(ptr2 + k) = (buffer + i + 1);
            *(buffer + i) = '\0';
            k++;
        }
    }
    for (int i = 0; i < counter_strings; i++) {
        printf("%s", *(ptr2 + i));
    }

    bubble_sort(ptr2, counter_strings);

    for (int i = 0; i < counter_strings; i++) {
        printf("%s\n", *(ptr2 + i));
    }

    return 0;
}


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

static void bubble_sort(char** ptr, int counter_strings) {
    char* temp;
    for (int i = 0; i < counter_strings - 1; i++) {
        for (int j = 1; j < counter_strings; j++) {
            if (*(ptr + i) < *(ptr + j)) {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
}
