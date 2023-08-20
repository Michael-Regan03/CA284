#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[]){
    if (argv[1]==1){
        printf("Sunday");}
    else if(argv[1]==2){
        printf("monday");}
    else if(argv[1]==3){
        printf("Tuesday");}
    else if(argv[1]==4){
        printf("Wednesday");}
        else if(argv[1]==5){
        printf("Thursday");}
    else if(argv[1]==6){
        printf("Friday");}
    else if(argv[1]==7){
        printf("Saturday");}
    return 0;
}
