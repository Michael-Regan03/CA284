#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct Shopping Shopping;

struct Shopping //initialising a struct for the shopping cart
{
    char item[20];
    unsigned int quantity;
    float price;
    int promotion;
    
};

void addToCart(Shopping s[], int length, char*argv[]);
void trueOrFalse(int x);
void printing(Shopping c[], int length);

int main(int argc, char*argv[])
{
    Shopping shopping[50]; 

    int length = ((argc-1)/4);   //calculating how many different items there are

    addToCart(shopping,length,argv);
    printing(shopping, length);

    return 0;
}

void addToCart(Shopping s[], int length, char*argv[]){
    int index = 0;
    for(int i=0; i<length; ++i) //appending all the values to the struct
    {
        strcpy(s[i].item, argv[index+1]);
        s[i].quantity = atoi(argv[index+2]);
        s[i].price = atof(argv[index+3]);
        s[i].promotion = atoi(argv[index+4]);
        index = index + 4;
    }
}

void trueOrFalse(int x){
    if(x==1){               //find if an item is on sale or not
        printf("On Sale\n");
    }
    else{
        printf("No Sale\n");
    }
}

void printing(Shopping c[], int length) 
{
    for(int i=0;i<length; ++i)
    {
        printf("%s,%d,%.2f,", c[i].item, c[i].quantity, c[i].price);    //printing the values
        trueOrFalse(c[i].promotion);
    }
}