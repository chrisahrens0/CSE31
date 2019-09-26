#include <stdio.h>

int main() {
	int i;
	int four_ints[4];
	char* four_c;

	for(i=0; i<4; i++)
        four_ints[i] = 2;

	printf("%x\n", four_ints[0]);
	
    four_c = (char*)four_ints;

	for(i=0; i<4; i++)
        four_c[i] = 'A'; // ASCII value of 'A' is 65 or 0x41 in Hex.
    
    // Add your code for the exercises here:
	
	printf("%x\n", four_ints[0]);
	printf("%x\n", four_ints[1]);

	printf("four_ints\n");
	for(i = 0; i < 4; i++){
		printf("%x\n", four_ints[i]);
	}
	printf("four_c\n");
	for(i = 0; i < 4; i++){
		printf("%x\n", four_c[i]);
	}

	printf("four_ints in dec: ");
	for(i = 0; i < 4; i++){
		printf("%d, ", four_ints[i]);
	}
	printf("\n");
	printf("four_ints in hex: ");
	for(i = 0; i < 4; i++){
		printf("%x, ", four_ints[i]);
	}
	printf("\n");
	
	
	return 0;

}