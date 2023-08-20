#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int dotProduct(int *vector1, int *vector2, int length);

int main(int argc, char* argv[]) {


    int length = atoi(argv[1]);

    int* vector1;
    vector1 = (int *)malloc(length * sizeof(int));

    for(int i=0; i<length; ++i){
        *(vector1+i) = atoi(argv[2+i]); //appending all argvs to lst
    }
    
    
    int* vector2;
    vector2 = (int *)malloc(length * sizeof(int));

    for(int i=0; i<atoi(argv[1]); ++i){
        *(vector2+i) = atoi(argv[length+2+i]); //appending all argvs to lst
    }

    int sum = 0;
    sum += dotProduct(vector1,vector2,length);
    
    printf("%d\n", sum);

    free( vector1 );
    free( vector2 );

    return 0;


}


int dotProduct(int *vector1, int *vector2, int length){
    int sum = 0;
    for(int i=0; i<length; ++i){
        sum += *(vector1+i) * *(vector2+i);
    }
    return sum;
}