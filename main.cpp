#include <TXLib.h>
#include <math.h>
#include "solver_equation.h"
#include "test_equation.h"
#include "input_output.h"
#include "colors.h"

int main(int argc, const char* argv[]) {
  if (argc != 2) {
    printf("Run programm again and enter --test, --use or --help");
    return 0;
  }

  if (strcmp(argv[1], "--help") == 0) {
    printf("Enter --test to test the programm or --use to use it");
    return 0;
  }

  else if (strcmp(argv[1], "--test") == 0) {
    run_tests();
    return 0;
  }

  else if (strcmp(argv[1], "--use") == 0) {

    solutions counted_roots = {};

    printf(BLUE("Enter the coefficients a, b, c, to solve a quadratic equation of the form\nax^2 + bx + c = 0\n"));
    printf(BLUE("(The program accepts only numbers)\n"));

    coefficients_of_sq_equation coef = save_coeffs(stdin);

    solve_of_sq_equation(coef, &counted_roots);

    print_results_of_solving(counted_roots);

    return 0;
  }
}
