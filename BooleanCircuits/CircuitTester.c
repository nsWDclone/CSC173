#include <stdio.h>
#include <math.h>
#include "CircuitTester.h"

static char* b2s(bool b) {
	return b ? "T" : "F";
}

void test_all(Circuit* c){
	int cols = Circuit_numInputs(c);
  int rows = pow(2.0, cols);
  for(int i=0; i<rows; i++){
		int binaryRowNum[cols];
		for(int j=0; j<cols; j++){
			binaryRowNum[cols-j-1] = (i >> j)&1;
		}
		for(int k=0; k<cols; k++){
    	Circuit_setInput(c, k, binaryRowNum[k]);
			printf("%s ", b2s(binaryRowNum[k]));
		}
		Circuit_update(c);
		printf("-> ");
		for(int l=0; l<Circuit_numOutputs(c); l++){
			printf("%s ", b2s(Circuit_getOutput(c, l)));
		}
		printf("\n");
  }
}
