#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;


struct Node{
    int data;
    Node *next;
};

Node* getNode(char*argv[],int length);
Node* push(Node *first, int value);
Node* pop(Node* first);
void printing(Node *first);

int main(int argc,char*argv[]){
    int length = atoi(argv[1]);
    Node* first = NULL;
    first = getNode(argv,length);
    printing(first);
    int value1 = atoi(argv[length + 2]);
    int value2 = atoi(argv[length + 3]);
    pop(first);
    pop(first);
    push(first,value1);
    push(first,9);
    printing(first);
    return 0;

}

Node* getNode(char*argv[],int length){
    Node* first = NULL;
    Node* current = NULL;
    first = (Node*)calloc(1,sizeof(Node));
    current = first;
    for(int i=0; i<length; ++i){
        current->data = atoi(argv[i+2]);
        if(i+1 == length){
            current->next = NULL;
        }
        else{
            current->next = (Node*)calloc(1,sizeof(Node));
            current = current->next;
        }
    }
    return first;
}

void printing(Node *first){
    Node *current = NULL;
    current = first;
    while(current->next != NULL){
        printf("%d\n",current->data);
        current = current->next;
    }
}

Node* pop(Node* first)
{
    Node* p = NULL;
    Node* prev = NULL;
    for(p = first; p != NULL; p = p->next)
    {
        if(p->next == NULL)
        {
            free(p);
            p = NULL;
            prev->next = NULL;
            break;
        } else {
            prev = p;
        }
    }
    return first;
}

Node* push(Node* first, int addedValue)
{
    Node* p = NULL;
    for(p = first; p != NULL; p = p->next)
    {
        if(p->next == NULL)
        {
            p->next = (Node*)calloc(1, sizeof(Node));
            p = p->next;
            p->data = addedValue;
            p->next = NULL;
            break;
        }
    }

    return first;
}