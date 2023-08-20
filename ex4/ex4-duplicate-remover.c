//Michael Regan
//Student ID 22112111
//This program takes in integers from the command line and stores them in a doubly linked list.
//It then iterates through that list and identifies elements that appear more then once.
//Those elements are then removed entirely form the list.
//The list is then printed out, line by line.


#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;


struct Node{ //creating a struct for the doubly linked list nodes
    int value;
    Node *next; //the next node
    Node *prev;
};

Node* getNode(int length, char*argv[]);
int removeDuplicates(Node* first);
int removeNodes(Node* first, int num);
void printNode(Node *first);


int main(int argc, char*argv[])
{
    int length = argc -1;
    Node* first = NULL; //declaring the first node on the list as none.
    first = getNode(length, argv);
    int x = removeDuplicates(first);
    if(x == 0){
        printNode(first);
    }


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

int removeDuplicates(Node* first){
    int x = 0;
    Node *current1, *current2 = NULL;
    for(current1 = first; current1 != NULL; current1 = current1->next){
        int duplicate = current1->value;
        for(current2 = current1->next; current2 != NULL; current2 = current2->next){ //nested loop to check for duplicates
            if(duplicate == current2->value){  //if a double is found
                int x = removeNodes(first,duplicate);
            }
        }
    }
    return x;
}




int removeNodes(Node* first, int num){              //removing Nodes recursively
    Node* current = NULL; 
        current = first;
        if(first == NULL){ //the list no longer has any nodes
            return 1;
        }
        if(num == current->value){      //if our node has the value of the number were trying to remove
            if(current->prev == NULL){   //if this is the first node on the list
                current->next->prev = NULL;
                int x = removeNodes(current->next, num);
            }else if(current->next == NULL){  //if this is the last node on the list
                current->prev->next = NULL;
                return 0;
            }else{ 
                current->prev->next = current->next; //Previous node jumping over this one
                current->next->prev = current->prev; //next node jumping back over this one
                int x = removeNodes(current->prev, num);
                }
        }else if(current->next != NULL){
            int x = removeNodes(current->next, num);
        }else{
            return 0;
        }
}


void printNode(Node *first)
{
    Node* p = NULL;
    for(p = first; p != NULL; p = p->next) //iterating through all nodes
    {
        printf("%d\n", p->value); //printing nodes
    }
}