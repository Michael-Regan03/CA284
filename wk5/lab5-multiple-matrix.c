#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void multiplying_matrices(int matrix1[100][100], int n1, int m1, int matrix2[100][100], int n2, int m2, int outputmatrix[100][100]);
void printMatrix(int matrix[100][100], int m, int n);

int main(int argc, char* argv[]) {
    int n1 = atoi(argv[1]);
    int m1 = atoi(argv[2]);
    int matrix1[100][100] = {0};
    int (*pointer1)[100] = matrix1;
    
    int start = n1*m1;
    int n2 = atoi(argv[start+3]);
    int m2 = atoi(argv[start+4]);
    int matrix2[100][100] = {0};
    int (*pointer2)[100] = matrix2;
    int outputmatrix[100][100] = {0};
    int k = 0;
	for(int i = 0; i < m1; ++i)
	{
		for(int j = 0; j < n1; ++j)
		{
			*(*(matrix1 + i) + j) = atoi(argv[3 + k++]); //3 refers to the first 3 arguments (function name, rows of matrix1, column of matrix1) which are not included in the list of elements, k++ means that every time the statement is executed, k is increased by 1 to move to the next argument.
		}

	}
	k = 0;
	for(int i = 0; i < m2; ++i)
	{
		for(int j = 0; j < n2; ++j)
		{
			*(*(matrix2 + i) + j) = atoi(argv[3 + m1*n1 + 2 + k++]); //3 is like above, m1*n1 refers to all elements of matrix1, 2 refers to the two dimentions of matrix 2
		}
	}
    multiplying_matrices(matrix1,n1,m1,matrix2,n2,m2, outputmatrix);
    printMatrix(outputmatrix, m1, n2);
}

void multiplying_matrices(int matrix1[100][100], int n1, int m1, int matrix2[100][100], int n2, int m2, int outputmatrix[100][100])
{
    for(int i=0; i<m2; ++i)
    {
        for(int j=0; j<n1; ++j)
        {
            for(int k=0; k<m2; ++k)
            {
             *(*(outputmatrix + i) + j) += *(*(matrix1 + i) + k) * *(*(matrix2 + k) + j);   
            }
        }
    }
}             

void printMatrix(int matrix[100][100], int m, int n)
{
    for(int i=0; i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(j==0)
            {
                printf("%d",*(*(matrix + i)+j));
            }
            else
            {
                printf(" %d", *(*(matrix+i)+j));
            }
        }
        printf("\n");
    }
}