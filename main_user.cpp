#include <TXLib.h>
#include <math.h>
#include "solver_equation.hpp"
#include "test_equation.hpp"
#include "technical.hpp"
#include "colors.hpp"

int main() {


  solutions real_root = {};

  printf(COLOR_PROGRAM "Enter the coefficients a, b, c, to solve a quadratic equation of the form\nax^2 + bx + c = 0\n" COLOR_NORMAL);
  printf(COLOR_PROGRAM "(The program accepts only numbers)\n" COLOR_NORMAL);

  coefficients_of_sq_equation coef = save_coefs_in_structure(stdin);

  solver_of_sq_equation(coef, &real_root);

  // real_root.nroots = -10;
  print_results(real_root);

  return 0;
}
