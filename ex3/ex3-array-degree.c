//This program reads arguments off the command line and appends them to a linked list.
//Then we iterate through the list and record the amount of times each element appears with a nested loop
//finally we print highest number rof appearances

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct Node Node;

struct Node{        //creating a struct for a linked list nodes
    int value;
    Node *next;
};

Node* getNode(int length, char*argv[]);
int findDegree(Node *first);

int main(int argc, char* argv[]) {
    Node* first;
    int length = argc-1;
    first = getNode(length,argv);
    int degree = findDegree(first);
    
    printf("%d\n", degree); //printing
    return 0;
}

Node* getNode(int length, char*argv[])
{
    Node* first,*current = NULL; //declaring the first, current and previous nodes all as none

    first = (Node*)calloc(1, sizeof(Node)); //using dynamic memory to hold the first node
    current = first;

    for(int i = 0; i < length; ++i) //looping through arguments on the command line
    {
            if(i == length - 1){ //test to see if we've reached the last argument
                current->value = atoi(argv[i+1]); //adding value to node
                current->next = NULL; //setting next to NULL
            }else{
                current->value = atoi(argv[i+1]); //setting the value
                current->next = (Node*)calloc(1, sizeof(Node)); //using dynamic memory to create the next node
                current = current->next;//iterating to the next node
           }
    }
    return first; //returning first
}

int findDegree(Node *first)
{
    Node* p, *q = NULL;
    int degree = 0;  //setting degree to 0
    for(p = first; p != NULL; p = p->next) //iterating through the list
    {
        int value = p->value;
        int tally = 0; //stating a tally
        for(q = p; q != NULL; q = q->next){ //iterating through the nodes after the target node
            if(q->value == value){
                ++tally; //every time the element appears in the list ++tally
            }
        }
        if(degree<tally){ 
            degree = tally; //replacing current highest number
        }   
    }
    return degree; //returning first
}