//Michael Regan
//Student ID 22112111
//This program reads in data from the command line. Every 3 arguments is an item in a groceries cart with code, price and number of items sold.
//This programme takes in that data and stores it in a struct called Product
//It then iterates through each object like a linked list and prints out its "Status" and "Country"
//The country is calculated by the first two characters of the product code and the status is either 1 or 0 depending on if the items sales are above the average.
// 13/12/22

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct Product Product;

struct Product
{
    char code[20];
    float price;
    int num_of_items_sold;
    int status;
    Product* next;
};

Product* findProduct(int length, char*argv[]);
char* country(char* code, char *pointer);
int averageSalePrice(Product* product);
void printing(Product*product);

int main(int argc,char *argv[]){
    int length = (argc -1 )/ 3; //there are 3 variables in each struct so the amount of products is the length of the arguments /3
    Product* first;
    first = findProduct(length,argv);
    printing(first);
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
            current->price = atof(argv[2+(i*3)]); //recording the price of the product
            current->num_of_items_sold = atoi(argv[3+(i*3)]);
            if(i == length -1){ //test to see if we've reached the last product
                current->next = NULL; //next product = NULL

            }
            else{
                current->next =  (Product*)calloc(1, sizeof(Product)); //using dynamic memory to make space in memory for the next product
                current = current->next;//iterating to the next product
           }
    }
    return first; //returning first
}


char* country(char *code, char* pointer){
    for(int i=0; i<2; ++i){
        pointer[i] = code[i]; //creating substring with first two characters of the product code
    }
    if(strcmp(pointer, "IE") == 0){  //string compare to see if country is Ireland
        return "Ireland";}
    if(strcmp(pointer, "FR") == 0){  //string compare to see if country is France
        return "France";}
    if(strcmp(pointer, "SP") == 0){   //string compare to see if country is Spain
        return "Spain";}
    if(strcmp(pointer, "US") == 0){   //string compare to see if country is USA
        return "USA";}
    if(strcmp(pointer, "RU") == 0){   //string compare to see if country is Russia
        return "Russia";}
}

int averageSalePrice(Product* product){
    Product *current = NULL;
    int total = 0;
    int counter = 0;
    for(current=product; current->next != NULL; current = current->next){
        int sales = current->price * current->num_of_items_sold;  //calculating sales
        total += sales;
        ++counter;  //counting how many items there are
    }
    int average = total/counter; //calculating average
    return average;
}

void printing(Product*product){
    Product *current = NULL;
    int average = averageSalePrice(product);  //running averageSalesPrice function
    for(current=product; current != NULL; current = current->next){ //iterating through linked list
        int sales = current->price * current->num_of_items_sold;  //calculating sales
        if(sales>=average){ //if sales > the average
            printf("1\n");   //print 1
        }else{
            printf("0\n");  //print 2
        }
        char identity[20]; //allocating space for the substring
        char* Country = country(current->code, identity);
        printf("%s\n", Country); //printing country of origin
    }
}