
#include <stdio.h>
#include <malloc.h>

int** matMult(int **a, int **b, int size){
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.

	int **res = (int**)malloc(size * sizeof(int*));
	for(int i = 0; i < size; i++){
		*(res+i) = (int*)malloc(size * sizeof(int));
		for(int j = 0; j < size; j++){
			*(*(res+i)+j) = (*(*(a+i)+j) * *(*(b+i)+j));
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
	int n = 10;
	int **matA, **matB, **matC;
	// (1) Define 2 n x n arrays (matrices). 

	matA = matB = (int**)malloc(n * sizeof(int*));
	for(int i = 0; i < n; i++){
		*(matA + i) = *(matB + i) = (int*)malloc(n * sizeof(int));
	}

	// (3) Call printArray to print out the 2 arrays here.
	
	printArray(matA, n);
	printArray(matB, n);
	
	//(5) Call matMult to multiply the 2 arrays here.
	
	matC = matMult(matA, matB, n);
	
	//(6) Call printArray to print out resulting array here.

	printArray(matC, n);

    return 0;
}