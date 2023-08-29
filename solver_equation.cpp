#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solver_equation.h"
#include "colors.h"

bool compare_doubles(double x, double y) {
  const double EPS = 1e-9;
  return fabs(x - y) < EPS;
}

void solve_of_sq_equation(coefficients_of_sq_equation coef, solutions* counted_roots) {

  assert(isfinite(coef.a));
  assert(isfinite(coef.b));
  assert(isfinite(coef.c));

  assert(counted_roots != nullptr);

  if (compare_doubles(coef.a, 0)) {
    solve_of_linear_equation(coef, counted_roots);
  }
  else {
    double discr =  coef.b * coef.b - 4 * coef.a * coef.c;

    if (compare_doubles(discr, 0)) {
      counted_roots->x1 = (-coef.b) / (2 * coef.a);
      counted_roots->nroots = SINGLE_ROOT;
    }
    else if (discr > 0) {
      double square_root_d = sqrt(discr);
      counted_roots->x1 = (-coef.b + square_root_d) / (2 * coef.a);
      counted_roots->x2 = (-coef.b - square_root_d) / (2 * coef.a);
      counted_roots->nroots = TWO_ROOTS;
    }
    else {
      counted_roots->nroots = NO_ROOTS;
    }
  }

}

void solve_of_linear_equation(coefficients_of_sq_equation coef, solutions* counted_roots) {
  if (!compare_doubles(coef.b, 0)) {
    double result = -coef.c / coef.b;
    counted_roots->nroots = SINGLE_ROOT;
    counted_roots->x1 = compare_doubles(result, 0) ? 0 : result;
  }
  else {
    counted_roots->nroots = (compare_doubles(coef.c, 0)) ? INFINITY_ROOTS : NO_ROOTS;
  }
}
