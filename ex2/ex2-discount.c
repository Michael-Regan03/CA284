#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct Shopping Shopping;

struct Shopping
{
    char item[20];
    unsigned int quantity;
    float price;
    int promotion;
    
};

void addToCart(Shopping s[], int length, char*argv[]);
float calculating(Shopping c[],int length);

int main(int argc, char*argv[])
{
    Shopping shopping[50]; 

    int length = ((argc-1)/4);  

    addToCart(shopping,length,argv);
    printf("%.2f\n",calculating(shopping,length));

    return 0;
}

void addToCart(Shopping s[], int length, char*argv[]){
    int index = 0;
    for(int i=0; i<length; ++i) 
    {
        strcpy(s[i].item, argv[index+1]);
        s[i].quantity = atoi(argv[index+2]);
        s[i].price = atof(argv[index+3]);
        s[i].promotion = atoi(argv[index+4]);
        index = index + 4;
    }
}

float calculating(Shopping c[],int length){
    float sum = 0;
    for(int i=0;i<length;++i)
    {
        if(c[i].promotion==0){
            sum += (float)(c[i].quantity * c[i].price); //calculating when theres no promotion
        }
        else{
            int flag = 0; //flag for buy 3 get 1 free
            for(int j=0; j<c[i].quantity; ++j)
            {
                ++flag;
                if(flag==3)
                {
                    flag = 0; //third item is free
                }
                else
                {
                    sum += (float)c[i].price;
                }

            }
        }
    }
    return sum;
}