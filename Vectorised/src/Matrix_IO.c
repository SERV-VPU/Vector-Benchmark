#include "Matrix_IO.h"
#include "tinyio.h"

int8_t getRandomNumber(){
	// return rand()%32-16;
	return 5;
}

void randFillMatrix2D(const uint32_t height,const uint32_t width, int8_t matrix[height][width]){
	for(uint32_t h=0;h<height;h++){
		for(uint32_t w=0;w<width;w++){
			matrix[h][w]= getRandomNumber();
		}
	}
}

void fillMatrix2D(const uint32_t height,const uint32_t width, int8_t matrix[height][width],int8_t number){
	for(uint32_t h=0;h<height;h++){
		for(uint32_t w=0;w<width;w++){
			matrix[h][w]= number;
		}
	}
}

void randFillVector(const uint32_t N, int8_t vector[N]){
	for(uint32_t n=0;n<N;n++){
		vector[n]= getRandomNumber();
	}
}

void fillVector(const uint32_t N, int8_t vector[N],int8_t number){
	for(uint32_t n=0;n<N;n++){
		vector[n]= number;
	}
}

void printMatrix2D(const uint32_t height,const uint32_t width, int8_t matrix[height][width]){
	printf_("\n");
	for(uint32_t h=0;h<height;h++){
		for(uint32_t w=0;w<width;w++){
			printf_(" %4d ",matrix[h][w]);
		}
		printf_("\n");
	}
	printf_("\n");
}

void printVector(const uint32_t N, int8_t vector[N]){
	printf_("\n");
	for(uint32_t n=0;n<N;n++){
		printf_(" %4d ",vector[n]);
	}
	printf_("\n");
}
