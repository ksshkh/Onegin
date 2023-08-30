#ifndef MY_ASSERT
#define MY_ASSERT

#define CHECK(condition)                                                                  \
    do {                                                                                  \
        if (!(condition)) {                                                               \
            printf("Assertion failed: " #condition                                        \
                   " file %s, function %s, line %d\n", __FILE__, __FUNCTION__, __LINE__); \
            }                                                                             \
    } while (0)

#endif
