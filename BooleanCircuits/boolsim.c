#include <stdio.h>
#include <stdlib.h>
#include "Circuit.h"
#include "CircuitBuilder.h"
#include "CircuitTester.h"

int main(int argc, char **argv) {
	printf("Circuit A:\nX Y Z   OUT\n-----------\n");
	test_all(build_circuit_A());

	printf("\nCircuit B:\nX Y Z   OUT\n-----------\n");
	test_all(build_circuit_B());

	printf("\nCircuit C:\nX Y   OUT\n---------\n");
	test_all(build_circuit_C());

	printf("\nOne-bit adder:\nX Y C    D Z\n------------\n");
	test_all(build_circuit_ADDER());
}
