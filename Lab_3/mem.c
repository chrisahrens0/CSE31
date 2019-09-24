
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

 int main() {
	int num;
	int *ptr;
	int **handle;

	num = 14;
	ptr = (int *)malloc(2 * sizeof(int));
	*ptr = num;
	handle = (int **)malloc(1 * sizeof(int *));
	*handle = ptr;

	// Insert extra code here

	printf("num value: %d\n", num);
	printf("num data location: %p\n", &num);

	printf("ptr data location: %p\n", &ptr);
	printf("ptr pointed data location: %p\n", ptr);
	printf("ptr pointed data value: %d\n", *ptr);

	printf("handle data location: %p\n", &handle);
	printf("handle pointed data location: %p\n", handle);
	printf("handle pointed data value: %p", *handle);

	return 0;
} 

