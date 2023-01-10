#include <stdint.h>
#include "main.h"
#include "tinyio.h"
#include "soc.h"
#include "implementations.h"
#include "NN_operations/vector_operations.h"
#include "NN_operations/matrix_operations.h"
#include "Matrix_IO.h"

int main(void) {
	uart_bitbang_init();
	printf_("Starting the tests\r\n");

	unsigned long startCycles, endCycles, cyclesToRun;
	unsigned long Cycles_total=0, Cycles_add=0, Cycles_relu=0, Cycles_relu6=0, Cycles_matrix=0;

	startCycles=getCycles();
	
	testbench_vectorAdd(&Cycles_add);
	testbench_vectorReLu(&Cycles_relu);
	testbench_vectorReLu6(&Cycles_relu6);
	testbench_matrix_add_d8(&Cycles_matrix);
	
	endCycles=getCycles();
	cyclesToRun=endCycles-startCycles;
	Cycles_total = Cycles_add + Cycles_relu + Cycles_relu6 + Cycles_matrix;
		
	printf_("\n\n");
	printf_(" Number of cycles to run just vector_add: %lu\n",Cycles_add);
	printf_("\n");
	printf_(" Number of cycles to run just vector_relu: %lu\n",Cycles_relu);
	printf_("\n");
	printf_(" Number of cycles to run just vector_relu6: %lu\n",Cycles_relu6);
	printf_("\n");
	printf_(" Number of cycles to run just matrix_add: %lu\n",Cycles_matrix);
	printf_("\n");
	printf_(" Number of cycles to run all vector operations: %lu\n",Cycles_total);
	printf_("\n");
	printf_(" Total Number of cycles to run testbenchs: %lu\n",cyclesToRun);

    return 0;
}

unsigned long getCycles(void){
	return get_mtime();
}

void testbench_vectorAdd(unsigned long *Cycles_NN_operations){
	for (int i = 0; i <= 3; i++) {
		unsigned long startCycles, endCycles;
		const uint32_t N[4] = {4,8,64,128};
		int8_t A[N[i]],B[N[i]],C[N[i]];
		printf_("\ntestbench_vecAdd\n\n");
		randFillVector(N[i],A);
		randFillVector(N[i],B);
		printf_("Vector A:");
		printVector(N[i],A);
		printf_("Vector B:");
		printVector(N[i],B);

		startCycles=getCycles();
		vect_add(N[i],A,B, C);
		endCycles=getCycles();
		
		printf_("\nOutput:\n");
		printVector(N[i],C);
		printf_("\n\n");
		printf_("\nTook: %lu\n", (endCycles-startCycles));
		printf_("\n\n");
		*Cycles_NN_operations +=(endCycles-startCycles);
	}
}

void testbench_vectorReLu(unsigned long *Cycles_NN_operations){
	for (int i = 0; i <= 3; i++) {
		unsigned long startCycles, endCycles;
		const uint32_t N[4] = {4,8,16,32};
		int8_t A[N[i]],C[N[i]];
		printf_("\ntestbench_ReLu\n\n");
		randFillVector(N[i],A);
		printf_("Vector A:");
		printVector(N[i],A);

		startCycles=getCycles();
		vect_ReLu(N[i],A, C);
		endCycles=getCycles();
			
		printf_("\nOutput:\n");
		printVector(N[i],C);
		printf_("\n\n");
		printf_("\nTook: %lu\n", (endCycles-startCycles));
		printf_("\n\n");
		*Cycles_NN_operations +=(endCycles-startCycles);
	}
}

void testbench_vectorReLu6(unsigned long *Cycles_NN_operations){
	for (int i = 0; i <= 3; i++) {
		unsigned long startCycles, endCycles;
		const uint32_t N[4] = {4,8,16,32};
		int8_t A[N[i]],C[N[i]];
		printf_("\ntestbench_ReLu6\n\n");
		randFillVector(N[i],A);
		printf_("Vector A:");
		printVector(N[i],A);

		startCycles=getCycles();
		vect_ReLu6(N[i],A, C);
		endCycles=getCycles();
			
		printf_("\nOutput:\n");
		printVector(N[i],C);
		printf_("\n\n");
		printf_("\nTook: %lu\n", (endCycles-startCycles));
		printf_("\n\n");
		*Cycles_NN_operations +=(endCycles-startCycles);
	}
}


void testbench_matrix_add_d8(unsigned long *Cycles_NN_operations){
	for (int i = 0; i <= 3; i++) {
		unsigned long startCycles, endCycles;
		const uint32_t N[4] = {4,8,16,32};
		int8_t MatA[N[i]][N[i]], MatB[N[i]][N[i]],MatC[N[i]][N[i]];

		printf_("\ntestbench_matrix_add_d8  \n");
		randFillMatrix2D(N[i],N[i],MatA);
		randFillMatrix2D(N[i],N[i],MatB);


		printf_("\nMatrix A:\n");
		printMatrix2D(N[i],N[i],MatA);
		printf_("Matrix B:\n");
		printMatrix2D(N[i],N[i],MatB);

		startCycles=getCycles();
		matrix_add_d8(N[i],N[i],MatA,MatB,MatC);
		endCycles=getCycles();
		
		printf_("Output:\n");
		printMatrix2D(N[i],N[i],MatC);
		printf_("\n\n");
		printf_("\nTook: %lu\n", (endCycles-startCycles));
		printf_("\n\n");
		*Cycles_NN_operations +=(endCycles-startCycles);
	}
}
