#include <stdio.h>
#include "test_equation.h"
#include "solver_equation.h"
#include "colors.h"
#include "interactive_solver.h"
#include "my_assert.h"

const int SIZE = 10;

void run_tests(void) {

  printf("Enter a name of the file with tests\n");

  char name_file[SIZE];
  gets(name_file);

  FILE* test_file = fopen(name_file, "r"); // TODO: pass file as an argument
  CHECK(test_file != NULL);

  int passed_tests = 0;
  int num = 0;
  coefficients_of_sq_equation coeff = {};

  int check_test_count = fscanf(test_file, "%d", &num);
  CHECK(check_test_count != 0);
  CHECK(check_test_count != EOF);

  solutions expected_roots = {};

  for (int i = 1; i <= num; i++) {
    fscanf(test_file,
          "%lf, %lf, %lf, %lf, %lf, %d",
          &coeff.a, &coeff.b, &coeff.c,
          &expected_roots.x1, &expected_roots.x2, &expected_roots.nroots);

    if (test_solver_of_sq_equation(coeff, i, expected_roots)) {
      passed_tests++;
    }
  }
  printf(GREEN("%d/%d tests passed!\n"), passed_tests, num);
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


