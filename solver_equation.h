#ifndef SOLVER_EQUATION
#define SOLVER_EQUATION

#include "input_output.h"

//----------------------------------------------------------------------------------------------
/// @brief Compare two double numbers
///
/// @param [in]  x   The first number
/// @param [in]  y   The second number
///
/// @return True if the numbers are equal and false in other case
//----------------------------------------------------------------------------------------------
bool compare_doubles(double x, double y);

//----------------------------------------------------------------------------------------------
/// @brief Solves a square equation ax^2 + bx + c = 0
///
/// @param [in]  coef   Coefficients of the equation (a, b, c)
/// @param [out] counted_roots  Roots of the equation (x1, x2) and number of root (nroots)
///
/// @note If a = 0, the solve_of_linear_equation function is called
//----------------------------------------------------------------------------------------------
void solve_of_sq_equation(coefficients_of_sq_equation coef, solutions* counted_roots);

//----------------------------------------------------------------------------------------------
/// @brief Solves a line equation bx + c = 0
///
/// @param [out] counted_roots  Roots of the equation (x1, x2) and number of rootd (nroots)
//----------------------------------------------------------------------------------------------
void solve_of_linear_equation(coefficients_of_sq_equation coef, solutions* counted_roots);

#endif
