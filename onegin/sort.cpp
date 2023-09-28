#include <stdio.h>
#include "sort.h"
#include "comparators.h"

void bubble_sort(char** ptr, int counter_strings) {
    char* temp;
    int check = 0;
    for (int i = 0; i < counter_strings; i++) {
        for (int j = 0; j < counter_strings; j++) {
            check = comparator(ptr + i, ptr + j);
            if (check < 0) {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
}

void bubble_sort_reverse(char** ptr, int counter_strings) {
    char* temp;
    int check = 0;
    for (int i = 0; i < counter_strings; i++) {
        for (int j = 0; j < counter_strings; j++) {
            check = reverse_comparator(*(ptr + i), *(ptr + j));
            if (check < 0) {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
}

