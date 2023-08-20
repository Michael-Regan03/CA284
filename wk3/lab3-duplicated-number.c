#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[]){
    char list[100];
    for(int i=0; argc-1>i; ++i)
    {
        list[i] = atoi(argv[i+1]);
    }
    int x=0;
    for(int i=0; argc-1>i; ++i)
    {
        for(int j=i; argc-2>j ; ++j)
        {
            /*printf("%d %d\n", list[i], list[j+1]);*/
            if(list[i] == list[j+1])
            {
                printf("%d\n", list[i]);
                ++x;
                return 0;
            }
        }
    }
    if(x<=0){
        printf("no duplicated number\n");
    }
    return 0;
}