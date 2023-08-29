#include <TXLib.h>
#include "test_equation.h"
#include "solver_equation.h"
#include "colors.h"
#include "input_output.h"

#define ASSERT(condition)                                                              \
  if (!(condition))                                                                    \
  {                                                                                    \
      printf("Assertion failed: " #condition                                           \
             "file %s, function %s, line %d\n", __FILE__, __FUNCTION__, __LINE__);     \
  }

void run_tests(void) {
  FILE * test_file = fopen("tests.txt", "r");
  ASSERT(test_file != NULL)

  int passed_tests = 0;
  int test_count = 0;
  int num = 0;
  solutions expected_roots = {};
  coefficients_of_sq_equation coeff = {};

  int check = fscanf(test_file, "%d", &num);
  ASSERT(check != 0)
  ASSERT(check != -1)

  for (int i = 0; i < num; i++) {
    fscanf(test_file,
         "%lf, %lf, %lf, %lf, %lf, %d",
         &coeff.a, &coeff.b, &coeff.c,
         &expected_roots.x1, &expected_roots.x2, &expected_roots.nroots);
    test_count++;
    if (test_solver_of_sq_equation(coeff, test_count, expected_roots)) {
      passed_tests++;
    }
  }
  printf(GREEN("%d/%d tests passed!\n"), passed_tests, test_count);
}

bool test_solver_of_sq_equation(coefficients_of_sq_equation coef,
                                int test_count,
                                solutions expected_roots) {

  solutions counted_roots = {};
  solve_of_sq_equation(coef, &counted_roots);

  if (compare_doubles(expected_roots.x1, counted_roots.x1) &&
      compare_doubles(expected_roots.x2, counted_roots.x2) &&
      expected_roots.nroots == counted_roots.nroots) {
    return true;
  }
  else {
    printf(RED("Failed the test %d.\n"), test_count);
    printf(RED("Received results:") " x1 = %lf, x2 = %lf, number of roots = %d\n",
             counted_roots.x1, counted_roots.x2, counted_roots.nroots);
    printf(RED("Expected results:") " x1 = %lf, x2 = %lf, number of roots = %d\n",
             expected_roots.x1, expected_roots.x2, expected_roots.nroots);
    return false;
  }
}


