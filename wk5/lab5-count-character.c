#include<stdio.h>

int main(int argc, char * argv[])
{
    char *pointer1 = argv[1];
    char *pointer2 = argv[2];
    int x = 0;
    for(int i = 0; i < sizeof(argv[2])/sizeof(*(pointer2+1)); ++i){
        if (*(pointer1)==*(pointer2+i)){
            ++x;
        }
    }
    printf("%d\n",x);
}