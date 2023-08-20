//Michael Regan
//Student ID - 22112111
// This program finds the shortest or longest sentence in a paragraph.
//We do this by iterating through the paragraph and every time we see a . and an even number of ' before it we append that sentence to a linked list
//until we reach the end of the paragraph.
//Then we find which sentence is the longest or shortest and return it along with its length
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node Node;


struct Node{ //creating a struct for the doubly linked list nodes
    int length;
    char sentence[201];
    Node *next; //the next node
};

char* nextSentence(char* paragraph, char*sentence, int index);
Node*  getNode(char* argv[]);
void printNode(Node *first);
void longest(Node *first);
void shortest(Node *first);

int main(int argc, char*argv[])
{
    Node *first = NULL;
    first = getNode(argv); //creating linked list
    if(strcmp(argv[2], "longest")==0){    //if were finding longest
        longest(first);
    }else if(strcmp(argv[2], "shortest")==0){ //if were finding shortest
        shortest(first);
    }else{
        printf("Not valid!"); //error handling
    }
    return 0; //return 0 

}


Node*  getNode(char* argv[]){
    Node*first, *current = NULL;
    first = (Node*)calloc(1, sizeof(Node)); //our first node
    current = first; //setting the current node to first
    int length = 0; //declaring length
    int paragraphLength = strlen(argv[1]);
    char paragraph[1000]; //declaring paragraph
    strcpy(paragraph, argv[1]); //copying paragraph
    for(int i=0; length!=paragraphLength; ++i){  //iterating through the entire paragraph
        char storage[201];
        char* sentence = nextSentence(paragraph,storage, length); //creating sentence where the last one ended
        
        strcpy(current->sentence, sentence); ///copying that to struct


        current->length = strlen(current->sentence); //calculating length
        length += current->length; //calculating how far we have traveled through the paragraph

        if(length<paragraphLength){
            current->next = (Node*)calloc(1, sizeof(Node));
            current = current->next; //setting current to the next node in the linked list
        }
    }
    current->next = NULL; //end of linked list
    return first; //return first

}

char* nextSentence(char* paragraph, char*sentence, int index){
    int x = 0;
    for(int i=0; 2<3; ++i){
        sentence[i] = paragraph[index + i]; //appending each character from the paragraph tp our sentence

        int ascii_value = paragraph[index+i]; //calculating the ascii value
        if(ascii_value==39){    //39 is the ascii value for ' and we wont to record when we are in an open ' so that a . will not stop the sentence 
            ++x;
        }

        if(ascii_value == 46){     //46 is the ascii value for . and will tell us when to stop
            if((x%2)==0){ //calculating if the . is valid or not
                return sentence; //returning sentence
            }
        }else if(ascii_value == 63){ //63 is the ascii value for a question mark
            if((x%2)==0){ //calculating if the . is valid or not
                return sentence; //returning sentence
            }
        }
    }
}

void longest(Node *first) //calculating longest sentence
{
    Node* p = NULL;
    char sentence[201]; //declaring new string
    int longest = first->length; //setting the first length to the longest
    for(p = first; p != NULL; p = p->next) //iterating through all nodes
    {
        printf("hello");
        if(longest <= p->length){ //finding the longest length
            longest = p->length;
            strcpy(sentence,p->sentence); //copying new longest string
        }
    }
    printf("%d\n%s\n", longest, sentence); //printing output
}

void shortest(Node *first) //calculating shortest sentence
{
    Node* p = NULL;
    char sentence[201]; //declaring new string
    int shortest = first->length;
    for(p = first; p != NULL; p = p->next) //iterating through all nodes
    {
        if(shortest >= p->length){
            shortest = p->length;
            strcpy(sentence,p->sentence); //copying new shortest string
        }
    }
    printf("%d\n%s\n", shortest, sentence); //printing output
}