
#include <stdio.h>
#include <malloc.h>

int** matMult(int **a, int **b, int size){
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.

	int **res = (int**)malloc(size * sizeof(int*));
	for(int i = 0; i < size; i++){
		*(res+i) = (int*)malloc(size * sizeof(int));
		for(int j = 0; j < size; j++){
			// *(*(res+i)+j) = (*(*(a+i)+j) * (*(*(b+i)+j)));
			// simple multiply across grid lines implementation, placeholder

			*(*(res+i)+j) = 0; //initialize each to 0
			for(int k = 0; k < size; k++){
				*(*(res+i)+j) += ( *(*a+i)+k * *(*(b+k)+j));
			}
		}
	}

	return res;
}

void printArray(int **arr, int n){
	// (2) Implement your printArray function here

	int i, j;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}

}

int main() {
	int n = 4;
	int **matA, **matB, **matC;
	// (1) Define 2 n x n arrays (matrices). 
	
	matA = (int**)malloc(n * sizeof(int*));
	matB = (int**)malloc(n * sizeof(int*));
	for(int i = 0; i < n; i++){
		//Initialize rows
		*(matA + i) = (int*)malloc(n * sizeof(int));
		*(matB + i) = (int*)malloc(n * sizeof(int));
		for(int j = 0; j < n; j++){
			//Populate Matrix A using pattern
			*(*(matA+i)+j) = (2*j+(i));
		}
		for(int j = 0; j < n; j++){
			//Populate Matrix B using different pattern
			*(*(matB+i)+j) = (3*j+(2+i));
		}
	}

	// (3) Call printArray to print out the 2 arrays here.
	
	printf("Matrix A: \n");
	printArray(matA, n);
	printf("\n");
	printf("Matrix B: \n");
	printArray(matB, n);
	printf("\n");
	
	//(5) Call matMult to multiply the 2 arrays here.
	
	matC = matMult(matA, matB, n);
	
	//(6) Call printArray to print out resulting array here.

	printf("Matrix C: \n");
	printArray(matC, n);

    return 0;
}