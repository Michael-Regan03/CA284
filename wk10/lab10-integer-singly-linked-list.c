#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedList LinkedList;

struct LinkedList 
{
    int data;
    LinkedList *next;
};

int main(int argc, char *argv[])
{
    LinkedList *current, *next;
    current = ( LinkedList *)calloc(1, sizeof( LinkedList));
    for(int i =0; i < atoi(argv[1]); ++i){
        next = ( LinkedList *)calloc(1, sizeof( LinkedList));
        current->data = atoi(argv[2+i]);
        current->next = next;
        printf("%d\n",current->data );
    }



}