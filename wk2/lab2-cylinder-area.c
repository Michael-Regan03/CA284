#include<stdio.h>
#include<stdlib.h>

#define PI 3.1415

int main(int argc, char*argv[]){

    int radius = 0;
    int height = 0;
    float area = 0.0;
    radius = atoi(argv[1]);
    height = atoi(argv[2]);
    
    if(argc <= 1){
        printf( "No input given!");}
    else if(argc <= 2){
        printf( "Two arguments needed!");}
    else if(radius >= 0 || height >= 0){
        area = (2*PI*radius*height)+(2*PI*radius*radius);
        printf("%.2f\n",area);}
    else{
        printf("The radious or height cannot be negative!");
    }

    return(0);
}