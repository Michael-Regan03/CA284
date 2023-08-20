#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[]){
    int x = 0;
    for(int i=0; argc>i; ++i ){
        int y = atoi(argv[i]);
        if(y>x){
            x=y;
        }
    }
    printf("%d\n", x);
}
