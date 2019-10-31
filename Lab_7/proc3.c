#include<stdio.h>

int sub(int a, int b){
    printf("%d-%d\n", b, a);
    return b - a;
}

int sum(int m, int n){
    int p = sub(n+1, m+1);
    int q = sub(m-1, n-1);
    printf("p=%d, q=%d\n", p, q);
    return p + q;
}

int main(){
    int x=5, y=10;
    y = y + x + sum(x, y);
    printf("%d\n", y);
    return 0;
}
