//Michael Regan
//Student ID 22112111
//This programme takes strings from command line consisting of the A's L's and P's
//Each string is a student and if they have 3 strick's we print a 1 else we print 0
//1 A is = to an strick
//3 L's in a row is = t a strick

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void readData(char* pointer);
char* substring(char* record, char*letter, int index);

int main(int argc, char *argv[])
{
    int length = argc -1;
    for(int i=0; i<length; ++i){
        readData(argv[1+i]); 
    }
}

void readData(char* pointer){
    
    int absentCheck = 0; //declaring absent check as int
    int lateTally = 0; //declaring a tally for the amount of lates in a row
    

    char record[100]; //declaring string for the students record
    strcpy(record,pointer); //copying string
    for(int i=0; i < strlen(pointer) ; ++i){
        char letter[2]; //initialising storage space
        
        char * str = substring(record,letter,i);        
        if(strcmp(str,"A")==0){ //comparing string to A for absent
            ++absentCheck; //absents go up by 1
        }
        else if(strcmp(str,"L")==0){
            ++lateTally; //tally of lates
            if(lateTally==3){ //3 lates in a row
                ++absentCheck;
                lateTally = 0; //tally back to zero
            }
        }
        else if(strcmp(str,"L") != 0){ //if the student was not late that day
            lateTally = 0; //tally back to zero
        }
    }
    if(absentCheck > 2){ //if the student had 3 or more lates
        printf("1\n"); //printing one
    }
    else{ //else
        printf("0\n"); //printing 0
    }
}


char* substring(char* record, char*letter, int index){
    for(int i =0; i<1;++i){ //creating a string of One letter
        letter[i] = record[index+i]; //appending one letter to the substring
    }
    return letter; //retuning the letter

}