#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int even_hailstone(int n) //for when n is even
{
    int output;
    output = n/2; //dividing by two
    return output; //returning output
}

int odd_hailstone(int n) //for when n is odd
{
    int output;
    output = (3*n-1); //multiplying by 3 and adding 1
    return output; //returning output
}

int main(int argc, char*argv[]){
    char num[50];
    int n = atoi(argv[1]);
    int x = 0;
    while(n > 1) // looping until n is = 1
    {
        if(n % 2 == 0) //testing to see if n is even or odd
        {
            n = even_hailstone(n); //if n is even we use this function
            num[x] = n;
            ++x;
        }
        else
        {
            n = odd_hailstone(n); //if n is odd we use this function
            num[x] = n;
            ++x; 
        }
    }
    for(int i=0; x>i; ++i){
        printf("%d", num[i]);
    }
    printf("\n");
}
