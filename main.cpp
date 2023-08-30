#include <stdio.h>
#include <string.h>
#include <math.h>
#include "solver_equation.h"
#include "test_equation.h"
#include "interactive_solver.h"
#include "colors.h"

int main(int argc, const char* argv[]) {

  if (process_args(argc, argv) == true) {
    return 0;
  }

  solutions counted_roots = {};

  printf(BLUE("Enter the coefficients a, b, c, to solve a quadratic equation of the form\nax^2 + bx + c = 0\n"));
  printf(BLUE("(The program accepts only numbers)\n"));

  coefficients_of_sq_equation coeff = get_coeffs(stdin);

  solve_of_sq_equation(coeff, &counted_roots);

  print_results_of_solving(counted_roots);

  return 0;
}
