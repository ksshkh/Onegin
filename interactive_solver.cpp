#include <stdio.h>
#include <assert.h>
#include "colors.h"
#include "interactive_solver.h"
#include "test_equation.h"

void skip_word(void) {
  int c = 0;
  do {
    c = getchar();
  } while(c != '\n' || c != EOF);
}

double read_coeff (FILE* file) {
  double number = 0;
  while (fscanf(file, "%lf", &number) != 1) {
    skip_word();
    printf(RED("Please, enter a number.\n"));
  }
  return number;
}

coefficients_of_sq_equation get_coeffs (FILE* file) {
  coefficients_of_sq_equation coeff = {};
  coeff.a = read_coeff(file);
  coeff.b = read_coeff(file);
  coeff.c = read_coeff(file);

  return coeff;
}

void print_results_of_solving(solutions counted_roots) {
  switch (counted_roots.nroots) {
    case NO_ROOTS:
      printf(PINK("No roots.\n"));
      break;
    case SINGLE_ROOT:
      printf(PINK("x = %.5lf\n"), counted_roots.x1);
      break;
    case TWO_ROOTS:
      printf(PINK("x1 = %.5lf\nx2 = %.5lf\n"), counted_roots.x1, counted_roots.x2);
      break;
    case INFINITY_ROOTS:
      printf(PINK("x - any number.\n"));
      break;
    default:
      assert(!"Reached default case!");
      break;
  }
}
