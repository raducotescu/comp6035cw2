/*
 * Test.cpp
 * Author: Radu Cotescu (rdc1g10)
 *
 * Main program for coursework testing.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include "include/intdecl.hpp"
#include "include/expressions.hpp"
#include "include/integration.hpp"
using namespace std;

int main() {
	/** TASK 1 TESTS **********************************************************/
	// char
	IntDecl<0>::RET a = 0;
	assert(sizeof(a) == sizeof(char));
	IntDecl2<0>::RET b = 0;
	assert(sizeof(b) == sizeof(char));

	// unsigned int
	IntDecl<65535>::RET c = 65535;
	assert(sizeof(c) == sizeof(unsigned int));
	IntDecl2<65535>::RET d = 65535;
	assert(sizeof(d) == sizeof(unsigned int));

	// int
	IntDecl<-32768>::RET e = -32768;
	assert(sizeof(e) == sizeof(int));
	IntDecl2<-32768>::RET f = -32768;
	assert(sizeof(f) == sizeof(int));

	// long
	IntDecl<65536>::RET g = 65536;
	assert(sizeof(g) == sizeof(long));
	IntDecl2<65536>::RET h = 65536;
	assert(sizeof(h) == sizeof(long));

	printf("TASK 1 TESTS: SUCCESS!\n");
	/** END TASK 1 TESTS ******************************************************/

	/** TASK 2 TESTS **********************************************************/
	Variable x;
	assert(((x^3) + (x^2) + 1).eval(2.0) == 13);
	printf("TASK 2 TESTS: SUCCESS!\n");
	/** END TASK 2 TESTS ******************************************************/

	/** TASK 3 TESTS **********************************************************/
	assert(integrate((x^2) + 2 * x - 3, 0, 5, 5) == 51.25);
	assert(integrate(Literal(1), 1, 3, 100) == 2);
	printf("TASK 3 TESTS: SUCCESS!\n");
	/** END TASK 3 TESTS ******************************************************/
	exit(0);
}
