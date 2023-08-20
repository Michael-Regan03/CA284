#include<stdio.h>
#include<stdlib.h>

#define PI 3.1415

int main(int argc, char*argv[]){

    int radius = 0;
    float area = 0.0;
    radius = atoi(argv[1]);


    if (radius >= 0){
        radius = radius*radius;
        area = radius* PI;
        printf("%.2f\n",area);}
    else{
        printf("ERROR: Radius must be a positive number");
    }

    return(0);


}