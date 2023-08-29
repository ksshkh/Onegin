#ifndef TEST_EQUATION
#define TEST_EQUATION

#include "solver_equation.h"
#include "interactive_solver.h"

//----------------------------------------------------------------------------------------------
/// @brief Run all tests
//----------------------------------------------------------------------------------------------
void run_tests(void);

//----------------------------------------------------------------------------------------------
/// @brief Check whether the received results match the expected ones
///
/// @param [in]  coef   Coefficients of the equation (a, b, c)
/// @param [in]  expected_root   Expected roots and their number (x1_exp, x2_exp, num_exp)
/// @param [in]  test_count  Number of test
///
/// @return True if the numbers are equal and false in other case
//----------------------------------------------------------------------------------------------
bool test_solver_of_sq_equation(coefficients_of_sq_equation coef,
                                int test_count,
                                solutions expected_roots);

#endif
