#include <stdio.h>
#include <stdlib.h>

/*
    Read a set of values from the user.
    Store the sum in the sum variable and return the number of values read.
*/
int read_values(double* sum) {
  int values=0,input=0;
  (*sum) = 0;
  printf("Enter input values (enter 0 to finish):\n");
  scanf("%d",&input);
  while(input != 0) {
    values++;
    (*sum) += input;
    scanf("%d", &input);
  }
  return values;
}

int main() {
  double* sum;
	sum = (double *)malloc(1 * sizeof(double));
  int values;
  values = read_values(sum);
  
  //printf("sum val: %f\n", *sum);

  printf("Average: %g\n", *sum/values);
  return 0;
}

