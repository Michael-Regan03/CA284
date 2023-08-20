//This program takes integers from the command line and prints back the elements that appear more then 3 time.
//I used dynamic memory allocation setting the length of the initial array to 5 and for every argument after that i extended the length by 1.
//then i looped through that array with every element in the array to count how many times each element appears. 
// I used a nested loop to make sure i was not counting the same element twice.
//The elements that appeared more then 3 times got appended to a new array that also used dynamic memory allocation and for the new elements the arrays length was extened to match.
//The elements were then printed.

#include<string.h>
#include<stdlib.h>
#include<stdio.h>


void append(int* array, char*argv[], int length, int arrayLength);
void checkFrequency(int*array,int length);
void printing(int*frequentElements, int frequentLength);

int main(int argc, char* argv[]) {
    int commandLineLength = argc -1; //finding the length of arguments in the command line
    int arrayLength = 5; //setting inital length of the array to 5
    int* array;
    array = (int *)malloc(arrayLength * sizeof(int));  //using dynamic memory allocation to set the length of the array to 5
    append(array,argv,commandLineLength,arrayLength);
    int* frequentElements;
    checkFrequency(array,commandLineLength); 
    return 0;
}

void append(int* array, char*argv[], int length, int arrayLength){
    for(int i=0; i < length; ++i){      //looping through every argument in the command line
        if(i==arrayLength){     //testing to see if the number of arguments exceeds the length we set for our array
            ++arrayLength;
            int *pTemp = (int *)realloc(array,arrayLength * sizeof(int));    //extending the length of our array by 1 for every argument after the 5th argument 
            if(!pTemp){     //if our reallocation fails
                printf("Error\n");
                free( array );
                array = NULL;
            }
            array = pTemp;  //setting our array to its new length
            }
        *(array + i) = atoi(argv[i+1]);     //appending value to the array
    }
}

void checkFrequency(int*array,int length){
    int frequentLength = 0;     //setting the length of our new array that contains numbers that appear at least 3 times
    int* frequentElements;      //initialising our new array
    frequentElements = (int *)malloc(1 * sizeof(int));  //using dynamic memory allocation to begin our new array
    for(int i=0; i < length; ++i){      //looping through every element in our previous array
        int element = *(array + i);       //for each element we will count how many times it appear
        int frequency = 1;       //the element count
        int flag = 0;       //flag to test if were counting the same element more then once
        for(int j=i+1; j < length; ++j)     //looping through elements in our previous array
        {
            if(*(array+j) == element)       //testing to see if an element appears twice
            {
                if(frequentLength > 0)
                {
                    for(int x = 0; x < frequentLength; ++x)     //testing to see if we've already counted that element
                    {
                        if(element == *(frequentElements+x))
                        {
                            ++flag;
                            break;
                        }
                    }
                }
                if(flag == 0)
                {
                    ++frequency;    //counting elements duplicate elements
                }
            }
            printf("%d",frequency);
        }
        if(frequency>3) //if the element has a frequency above 3
        {
                int *pTemp = (int *)realloc(frequentElements,(frequentLength+frequency) * sizeof(int)); //reallocating memory for the elements we discovered with a frequency of 3 or more
                if(!pTemp){
                    printf("Error");
                    free( array );
                    array = NULL;
                }
                frequentElements = pTemp;
                for(int i = frequentLength; i < (frequentLength+frequency) ; ++i) //looping through as many times as that element appears
                {
                    *(frequentElements + i) = element; //appending to our frequentElements array
                }
                frequentLength += frequency;
        }
    }
    printing(frequentElements,frequentLength);
}

void printing(int*frequentElements, int frequentLength){
    for(int i=0; i < frequentLength; ++i ){
        printf("%d\n", *(frequentElements + i)); //printing
    }
}
