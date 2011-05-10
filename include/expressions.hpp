/*
 * expressions.hpp
 * Author: Radu Cotescu (rdc1g10)
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
using namespace std;

/*
 * Class defining Literals.
 */
class Literal {
public:
	Literal(const double v) : value(v) {}
	double eval() const {
		return value;
	}
private:
	const double value;
};

/*
 * Class defining variables.
 */
class Variable {
	Variable(const double v) : value(v) {}
	double eval() const {
		return value;
	}
	;
private:
	double& value;
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
	double eval() const {
		return operation(lhs.eval(), rhs.eval());
	}
private:
	LHS lhs;
	RHS rhs;
	BinaryOperation operation;
};

/*
 * Operator overriding.
 */
template <class LHS, class RHS> BinaryExpression<LHS, RHS, plus<double> > operator+(LHS lhs, RHS, rhs) {
	return BinaryExpression<LHS, RHS, plus<double> >(lhs, rhs);
}
#endif /* EXPRESSIONS_HPP_ */
