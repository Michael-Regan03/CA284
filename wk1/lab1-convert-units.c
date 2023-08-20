#include <stdio.h>
#include <stdlib.h> 



int main(int argc, char * argv[]){
    int centimeters = 0;
    float inches = 2.54;
    float result = 0.0;
    centimeters = atoi(argv[1]);

    result = centimeters / inches;

    printf("%.2f\n",result);


    return(0);
}