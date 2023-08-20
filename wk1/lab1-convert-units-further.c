#include <stdio.h>
#include <stdlib.h> 



int main(){
    int centimeters = 30;
    float inches = 2.54;
    float result = 0.0;
    result = centimeters / inches;
    while( centimeters >= 49){
        centimeters = centimeters + 1;
        result = centimeters / inches;
        printf("%.2f\n",result);

    }

    return(0);
}
