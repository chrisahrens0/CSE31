#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char toUpper(char c){
    if(c >= 'a' && c <= 'z') return c - 32;
}



int main(){
    char* string = "The quick brown fox jumped over the lazy dog";
    printf("%s\n", (char*)strstr(string, "brown"));
    printf("toUpper(c) = %c\n", toUpper('c'));
    return 0;
}