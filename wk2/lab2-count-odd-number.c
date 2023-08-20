#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{   int my_array[100] = {};
    int sum=0;
    for(int j=0; j<argc; ++j){
        my_array[j] = argv[j];
    }
    for(int x=1; x < sizeof(my_array); ++x);
    { 
        if(my_array[x] % 2 != 0){
            sum += 1;
            }
    }
    printf("%d", sum);
    return 0;
}