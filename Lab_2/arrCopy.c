#include<stdio.h>
#include<string.h>

void printArr(int *a, int size){
	//Your code here

    printf("printArr: ");
    for(int j = 0; j < size; j = j + 1){
        printf("%d ", *(a+j));
    }
    printf("\n");

}

int* arrCopy(int *a, int size){
	//Your code here
    int temparr[size];
    for(int i = 0; i < size; i = i + 1){
        // int* tempptr = temparr + i;
        // *tempptr = *(a + i);
        *(temparr+i) = *(a + i);
    }
    int *arrptr = temparr;
    return arrptr;
}

int main(){

    //TEST CODE ------------
    /*
    int test[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    int* testptr = test;
    printArr(testptr, 10);
    */
    //END TEST CODE --------
    int n;
    int *arr;
    int *arr_copy;
    int i;
    printf("Enter size of array:\n");
    scanf("%d",&n);

    //Dynamically create an int array of n items
    //Your code here
    int tempArr[n];
    arr = tempArr;
    

    //Ask user to input content of array
	//Your code here
    for(int j = 0; j < n; j = j + 1){
        printf("Enter array content #%d: ", j+1);
        scanf("%d", arr+j);
    }
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	//Print original array
    printArr(arr, n);


	//Copy array
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n);

    return 0;
}