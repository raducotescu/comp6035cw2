/*
 * IntDecl.hpp
 * Author: Radu Cotescu (rdc1g10)
 *
 * Part 1: Integer Declarations
 * Write a C++ template meta-program, IntDecl, which accepts an integer value
 * and calculates the smallest primitive type which represents that value
 * according to the following ranges:
 * Input value:
 * 		0 to 255 is type: char
 * 		0 to 65535 is type: unsigned int
 * 		-32768 to 32767 is type: int
 * 		any other integer value is type: long
 *
 * Values which fall in to two or more ranges should be given the first type
 * found in the list ordered above.
 *
 * Provide a short example program in which you instantiate your template
 * meta-program on a value in each of the ranges.
 */
#ifndef INTDECL_HPP_
#define INTDECL_HPP_
enum DataType {CHAR, UNSIGNED_INT, INT, LONG};

/*
 * Template used to decide what is the proper size for the value of N.
 * @param N the value to be analyzed
 */
template<int N> struct Decider {
	static const DataType
		RET =
			0 <= N && N <= 255 ? CHAR :
			0 <= N && N <= 65535 ? UNSIGNED_INT :
			-32768 <= N && N <= 32767 ? INT :
			LONG;
};

/*
 * Helper template used to associate the value in the Decider::RET with a
 * char C++ data type.
 * @param deciderValue a Decider template constant
 */
template<DataType deciderValue> struct TypeSpecifier {
	typedef char RET;
};

/*
 * Specialization of the TypeSpecifier template for unsigned integers.
 */
template<> struct TypeSpecifier<UNSIGNED_INT> {
	typedef unsigned int RET;
};

/*
 * Specialization of the TypeSpecifier template for integers.
 */
template<> struct TypeSpecifier<INT> {
	typedef int RET;
};

/*
 * Specialization of the TypeSpecifier template for long.
 */
template<> struct TypeSpecifier<LONG> {
	typedef long RET;
};

/*
 * main template used for declarations
 */
template<int N> struct IntDecl {
	typedef typename TypeSpecifier<Decider<N>::RET>::RET RET;
};

#endif /* INTDECL_HPP_ */
