#ifndef VECTOR_OPERATIONS_H_
#define VECTOR_OPERATIONS_H_

#include <stdlib.h>
#include <stdint.h>

#define MAX_INT8_T 127
#define MIN_INT8_T -128

void vect_add(unsigned int N, const int8_t *vec1, const int8_t *vec2, int8_t *vecOut);

void vect_ReLu(unsigned int N, const int8_t *vec1, int8_t *vecOut);
void vect_ReLu6(unsigned int N, const int8_t *vec1, int8_t *vecOut);

int8_t saturate_16bit_to_8bit(int16_t input);
int8_t saturate_32bit_to_8bit(int32_t input);

#endif