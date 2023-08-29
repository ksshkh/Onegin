#include <TXLib.h>
#include <math.h>
#include "solver_equation.h"
#include "colors.h"
#include "input_output.h"

bool compare_doubles(double x, double y) {
  const double EPS = 1e-9;
  return fabs(x - y) < EPS;
}

void solve_of_sq_equation(coefficients_of_sq_equation coef, solutions* real_root) {

  assert(isfinite(coef.a));
  assert(isfinite(coef.b));
  assert(isfinite(coef.c));


  assert(real_root != nullptr);

  if (compare_doubles(coef.a, 0)) {
    solve_of_linear_equation(coef, real_root);
  }
  else {
    double D =  coef.b * coef.b - 4 * coef.a * coef.c;

    if (compare_doubles(D, 0)) {
      real_root->x1 = (-coef.b) / (2 * coef.a);
      real_root->nroots = SINGLE_ROOT;
    }
    else if (D > 0) {
      double square_root_d = sqrt(D);
      real_root->x1 = (-coef.b + square_root_d) / (2 * coef.a);
      real_root->x2 = (-coef.b - square_root_d) / (2 * coef.a);
      real_root->nroots = TWO_ROOTS;
    }
    else {
      real_root->nroots = NO_ROOTS;
    }
  }

}

void solve_of_linear_equation(coefficients_of_sq_equation coef, solutions* real_root) {
  if (!compare_doubles(coef.b, 0)) {
    double result = -coef.c / coef.b;
    if (compare_doubles(result, 0)) {
      real_root->x1 = 0;
      real_root->nroots = SINGLE_ROOT;
    }
    else {
    real_root->x1 = result;
    real_root->nroots = SINGLE_ROOT;
    }
  }
  else {
    if (compare_doubles(coef.c, 0)) {
      real_root->nroots = INFINITY_ROOTS;
    }
    else {
      real_root->nroots = NO_ROOTS;
    }
  }
}
