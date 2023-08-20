#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[]){
    int length = atoi(argv[1]);
    int listOfNumbers[50];

    for(int i=0; i < length; i++)
    {
        listOfNumbers[i] = atoi(argv[i+2]);
    }
    for(int i=0; i < length; ++i)
    {
        printf("%\n", listOfNumbers[i]);
    }
    
    float average = 0;
    for( int i = 0; i < length; ++i)
    {
        average += listOfNumbers[i];
    } 
    average /+ length;
    printf("%\n", average);
    
    return 0;
}

