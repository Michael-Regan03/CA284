#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node{
    int value;
    Node *next;
};

Node* getNode(int length, char*argv[]);
void printNode(Node *first);
Node* pop(Node* first);
Node* push(Node* first, int addedValue);

int main(int argc, char*argv[])
{
    int length = atoi(argv[1]);
    int addedValue1 = atoi(argv[length + 2]);
    int addedValue2 = atoi(argv[length + 2 + 1]);
    Node* first = NULL;
    first = getNode(length, argv);
    pop(first);
    pop(first);
    push(first, addedValue1);
    push(first, addedValue2);
    printNode(first);

    return 0;
}

Node* getNode(int length, char*argv[])
{
    Node* first = NULL;
    Node* current = NULL;

    first = (Node*)calloc(1, sizeof(Node));
    current = first;

    for(int i = 0; i < length; ++i)
    {
        current->value = atoi(argv[i+2]);

        //Check if the last node
        if(i == length - 1){
            current->next = NULL;
        } else {
            current->next = (Node*)calloc(1, sizeof(Node));
            current = current->next;
        }
    }

    return first;
}

void printNode(Node *first)
{
    Node* p = NULL;
    for(p = first; p != NULL; p = p->next)
    {
        printf("%d\n", p->value);
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
            p->value = addedValue;
            p->next = NULL;
            break;
        }
    }

    return first;
}

Node* push(Node *first, int value){
    Node* current = NULL;
    for(current = first; current != NULL; current = current->next){
        if(current->next == NULL){
            current->next = (Node*)calloc(1,sizeof(Node));
            current->next->next = NULL;
            current->next->data = value;
            break;
        }
    }
    return first;
}

Node* pop(Node* first){
    Node* current = NULL;
    Node* prev = NULL;
    
    for(current = first; current!=NULL; current = current->next){
        if(current->next==NULL){
            free(current);
            current = NULL;
            prev->next = NULL;
            break;
        }
        else{
            prev = current;
        }
        return first;
    }
}