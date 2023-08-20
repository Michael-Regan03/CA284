#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int HappyNumber(int n){
    if(n<100){ // if n is two digits
    int num1 = (n%10);  //gets the first digit from n
    int num2 = (n/10)%10;   //gets the second digit from n
    int sum = (num1*num1) + (num2*num2);    //creating a happy number
    return sum;}
    else{ //if n is three digits
    int num1 = (n%10);  //gets the first digit from n
    int num2 = (n/10)%10; //gets the second digit from n
    int num3 = (n/10/10)%10; // getting third digit from n
    int sum = (num1*num1) + (num2*num2) + (num3*num3); //creating a happy number
    return sum;
    }
}


int main(int argc, char*argv[]){
    int happy_number = atoi(argv[1]);
    char unhappy_numbers[100];
    int i = 0;
    while(happy_number!=0){ //while loop
    int x = HappyNumber(happy_number); //using recursion to generate more happy numbers
    happy_number = x; 
    if(happy_number==1){    //testing for happy number
        printf("is happy\n"); //print "is happy"
        return 0; //closing loop
    }
    for(int j=0; j>i; ++j ){ //creating a list of previously generated numbers to see if we are in an infinite loop
        if(happy_number == unhappy_numbers[j]){
           printf("not happy\n"); //printing""not happy"
           return 0; //closing loop
          }
    }
    unhappy_numbers[i] = happy_number; //adding current happy number to unhappy_numbers[] list
    ++i; //tracking how long we've been looping for to see how large the unhappy_numbers[] list is
}
}