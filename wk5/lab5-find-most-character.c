#include<stdio.h>
#include<string.h>

int main(int argc, char * argv[]){
    char *pointer = argv[1];
    int highest_count = 0;
    int result = 0;
    int length = strlen(argv[1]);
    char *test = " ";
    for(int i = 0; i < length; ++i){
        int x = 0;
        for(int j = 0; j < length; ++j){
           if (*(pointer+i)==*(pointer+j)){
            ++x; 
        }
        }
        if(*(pointer+i) != *(test) ){
            if(x>highest_count){
                highest_count = x;
                result = i;
        }
        }
    }
    printf("%c\n",*(pointer+result));
    return 0;
}
