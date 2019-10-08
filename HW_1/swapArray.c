#include <stdio.h>
#include <stdlib.h>

// void swapArray(int* a1, int* a2){
//     int* b1 = a1;
//     int* b2 = a2;

//     a1 = b2;
//     a2 = b1;
// }

void swapArray(int* a1, int* a2, int size){
    int* temp = (int*)malloc(sizeof(int)*size);

    for(int i = 0; i < size; i++){
        *(temp+i) = *(a2+i);
        *(a2+i) = *(a1+i);
        *(a1+i) = *(temp+i);
        printf("a1[%d]   = %d\n", i, *(a1+i));
        printf("a2[%d]   = %d\n", i, *(a2+i));
        //printf("temp[%d] = %d\n", i, *(temp+i));
    }
}

int main(){
    int array1[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array2[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int* arr1 = array1;
    int* arr2 = array2;

    // int* arr1 = (int*)malloc(sizeof(int)*10);
    // int* arr2 = (int*)malloc(sizeof(int)*10);

    // arr1 = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // arr2 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    swapArray(arr1, arr2, 10);

    for(int i = 0; i < sizeof(arr1)+2; i++){
        printf("%d", arr1[i]);
    }
    printf("\n");
    for(int i = 0; i < sizeof(arr2)+2; i++){
        printf("%d", arr2[i]);
    }
}