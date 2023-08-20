#include<string.h>
#include<stdlib.h>
#include<stdio.h>


int largestTwice(int*array, int length);
int largest_num(int *array,int length);


int main(int argc, char* argv[]) {

    int length = argc-1;
    int* array;
    array = (int *)malloc(length * sizeof(int));

    for(int i=0; i<length; ++i){
        *(array+i) = atoi(argv[1+i]);
    }

    int output;
    output = largestTwice(array, length);

    printf("%d\n", output);

    return 0;



}

int largestTwice(int*array, int length){
    int* doubles;
    doubles = (int *)malloc(length * sizeof(int));
    int x = 0;
    *(doubles) = 0;
    for(int i=0; i<length; ++i){
        for(int j=0; j<length; ++j){
                if((*(array+i)+*(array+i))==*(array+j)){
                    x += 1;
                    *(doubles+x) = *(array+j);
                }
        }
    }
    
    int output;
    output = largest_num(doubles, x);

    return output;
}

int largest_num(int *array,int length){
    
    int largest_num = *(array);

    for(int i=0; i<length; ++i){
        if(*(array+i)>largest_num){
            largest_num = *(array+i);
        }
    }

    return largest_num;
}