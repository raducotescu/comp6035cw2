/*
 * Test.cpp
 * Author: Radu Cotescu (rdc1g10)
 *
 * Main program for coursework testing.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./include/intdecl.hpp"


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
	exit(0);
}
