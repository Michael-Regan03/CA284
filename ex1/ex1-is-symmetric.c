#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[]){
    char *str = argv[1]; //creating string from first argument
    int length = strlen(str); //find string length
    int x = 0;
    for(int i=0; length>i; ++i){
        int one = str[i];
        int two = str[length-1-i];
        int sum = one - two; //subtracting the ascii values to see if they equal
        if(sum==0) //Finding if the letters are the same
        {
            x = x+1;
        }
    }
    if(length==x){
        printf("yes\n"); //printing yes
        return 0;
    }
    printf("no\n"); //printing no
    return 0;
}