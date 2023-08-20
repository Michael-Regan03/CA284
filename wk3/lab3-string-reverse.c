#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[]){
    char *str = argv[1];
    char output[100];
    int length = strlen(str);
    
    for(int i=0; length>0; ++i){
        output[i] = str[length-i];
    }

    printf("%s\n", output);

}
