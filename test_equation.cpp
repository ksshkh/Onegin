#include <TXLib.h>
#include "test_equation.h"
#include "solver_equation.h"
#include "colors.h"
#include "input_output.h"
#include "my_assert.h"

void run_tests(void) {
  FILE * test_file = fopen("tests.txt", "r"); // TODO: pass file as an argument
  ASSERT(test_file != NULL);

  int passed_tests = 0;
  int test_count = 0;
  int num = 0;
  solutions expected_roots = {}; // TODO: move closer to declaration?
  coefficients_of_sq_equation coeff = {};

  int check_test_count = fscanf(test_file, "%d", &num);
  ASSERT(check_test_count != 0); // TODO: rename ASSERT or use it differently
  ASSERT(check_test_count != EOF);

  for (int i = 0; i < num; i++) { // TODO: are test_count and i different?
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
  if (!compare_doubles(expected_roots.x1, counted_roots.x1) ||
      !compare_doubles(expected_roots.x2, counted_roots.x2) ||
      !(expected_roots.nroots == counted_roots.nroots)) {
    printf(RED("Failed the test %d.\n"), test_count);
    printf(RED("Received results:") " x1 = %lf, x2 = %lf, number of roots = %d\n",
         counted_roots.x1, counted_roots.x2, counted_roots.nroots);
    printf(RED("Expected results:") " x1 = %lf, x2 = %lf, number of roots = %d\n",
         expected_roots.x1, expected_roots.x2, expected_roots.nroots);
    return false;
  }
  return true;
}


