#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "comparators.h"

int comparator(char** s1, char** s2) {
    while(!isalpha(**s1)) {
        (*s1)++;
    }
    while(!isalpha(**s2)) {
        (*s2)++;
    }
    return strcmp (*s1, *s2);
}

int reverse_comparator(char* s1, char* s2) {
    int len1 = 0;
    int len2 = 0;
    len1 = strlen(s1);
    len2 = strlen(s2);

    while(!isalpha(*(s1 + len1))) {
        len1--;
    }
    while(!isalpha(*(s2 + len2))) {
        len2--;
    }
    while (len1 > 0 && len2 > 0 && *(s1 + len1) == *(s2 + len2)) {
        len1--;
        len2--;
    }
    while (len1 == 0 || len2 == 0) {
        return 0;
    }

    return *(s1 + len1) - *(s2 + len2);
}

