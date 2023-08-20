#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void binary_to_decimal(char *argv[], int length);

int main(int argc, char *argv[]){
    int length = argc-1;
    binary_to_decimal(argv,length);
    return 0;
}

void binary_to_decimal(char *argv[], int length){
    int decimal = 0;
    int flag = 0;
    int flag2 = 0;
    int x = length;
    for(int i=0;i<length;++i){
        int num = atoi(argv[i]);
        if(num==1| num==0){
            decimal += (pow(2,x)*num);        
            ++flag2;
        }
        else if(num>1 | 0>num){
            ++flag; 
            ++flag2;
        }
        x = x-1;
    }
    //int y = pow(2,0);
    //printf("%d\n", y);
    if(length>8){
        printf("Too many binary digits entered.\n");
    }
    else if(flag2!=length){
        printf("Only digits 1 and 0 are permitted.\n");
    }
    else if(flag == 0){
        printf("%d\n",decimal);
    }
    else{
        printf("Only digits 1 and 0 are permitted.\n");
    }
}