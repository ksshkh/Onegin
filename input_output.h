#ifndef TECHNICAL
#define TECHNICAL

/// @brief Number of roots
enum num_of_roots {
  NO_ROOTS = 0, ///< No roots
  SINGLE_ROOT = 1, ///< Single root
  TWO_ROOTS = 2, ///< Two roots
  INFINITY_ROOTS = 3 ///< Infinitie number of roots
};

/// @brief Coefficient names for equation ax^2 + bx + c = 0
struct coefficients_of_sq_equation {
  double a;///< The first coefficient
  double b;///< The second coefficient
  double c;///< The third coefficient
};

/// @brief Roots of equation and their number
struct solutions {
  double x1;///< The first root
  double x2;///< The second root
  int nroots;///< Number of roots
};

//----------------------------------------------------------------------------------------------
/// @brief Clear the buffer
//----------------------------------------------------------------------------------------------
void skip_word(void);

//----------------------------------------------------------------------------------------------
/// @brief Read data (coefficients)
///
/// @param [in]  file   File with data
///
/// @return The value of one coefficient
//----------------------------------------------------------------------------------------------
double read_coeff(FILE* file);

//----------------------------------------------------------------------------------------------
/// @brief Save readen data in structure with coefficients of square equation
///
/// @param [in]  file   File with data (coefficients of equations)
///
/// @return Structure with value of coefficients
//----------------------------------------------------------------------------------------------
coefficients_of_sq_equation save_coeffs(FILE* file);

//----------------------------------------------------------------------------------------------
/// @brief Output results of program
///
/// @param [in]  counted_roots   The structure with value of roots (x1, x2) and their number (nroots)
//----------------------------------------------------------------------------------------------
void print_results_of_solving(solutions counted_roots);

#endif
