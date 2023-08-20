#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char* argv[]) {

    int length = argc-1;
    float* array;
    array = (float *)malloc(length * sizeof(float));

    for(int i=0; i<length; ++i){
        *(array+i) = atof(argv[1+i]); //appending all argvs to lst
    }

    float largest_num = 0;

    for(int i=0; i<length; ++i){
        if(*(array+i)>largest_num){
            largest_num = *(array+i);
        }
    }

    float second_largest = 0;

    for(int i=0; i<length; ++i)
    {
        if(largest_num > *(array+i))
        {
            if( *(array+i)>second_largest)
            {    
                if(*(array+i)!=largest_num)
                {
                    second_largest = *(array+i);
                }
            }

        }
    }
    
    printf("%.1f\n", second_largest);


}
