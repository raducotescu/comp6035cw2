/*
 * differentiation.hpp
 * Author: Radu Cotescu (rdc1g10@soton.ac.uk)
 *
 * Part 4: Symbolic Differentiation
 * Write a series of C++ templates which accept an expression template from Part
 * 2 such that the templates collectively symbolically perform the
 * differentiation operation (with respect to the single variable x) on this
 * expression. The template should transform its input expression template in to
 * another expression template representing the derivative of the expression.
 *
 * The derivatives should be calculated as follows:
 * 		Der( e + f ) = Der( e ) + Der( f )
 * 		Der( e * f ) = ( e * Der( f ) ) + ( Der( e ) + f )
 * 		Der( e – f ) = Der( e ) – Der( f )
 * 		Der( e / f ) = ( f * Der( e ) – e * Der( f )) / f^2
 * 		Der(e^n) = n * e^(n-1) * Der( e )
 *
 * Show how to use these templates to generate code for a short example program
 * that calculates the value of the derivative of:
 * 		(x^20 + 3) / (x - 3)
 * at values x = 5 and x = 10.
 */

#ifndef DIFFERENTIATION_HPP_
#define DIFFERENTIATION_HPP_
#include "expressions.hpp"
template <class Expression> double differentiate(Expression e, double d) {
	return e.der(d);
};
#endif /* DIFFERENTIATION_HPP_ */
