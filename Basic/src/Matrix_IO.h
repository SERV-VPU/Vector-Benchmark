#ifndef MATRIX_IO_H_
#define MATRIX_IO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void randFillMatrix2D(const uint32_t height,const uint32_t width, int8_t matrix[height][width]);
void fillMatrix2D(const uint32_t height,const uint32_t width, int8_t matrix[height][width],int8_t number);
void randFillVector(const uint32_t N, int8_t vector[N]);
void fillVector(const uint32_t N, int8_t vector[N],int8_t number);
void printVector(const uint32_t N, int8_t vector[N]);
void printMatrix2D(const uint32_t height,const uint32_t width, int8_t matrix[height][width]);
int8_t getRandomNumber();


#endif /* MATRIX_IO_H_ */
