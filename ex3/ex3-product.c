//This program reads arguments off the command line and appends them to a linked list. 
//The linked list is a struct called "Product" which contains "code", "country", "price" and the next product in the list.
//Then all the products are ran through a function called irishTax() which adds 20 percent to every product where country=Ireland.
//Finally every product is printed out in order from first appended on the list to last appended on the list


#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct Product Product;

struct Product
{
    char code[20];
    char country[200];
    int price;
    Product* next;
};

Product* findProduct(int length, char*argv[]);
Product* irishTax(Product *first);
void printProducts(Product *first);

int main(int argc,char *argv[]){
    int length = (argc -1 )/ 3; //there are 3 variables in each struct so the amount of products is the length of the arguments /3
    Product* first;
    first = findProduct(length,argv);
    first = irishTax(first);
    printProducts(first);
    
    return 0;
}   


Product* findProduct(int length, char*argv[])
{
    Product* first,*current = NULL;

    first = (Product*)calloc(1, sizeof(Product)); //using dynamic memory to hold the first product
    current = first;

    for(int i = 0; i < length; ++i) 
    {   
            strcpy(current->code, argv[1 + (i*3)]); //copping the code of the product
            strcpy(current->country, argv[2 + (i*3)]); //copping the country of the product
            current->price = atoi(argv[3+(i*3)]); //recording the price of the product
            if(i == length - 1){ //test to see if we've reached the last product
                current->next = NULL; //next product = NULL

            }
            else{
                current->next =  (Product*)calloc(1, sizeof(Product)); //using dynamic memory to make space in memory for the next product
                current = current->next;//iterating to the next product
           }
    }
    return first; //returning first
}

Product* irishTax(Product *first)
{
    Product* p = NULL;
    for(p = first; p != NULL; p = p->next) //iterating through all the products
    {
        int x = strcmp(p->country,"Ireland"); //if the country is ireland
        if(x==0){
            p->price += (p->price*0.2); //adding 20 percent to the price
        }
    }
    return first; //returning first
}

void printProducts(Product *first)
{
    Product* p = NULL;
    for(p = first; p != NULL; p = p->next) //iterating through all products
    {
        //printing
        printf("%s\n", p->code);
        printf("%s\n", p->country);
        printf("%d\n", p->price); 
    }
}