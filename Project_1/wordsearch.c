#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
void searchPuzzle(char** arr, int n, char** list, int listSize);
void dirSearch(char** arr, int n, char* word);
int search(char** arr, int r, int c, int n, char* word);
char toUpper(char c);
char toLower(char c);
void modifyArray(int r, int c, int dir, char** arr, int length);

// Main function, DO NOT MODIFY!!!	
int main(int argc, char **argv) {
    int bSize = 15;
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    char **block = (char**)malloc(bSize * sizeof(char*));
	char **words = (char**)malloc(50 * sizeof(char*));

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

	// Read puzzle block into 2D arrays
    for(i=0; i<bSize; i++){
        *(block+i) = (char*)malloc(bSize * sizeof(char));

        fscanf(fptr, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(block+i), *(block+i)+1, *(block+i)+2, *(block+i)+3, *(block+i)+4, *(block+i)+5, *(block+i)+6, *(block+i)+7, *(block+i)+8, *(block+i)+9, *(block+i)+10, *(block+i)+11, *(block+i)+12, *(block+i)+13, *(block+i)+14 );
    }
	fclose(fptr);

	// Open file for reading word list
	fptr = fopen("states.txt", "r");
	if (fptr == NULL) {
        printf("Cannot Open Words File!\n");
        return 0;
    }
	
	// Save words into arrays
	for(i=0; i<50; i++){
		*(words+i) = (char*)malloc(20 * sizeof(char));
		fgets(*(words+i), 20, fptr);		
	}
	
	// Remove newline characters from each word (except for the last word)
	for(i=0; i<49; i++){
		*(*(words+i) + strlen(*(words+i))-2) = '\0';	
	}
	
	// Print out word list
	printf("Printing list of words:\n");
	for(i=0; i<50; i++){
		printf("%s\n", *(words + i));		
	}
	printf("\n");
	
	// Print out original puzzle grid
    printf("Printing puzzle before search:\n");
    printPuzzle(block, bSize);
	printf("\n");

	// Call searchPuzzle to find all words in the puzzle
	searchPuzzle(block, bSize, words, 50);
	printf("\n");
	
	// Print out final puzzle grid with found words in lower case
    printf("Printing puzzle after search:\n");
    printPuzzle(block, bSize);
	printf("\n");
	
    return 0;
}

void printPuzzle(char** arr, int n){
	// This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
	// Your implementation here

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%c ", *(*(arr+i)+j));
		}
		printf("\n");
	}

}

void searchPuzzle(char** arr, int n, char** list, int listSize){
	// This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
	// Your implementation here
	

	//Horizontal Search
	for(int i = 0; i < listSize; i++){
		char* word = (char*)malloc(sizeof(char)*sizeof(*(list+i)));
		for(int j = 0; j < strlen(*(list+i)); j++){
			*(word+j) = *(*(list+i)+j);
			// if(*(capsword+j) >= 'a' && *(capsword+j) <= 'z'){
			// 	*(capsword+j) = *(capsword+j) - 32;
			// }
			//// previously used to make all caps, is now done later.
		}
		dirSearch(arr, n, word);
		//printf("Searching word: %s\n", *(list+i));
	}


}

void dirSearch(char** arr, int n, char* word){
	for (int row = 0; row < n; row++){
		for(int col = 0; col < n; col++){
			//printf("%s\n", word);
			if(search(arr, row, col, n, word) == 1){
				//printf("(%d, %d): %s\n", row, col, word);
				printf("Found word: %s\n", word);
			}
		}
	}

}

int search(char** arr, int r, int c, int n, char* word){

	int* x = (int*)malloc(sizeof(int)*5);
	*(x+0) = 0, *(x+1) = 1, *(x+2) = -1, *(x+3) = 1, *(x+4) = -1;
	int* y = (int*)malloc(sizeof(int)*5);
	*(y+0) = 1, *(y+1) = 0, *(y+2) = 0, *(y+3) = 1, *(y+4) = 1;

	/*
	0: horizontal left to right
	1: vertical up to down
	2: vertical down to up
	3: horiztontal top left to bottom right
	4: horizontal bottom left to top right
	*/

	//printf("Searching for %s...\n", word);

	if( toUpper(*(*(arr+r)+c)) != toUpper(*(word+0)) ){
		return 0;
	}



	int length = strlen(word);

	//printf("length = %d\n", length);
	//printf("word = %s\n", word);

	for(int dir = 0; dir < 5; dir++){
		int k;
		int rd = r + *(x+dir);
		int cd = c + *(y+dir);
		for(k = 1; k < length; k++){
			if(rd >= n || rd < 0 || cd >= n || cd < 0){
				//printf("got here 1\n");
				break;
			}
			if( toUpper(*(*(arr+rd)+cd)) != toUpper(*(word+k)) ){
				//printf("got here 2\n");
				break;
			}
			rd += *(x+dir);
			cd += *(y+dir);
		}
		if(k == length){
			modifyArray(r, c, dir, arr, length);
			return 1;
		}
	}
	return 0;
}

char toUpper(char c){
	if(c >= 'a' && c <= 'z'){
		return c - 32;
	}
}

char toLower(char c){
	if(c >= 'A' && c <= 'Z'){
		return c + 32;
	}
}

void modifyArray(int r, int c, int dir, char** arr, int length){

	/*
	0: horizontal left to right
	1: vertical top to bottom
	2: vertical bottom to top
	3: horiztontal top left to bottom right
	4: horizontal bottom left to top right
	*/

	int* x = (int*)malloc(sizeof(int)*5);
	*(x+0) = 0, *(x+1) = 1, *(x+2) = -1, *(x+3) = 1, *(x+4) = -1;
	int* y = (int*)malloc(sizeof(int)*5);
	*(y+0) = 1, *(y+1) = 0, *(y+2) = 0, *(y+3) = 1, *(y+4) = 1;

	for(int i = 0; i < length; i++){
		*(*(arr+r+(i * *(x+dir)))+c + (i * *(y+dir))) = toLower( *(*(arr+r+(i * *(x+dir)))+c + (i * *(y+dir))) );
	}
}