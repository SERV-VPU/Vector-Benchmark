#include "vector_operations.h"

void vect_add(unsigned int N, const int8_t *vec1, const int8_t *vec2, int8_t *vecOut){
	for(unsigned int n =0; n<N; n++){
		vecOut[n]=saturate_16bit_to_8bit( vec1[n] + vec2[n] );
	}
}

void vect_ReLu(unsigned int N, const int8_t *vec1, int8_t *vecOut){
	for(unsigned int n =0; n<N; n++){
		if(vec1[n]<(int8_t)0){
			vecOut[n]= 0;
		}else{
			vecOut[n]=vec1[n];
		}
	}
}

void vect_ReLu6(unsigned int N, const int8_t *vec1, int8_t *vecOut){     //maybe add another parameter to define max value; unsigned int maxValue=6
	for(unsigned int n =0; n<N; n++){
		if(vec1[n]<(int8_t)0){
			vecOut[n]= 0;
		}else if(vec1[n]>(int8_t) 6){
			vecOut[n]=6;
		}else{
			vecOut[n]=vec1[n];
		}
	}
}

int8_t saturate_16bit_to_8bit(int16_t input){
	if(input>MAX_INT8_T){
		return MAX_INT8_T;
	}else if(input<MIN_INT8_T){
		return MIN_INT8_T;
	}else{
		return (int8_t)input;
	}
}

int8_t saturate_32bit_to_8bit(int32_t input){
	if(input>MAX_INT8_T){
		return MAX_INT8_T;
	}else if(input<MIN_INT8_T){
		return MIN_INT8_T;
	}else{
		return (int8_t)input;
	}
}
