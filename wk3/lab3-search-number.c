#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[]){
    char list[100];
    for(int i=0; argc-2>i; ++i)
    {                                       // comment
        list[i] = atoi(argv[i+2]);
    }
    int j = 0;
    while(atoi(argv[1]) != list[j]){
        ++j;
    }
    printf("Found %d at %d\n", atoi(argv[1]), j);
}