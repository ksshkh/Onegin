#ifndef READ_FILE
#define READ_FILE

#include "sort.h"

const int MAX_STR = 100;

int count_size_file(FILE* fp);

int count_num_of_strings(int size_of_file, char* buffer);

void part_strings (char** ptr2, char* buffer, int size_of_file);

#endif
