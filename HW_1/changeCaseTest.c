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

void changeCase_by_ref( char** n){
    *n = changeCase(*n);
}

void changeCase_name(char* names[], int i) {
    changeCase_by_ref( &(names[i]) );
}



int main(){
    char yeeeeet[7] = {'Y', 'e', 'e', 't', 'D', 'a', 'b'};
    char* dab = changeCase(yeeeeet);

    for(int i = 0; i < sizeof(yeeeeet); i++){
        printf("%c", dab[i]);
    }
    printf("\n");

    char** names = (char**)malloc(sizeof(char*)*4);

    names[0] = "Joe Schmoe";
    names[1] = "John Doe";
    names[2] = "Jane Doe";
    names[3] = "Arnold Schwarzenegger";

    changeCase_name(names, 2);
    printf("%s\n", names[2]); 

    for(int i = 0; i <= sizeof(names[2]); i++){
        printf("%c", names[2][i]);
    }

    return 0;
}