#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[]){
    char float_num[200]; //creating a list of float numbers
    for(int i=0; argc-2>i; ++i) 
    {
        float_num[i] = atof(argv[i+2]); // iterating through arguments to create a list
    }
    float largest = 0.0;
    float smallest = 0.0;
    for(int i=0; argc-2>i; ++i) // looping through every element in the list of floats
    {
        if(float_num[i]>largest)  // finding the biggest number in the list
        {
            largest = float_num[i]; //replacing the largest number
        }
        else if(float_num[i]<smallest) //finding the smallest number in the list
        {
            smallest = float_num[i]; //replacing the smallest number 
        }
    }
    if(strcmp(argv[1],"largest") == 0) //comparing to see if we are finding largest
    {
        printf("%.2f\n",largest); // printing largest
    }
    else if(strcmp(argv[1],"smallest") == 0) //comparing to see if we are finding smallest
    {
        printf("%.2f\n",smallest); //printing smallest
    }
    return 0; 
}