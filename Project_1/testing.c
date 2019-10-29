#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char* string = "The quick brown fox jumped over the lazy dog";
    printf("%s", (char*)strstr(string, "brown"));
    return 0;
}