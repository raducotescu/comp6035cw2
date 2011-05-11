/*
 * expressions.hpp
 * Author: Radu Cotescu (rdc1g10@soton.ac.uk)
 *
 * Part 2: Expression Templates
 * Write C++ templates which allow you to use types to represent arithmetic
 * expressions over the four basic operations (addition, subtraction,
 * multiplication and division), a single variable, and integer exponentiation:
 * (e.g. x^2+(x-2)^3/5). For the purposes of this assignment we refer to the
 * single variable as x.
 *
 * The types representing the expressions should contain a function named "eval"
 * that provides code for evaluating the expression. This function should accept
 * a double parameter that will be used as the value for the single variable x.
 */
#ifndef EXPRESSIONS_HPP_
#define EXPRESSIONS_HPP_
#include <functional>
#include <math.h>
#include <typeinfo>
using namespace std;

/*
 * Class defining Literals (scalars).
 */
class Literal {
public:
	Literal(const double v) : value(v) {}
	double eval(double) const {
		return value;
	}
	double der(double) const {
		return 0;
	}
private:
	const double value;
};

/*
 * Class defining double variables.
 */
class Variable {
public:
	double eval(double d) const { return d; }
	double der(double d) const { return 1; }
};

/*
 * Expression traits used to convert constants of numerical types to objects
 * of type Literal.
 */
template <class Expression> struct expressionTrait {
	typedef Expression expressionType;
};

template <> struct expressionTrait<double> {
	typedef Literal expressionType;
};

template <> struct expressionTrait<int> {
	typedef Literal expressionType;
};

template <> struct expressionTrait<float> {
	typedef Literal expressionType;
};

/*
 * Exponentiation function object class.
 */
template <class T> struct exponentiation : binary_function <T, T, T> {
	T operator() (const T& m, const T& n) const {
		return pow(m, n);
	}
};

/*
 * Template defining a binary expression.
 */
template <class LHS, class RHS, class BinaryOperation> class BinaryExpression {
public:
	BinaryExpression(
			LHS _lhs,
			RHS _rhs,
			BinaryOperation _operation = BinaryOperation()
	) : lhs(_lhs), rhs(_rhs), operation(_operation) {}
	double eval(double d) const {
		return operation(lhs.eval(d), rhs.eval(d));
	}
	double der(double d) const {
		if (typeid(operation) == typeid(plus<double>)) {
			return (lhs.der(d) + rhs.der(d));
		}
		else if (typeid(operation) == typeid(minus<double>)) {
			return (lhs.der(d) - rhs.der(d));
		}
		else if (typeid(operation) == typeid(multiplies<double>)) {
			return (lhs.eval(d) * rhs.der(d) + lhs.der(d) * rhs.eval(d));
		}
		else if (typeid(operation) == typeid(divides<double>)) {
			return ((rhs.eval(d) * lhs.der(d) - lhs.eval(d) * rhs.der(d)) / (rhs^2).eval(d));
		}
		else if (typeid(operation) == typeid(exponentiation<double>)) {
			return (rhs.eval(d) * (lhs^(rhs.eval(d) - 1)).eval(d) * lhs.der(d));
		}
		else {
			assert (false);
			return 0;
		}
	}
private:
	typename expressionTrait<LHS>::expressionType lhs;
	typename expressionTrait<RHS>::expressionType rhs;
	BinaryOperation operation;
};

/*
 * Operator + overloading.
 */
template <class LHS, class RHS> BinaryExpression<LHS, RHS, plus<double> > operator+(LHS lhs, RHS rhs) {
	return BinaryExpression<LHS, RHS, plus<double> >(lhs, rhs);
}

/*
 * Operator - overloading.
 */
template <class LHS, class RHS> BinaryExpression<LHS, RHS, minus<double> > operator-(LHS lhs, RHS rhs) {
	return BinaryExpression<LHS, RHS, minus<double> >(lhs, rhs);
}

/*
 * Operator * overloading.
 */
template <class LHS, class RHS> BinaryExpression<LHS, RHS, multiplies<double> > operator*(LHS lhs, RHS rhs) {
	return BinaryExpression<LHS, RHS, multiplies<double> >(lhs, rhs);
}

/*
 * Operator / overloading.
 */
template <class LHS, class RHS> BinaryExpression<LHS, RHS, divides<double> > operator/(LHS lhs, RHS rhs) {
	return BinaryExpression<LHS, RHS, divides<double> >(lhs, rhs);
}

/*
 * Template for defining the exponentiation operation.
 */
template <class LHS, class RHS> BinaryExpression<LHS, RHS, exponentiation<double> > operator^(LHS lhs, RHS rhs) {
	return BinaryExpression<LHS, RHS, exponentiation<double> >(lhs, rhs);
}
#endif /* EXPRESSIONS_HPP_ */
