#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void sort(int*pointer, int argc);
void swap_with_pointer(int *a, int *b);

int main(int argc, char *argv[])
{
	int lst[100]; //initialising lst
    int(*pointer) = lst; //pointer starting at arg[1]
	
    for(int i=0; i<argc-3; ++i){
        *(pointer+i) = atoi(argv[2+i]); //appending all argvs to lst
    
    }
    
    sort(pointer,argc); //sorting lst
    int length = ((argc-3)/2);
    
    for(int i=0;i<2;++i)
    {
        printf("%d\n", *(pointer+length+ i)); //returning 2 values in the middle
    }
	
    return 0;
}


void sort(int*pointer, int argc){
    for(int i=0;i<argc-1;++i)
    {
        for(int j=0;j<argc-1;++j)
        {
            if(*(pointer+i)<*(pointer+j)){ //if the next pointer is smaller
                swap_with_pointer((pointer+i),(pointer+j));
            }
        }
    
    }
}


void swap_with_pointer(int *a, int *b)
{
	int temp = *a;
	*a = *b; //wapping pointers
	*b = temp;
}
