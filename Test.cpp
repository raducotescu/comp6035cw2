/*
 * Test.cpp
 * Author: Radu Cotescu (rdc1g10)
 *
 * Main program for coursework testing.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./include/IntDecl.hpp"


int main() {
	/** TASK 1 TESTS **********************************************************/
	IntDecl<0>::RET a = 0;
	assert(sizeof(a) == sizeof(char));			// char test

	IntDecl<65535>::RET b = 65535;
	assert(sizeof(b) == sizeof(unsigned int));	// unsigned int test

	IntDecl<-32768>::RET c = -32768;
	assert(sizeof(c) == sizeof(int));			// int test

	IntDecl<65536>::RET d = 65536;
	assert(sizeof(d) == sizeof(long));			// long test

	printf("TASK 1 TESTS: SUCCESS!\n");
	/** END TASK 1 TESTS ******************************************************/
	exit(0);
}
