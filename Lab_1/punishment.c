#include <stdio.h>
#include <stdlib.h>
int main(){
    int lines, typo;
    printf("Enter the number of lines for punishment: ");
    scanf("%d", &lines);
    if(lines < 0){
        printf("You entered an incorrect value for the number of lines!");
        exit(1);
    }
    printf("Enter the line for which we want to make a typo: ");
    scanf("%d", &typo);
    if(typo < 0 || typo > lines){
        printf("You entered an inccorect value for the line typo!");
        exit(1);
    }

    char cor[] = "C programming language is the best! ";
    char inc[] = "C programming language is the bet! ";

    int i;

    for(i = 0; i < typo; i = i + 1){
        printf("%s", cor);
    }
    printf("%s", inc);
    for(i = typo; i < lines; i = i + 1){
        printf("%s", cor);
    }

    return 0;
}