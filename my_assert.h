#ifndef MY_ASSERT
#define MY_ASSERT

#define ASSERT(condition)                                                              \
  if (!(condition))                                                                    \
      printf("Assertion failed: " #condition                                           \
             "file %s, function %s, line %d\n", __FILE__, __FUNCTION__, __LINE__)

#endif
