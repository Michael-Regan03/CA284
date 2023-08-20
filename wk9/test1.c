#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
    /* We need 10 integer numbers at the beginning */

    int capacity = 10;
    int *pNumber = calloc(capacity, sizeof(int));
    for(int i = 0; i < 10; ++i)
    {
        *(pNumber + i) = i;
        printf("%d",i);
    }
     printf("\n");
    /* Now we need to add more 5 numbers to the current working list */
    int *pTemp = NULL;
    capacity += 5;
    pTemp = realloc(pNumber, capacity*sizeof(int));
    if(!pTemp)
    {
        printf("Unfortunately memory reallocation failed.\n");
        free(pNumber);
        pNumber = NULL;
        return 0;
    }

    pNumber = pTemp;
    for(int i = 0; i < 15; ++i)
    {
        *(pNumber + i) = i;
        printf("%d",i);
    }
    }