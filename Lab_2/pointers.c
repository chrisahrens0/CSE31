#include <stdio.h>

int main(){
    int x, y, *px, *py;
    int arr[10];

    x = 0, y = 0;

    for(int i = 0; i <= 9; i = i+1){
        arr[i] = i * 10;
    }
    
    px = &x;
    py = &y;

    printf("x = %d, y = %d \n", x, y);
    printf("arr[0] = %d \n", arr[0]);

    printf("px = %p, py = %p \n", (void*)px, (void*)py);
    printf("&x = %p, &y = %p \n", (void*)&x, (void*)&y);

    for(int i = 0; i <= 9; i++){
        printf("arr + %d = %d \n", i, arr[i]);
    }

    printf("arr     = %p \n", (void*)arr);
    printf("&arr[0] = %p \n", (void*)&arr[0]);

    return 0;
}