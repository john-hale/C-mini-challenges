#include <stdio.h>
#include <stdlib.h>
// We need to include time to access the clock() function
//WHAT IS THE RESOLUTION OF clock()?
#include <time.h>

int main(int argc, char **argv) {
  int i,j;
  int n = 2048;
  double sum;
  clock_t start, end;
  double *arr = malloc(n*n*sizeof(double));
  
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      arr[i*n+j] = (double) rand()/RAND_MAX;
sum = 0;

//start clock
  start = clock();
for (i = 0; i<n; i++) // iterate over rows 
  for (j = 0; j<n; j++) // iterate over columns 
    sum += arr[i*n + j];
//end clock
  end = clock();

  printf("Row Major: sum = %lf and Clock Ticks are %ld\n",sum,end-start);
sum = 0;
//start clock
  start = clock();
for (i = 0; i<n; i++) // iterate over columns 
  for (j = 0; j<n; j++) // iterate over rows 
    sum += arr[j*n + i];
//end clock
  end = clock();

  printf("Column Major: sum = %lf and Clock Ticks are %ld\n",sum,end-start);
  return 0;
}

