#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[]){
    int x = atoi(argv[1]); //assigning the first argument as x
    int triangular_number = 0;
    for(int i=0; x>triangular_number; ++i){
        triangular_number = triangular_number + i;
    }
    if(x-triangular_number==0){
        printf("%d is a triangular number\n", x);  //printing x is a triangular number
    }
    else{
        printf("%d is not a triangular number\n", x); //printing x is not a triangular number
    }
    return 0;
}