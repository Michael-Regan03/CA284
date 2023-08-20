//This program reads integers off the command line and appends them into a doubly linked list.
//It then iterates through the list and removes any even numbers.
//It then appends the sum of all the elements of the list onto end of the list
//Finally it prints all the elements of the doubly linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node{ //creating a struct for the doubly linked list nodes
    int value;
    Node *next; //the next node
    Node *prev; //the previous node
};

Node* getNode(int length, char*argv[]);
Node* deleteEven(Node* first);
Node* counting(Node*first);
void printNode(Node *last);

int main(int argc, char*argv[])
{
    int length = argc-1; //length of arguments on the command line
    Node* first = NULL; //declaring the first node on the list as none.
    first = getNode(length, argv);
    first = deleteEven(first);
    first = counting(first);
    printNode(first);

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

Node* deleteEven(Node* first)
{
    Node* p = NULL;
    for(p = first; p != NULL; p = p->next) //iterating through all nodes
    {
        if((p->value%2)==0){  //if the value of the node it even
            if(p->next == NULL) //if its the last node
            {
                p = p->prev; //going back a node
                p->next = NULL; //setting the next node to NULL
            } 
            if(p->prev == NULL){ //if its the first node
                p->next->prev = NULL; //setting the next nodes previous node to NULL
                first = p->next; //changing the first node in the list
            }
            else {
                p = p->prev; //going back to last odd number
                p->next = p->next->next; //skipping the node we were just on
                p->next->prev = p; //changing thats previous incase its even
            }
        }
    }
    return first; //returning first
}

Node* counting(Node*first){
    Node* p = NULL;
    int sum = 0;
    for(p = first; p->next != NULL; p = p->next) //iterating to the second last node
    {
        sum += p->value; //counting all the values
    }
    sum += p->value; //adding up the last node
    p->next = (Node*)calloc(1, sizeof(Node)); //creating another node for the sum
    p->next->next = NULL;
    p->next->value = sum; //setting the value of that node to the sum of all the previous nodes
    p->next->prev = p; 
    return first; 
}

void printNode(Node *first)
{
    Node* p = NULL;
    for(p = first; p != NULL; p = p->next) //iterating through all nodes
    {
        printf("%d\n", p->value); //printing nodes
    }
}