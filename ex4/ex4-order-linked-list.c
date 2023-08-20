//Michael Regan
//Student ID - 22112111
//This program takes in integers from the command line and appends them to a linked list
//It them iterates through those items to determine if the list is in descending order
//If it is in descending order it prints 1 else it prints 0
//13/12/22

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;


struct Node{ //creating a struct for the doubly linked list nodes
    int value;
    Node *next; //the next node
    Node *prev; //the previous node
};

Node* getNode(int length, char*argv[]);
int descending(Node* first);

int main(int argc, char*argv[])
{
    int length = argc -1;
    Node* first = NULL; //declaring the first node on the list as none.
    first = getNode(length, argv);
    int x = descending(first);
    printf("%d\n" ,x);
    return 0;
}

Node* getNode(int length, char*argv[])
{
    Node* first,*current, *prev = NULL; //declaring the first, current and previous nodes all as none

    first = (Node*)calloc(1, sizeof(Node)); //using dynamic memory to hold the first node
    current = first;

    for(int i = 0; i < length; ++i) //looping through arguments on the command line
    {
            if(i == length - 1){ //test to see if we've reached the last argument
                current->value = atoi(argv[i+1]); //adding value to node
                current->next = NULL; //setting next value to node
                current->prev = prev;
            }
            else if (i == 0){  //if its the first argument of the list
                current->value = atoi(argv[i+1]); //setting the value
                current->prev = NULL; //previous node is set to NONE as this is the first node
                current->next = (Node*)calloc(1, sizeof(Node)); //Next node is allocated space
                prev = current; //Setting prev to current so for the next argument we can say its previous is this current node
                current = current->next; //iterating to the next node
            }else{
                current->value = atoi(argv[i+1]); //setting the value
                current->next = (Node*)calloc(1, sizeof(Node)); //using dynamic memory to create the next node
                current->prev = prev; //setting prev to previous node
                prev = current;//Setting prev to current so for the next argument we can say its previous is this current node
                current = current->next;//iterating to the next node
           }
    }
    return first; //returning first
}

int descending(Node* first){
    Node* current = NULL;
    for(current = first; current != NULL; current = current->next) //iterating through all nodes
    {
        if(current->next != NULL){ //if its not the last node in the list
            if(current->value < current->next->value){ //if the next nodes value is larger then the current node, ie it is not in descending order
                return 0; //return 0
            }
        }
    }
    return 1; //returning 0
    
}