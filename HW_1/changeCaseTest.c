#include <stdio.h>
#include <stdlib.h>

char* changeCase(char* str){
    char* p;
    char* result;
    result = (char*)malloc(sizeof(char)*sizeof(str));
    for(int i = 0; i < sizeof(str); i++){
        *(result+i) = str[i];
    }

    for(int i = 0; i < sizeof(str); i++){
        char temp = *(result+i);
        if(temp >= 97 && temp <= 122){
            *(result+i) = temp - 32;
        } else if (temp >= 65 && temp <= 90){
            *(result+i) = temp + 32;
        }
    }

    return result;
}

int main(){
    char yeeeeet[7] = {'Y', 'e', 'e', 't', 'D', 'a', 'b'};
    char* dab = changeCase(yeeeeet);

    for(int i = 0; i < sizeof(yeeeeet); i++){
        printf("%c", dab[i]);
    }

    return 0;
}