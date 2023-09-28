#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "sort.h"
#include "read_file.h"
#include "output_result.h"

int main(void) {

    FILE* output = fopen("print_onegin.txt", "w+");

    FILE* fp = fopen("testonegin.txt", "rb");
    int size_of_file = 0;
    size_of_file = count_size_file(fp);

    char* buffer = (char*)calloc(size_of_file + 1, sizeof(char));
    fread(buffer, sizeof(char), size_of_file, fp);

    int counter_strings = 0;
    counter_strings = count_num_of_strings(size_of_file, buffer);
    char** ptr2 = (char**)calloc(counter_strings + 1, sizeof(char*));

    part_strings(ptr2, buffer, size_of_file);

    bubble_sort(ptr2, counter_strings);
    fprintf(output, "Sort varient:\n");
    print_sort(ptr2, counter_strings, output);

    bubble_sort_reverse(ptr2, counter_strings);
    fprintf(output, "Sort varient reverse:\n");
    print_sort(ptr2, counter_strings, output);

    print_orig(buffer, size_of_file, output);

    return 0;
}
