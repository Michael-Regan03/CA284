#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
    FILE *filestream = fopen("paragraph.txt", "r");
    
    char line[200];

    int max_length = 0;

    char output[200];

    while(fgets(line,sizeof(line), filestream)){
        int line_length = strlen(line);
        if(line_length>max_length){
            max_length=line_length; 
            strcpy(output, line);
        }
    }
    printf("%d\n%s\n",max_length,output);
    return 0;

}