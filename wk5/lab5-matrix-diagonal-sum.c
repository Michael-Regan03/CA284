#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumDiag(int (*pointer1)[100], int n);

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);

    int matrix[100][100];
    int (*pointer1)[100] = matrix;

    for(int i=0; i<n; ++i){
        for(int j=0;j<n;++j){
            *(*(pointer1+i)+j) = atoi(argv[(i*n)+2+j]) ;
        }
    }

    printf("%d\n", sumDiag(pointer1, n));
	return 0;
}

int sumDiag(int (*pointer1)[100], int n){
    int sum = 0;
    int* psum = &sum;

    for(int i=0; i<n; ++i){
        *psum += *(*(pointer1+i)+i);
    }
    return *psum;
}
