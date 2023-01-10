#ifndef NN_ALGORITHMS_TESTBENCH_H_
#define NN_ALGORITHMS_TESTBENCH_H_

int main(void);

unsigned long getCycles(void);

void testbench_vectorAdd(unsigned long *Cycles_NN_operations);
void testbench_vectorReLu(unsigned long *Cycles_NN_operations);
void testbench_vectorReLu6(unsigned long *Cycles_NN_operations);

void testbench_matrix_add_d8(unsigned long *Cycles_NN_operations);

#endif /* NN_ALGORITHMS_TESTBENCH_H_ */
