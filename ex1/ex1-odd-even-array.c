#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[]){
    char num[50]; //creating a list of numbers
    int flag = 0; //flag to see if first even number has been found
    int odd_numbers = 0;
    int even_numbers = 0;
    for(int i=0; argc-1>i; ++i) 
    {
        num[i] = atoi(argv[i+1]); // iterating through arguments to create a list
        if(num[i] % 2 == 0) //testin if number is even or odd
        {
            if(flag <= 0)   //testing for first even number
            {
                even_numbers = num[i];
                ++flag; //setting off flag
            }
            else
            {
                even_numbers -= num[i]; //subtracting even number
            }
        }
        else
        {
            odd_numbers += num[i]; //adding odd number
        }
    }
    printf("%d\n",odd_numbers); //printing odd numbers
    printf("%d\n",even_numbers); //printing even numbers
}