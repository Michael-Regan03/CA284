#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[]){
    int height, width;
    height = atoi(argv[1]);
    width = atoi(argv[2]);
    for(int i=0; i < height; ++i);
    {
        for(int j =0; j < width; ++j);
        {
            if((j == 0) || (j < width - 1)){
                printf("*");}
            else{ 
                printf(" ");}
        }
        printf("\n");
    }
}