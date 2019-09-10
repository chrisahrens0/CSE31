#include <stdio.h>
#include <stdbool.h>
int main(){
    int nums[100];
    int size = 0;
    bool exit = false;
    while(!exit){
        int x;
        printf("Please enter an integer: ");
        scanf("%d", &x);
        if(x == 0){
            exit = true;
            break;
        } else {
        nums[size] = x;
        size = size + 1;
        }
    }

    int positives[100];
    int positiveSize = 0;
    int negatives[100];
    int negativeSize = 0;

    for(int i = 0; i < size; i = i + 1){
        if(nums[i] > 0){
            positives[positiveSize] = nums[i];
            positiveSize = positiveSize + 1;
        } else {
            negatives[negativeSize] = nums[i];
            negativeSize = negativeSize + 1;
        }
    }

    // Error Checking
    // printf("Positive Size: %d", positiveSize);
    // printf("Negative Size: %d", negativeSize);

    int posTotal = 0;
    // printf("%n", &posTotal);
    int negTotal = 0;
    // printf("%n", &negTotal);

    for(int i = 0; i < positiveSize; i = i + 1){
        posTotal = posTotal + positives[i];
    }
    for(int i = 0; i < negativeSize; i = i + 1){
        negTotal = negTotal + negatives[i];
    }


    // int posAvg = posTotal/positiveSize;
    // int negAvg = negTotal/negativeSize;

    if(positiveSize > 0){
        int posAvg = posTotal/positiveSize;
        printf("Positive average: %d \n", posAvg);
    }
    if(negativeSize > 0){
        int negAvg = negTotal/negativeSize;
        printf("Negative average: %d \n", negAvg);
    }
}