#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int findMax(int*lengthOfString, int length);
void printingMax(int length, int max,  char* argv[]);

int main(int argc, char* argv[]) {
    int length = argc - 1;
    int *lengthOfStrings = calloc(length,sizeof(int));
    for(int i=0; i<length; ++i)
    {
        *(lengthOfStrings+i) = strlen(argv[1+i]);
    }
    int max = findMax(lengthOfStrings,length);
    //printf("%d",max);
    printingMax(length,max,argv);
    return 0;
}

int findMax(int*lengthOfString, int length){
    int max = *(lengthOfString);
    for(int i=0; i<length; ++i)
    {
        if(*(lengthOfString+i)>max)
        {
            max = *(lengthOfString+i);
        }
    }
    return max;
}

void printingMax(int length, int max,  char* argv[]){
    for(int i=1; i<length+1; ++i)
    {
        if(strlen(argv[i])==max){
            printf("%s\n", argv[i]);
        }
    }
}