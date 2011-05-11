/*
 * integration.hpp
 * Author: Radu Cotescu (rdc1g10@soton.ac.uk)
 *
 * Part 3: Numerical Integration
 * Use the expression templates from Part 2 to write a C++ template which
 * accepts arithmetic expressions and generates code for numerically
 * approximating the integral of that expression with respect to the single
 * variable. Your template should provide a function named "integrate" which
 * accepts double values as the lower and upper limits of the range to be
 * integrated over. This function should also accept an integer value which
 * specifies the number of divisions of the range by which the integral is
 * approximated.
 *
 * Show how to use this template to generate code for a short example program
 * which numerically integrates the arithmetic expression:
 *
 * 		x^2+2*x-3
 *
 */

#ifndef INTEGRATION_HPP_
#define INTEGRATION_HPP_
/*
 * Template function that calculates the definite Integral of an expression.
 * @param e the expression
 * @param low the lower limit
 * @param up the upper limit
 * @param divisions the number of divisions of the range by which the integral
 * 		is approximated
 */
template<class Expression> double integrate(Expression e, double low, double up,
		int divisions) {
	double sum = 0, step = (up - low) / divisions;
	for (double i = low + step / 2; i < up; i += step)
		sum += e.eval(i);
	return step * sum;
}
#endif /* INTEGRATION_HPP_ */
