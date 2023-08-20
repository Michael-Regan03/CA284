#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int antiDiagonal(int (*pArr)[100], int n);

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]); //finding the width of the matrix

	int a[100][100]; //initialising matrix
	int (*pArr)[100] = a; //initialising the pointer for the start of every sublist within the matrix

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			*(*(pArr+i)+j) = atoi(argv[i*n+j+2]); //calculating the contents of the matrix from the command line

	printf("%d\n", antiDiagonal(pArr, n)); //printing result
	return 0;
}

int antiDiagonal(int (*pArr)[100], int n){
	int sum = 0;
	int* pSum = &sum; 

	for (int i=0; i<n; i++)
        *pSum += *(*(pArr+i)+n-1-i); //calculating the reverse diagonal

	return *pSum;
}