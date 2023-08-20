#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[]){
    float x=atof(argv[2]);
    float y=atof(argv[3]);
    float sum = 0.0;
    if(strcmp(argv[1],"multiply") == 0)
    {
        sum=x*y;
        printf("%f\n",sum);
    }
    else if(strcmp(argv[1],"divide") == 0)
    {
        if(y == 0)
        {
            printf("invalid\n");
        }
        else if(x == 0)
        {
            printf("invalid\n");
        }
        else
        {
            sum=x/y;
            printf("%f\n",sum);
        }
    }
}
