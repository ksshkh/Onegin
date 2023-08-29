#include <TXLib.h>
#include <math.h>
#include "solver_equation.h"
#include "colors.h"
#include "input_output.h"

void skip_word(void) {
  scanf("%*s");
}

double read_coeff (FILE* file) {
  double number = 0;
  while (fscanf(file, "%lf", &number) != 1) {
    skip_word();
    printf(RED("Please, enter a number.\n"));
  }
  return number;
}

coefficients_of_sq_equation save_coefs_in_structure (FILE* file) {
  coefficients_of_sq_equation coef = {};
  coef.a = read_coeff(file);
  coef.b = read_coeff(file);
  coef.c = read_coeff(file);

  return coef;
}

void print_results_of_solving(solutions real_root) {
  switch (real_root.nroots) {
    case NO_ROOTS:
      printf(PINK("No roots.\n"));
      break;
    case SINGLE_ROOT:
      printf(PINK("x = %.5lf\n"), real_root.x1);
      break;
    case TWO_ROOTS:
      printf(PINK("x1 = %.5lf\nx2 = %.5lf\n"), real_root.x1, real_root.x2);
      break;
    case INFINITY_ROOTS:
      printf(PINK("x - any number.\n"));
      break;
    default:
      assert(!"Reached default case!");
      break;
  }
} // in->out документация изменить названия переменных
