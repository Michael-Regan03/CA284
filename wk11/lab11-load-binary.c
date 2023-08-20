#include<stdio.h>
#include<stdlib.h>

typedef struct Student Student;

struct Student{
    int nameLen;
    char name[50];
    int collegeLen;
    char college[40];
    int age;
    float grade;
};

long int findSize(char file_name[]);

int main()
{

    char *filename = "studentBinary.bin"; //So a binary file has an extension of '.bin'
    char file_name[] = { "studentBinary.bin" };
    long int sizeOfFile = findSize(file_name);
    
    FILE *pfile = NULL;
    pfile = fopen(filename, "rb"); //open a file with a binary mode
    if(!pfile) //check if the open operation work correctly
    {
        printf("Error opening %s for writing. Program terminated.\n", filename);
        exit(1);
    }

    int tally = 0;
    
    while(tally<sizeOfFile){
        Student s;
        fread(&s.nameLen, sizeof(int), 1, pfile);
        fread(s.name, sizeof(char), s.nameLen, pfile);
        fread(&s.collegeLen, sizeof(int), 1, pfile); 
        fread(s.college, sizeof(char), s.collegeLen, pfile); 
        fread(&s.age, sizeof(int), 1, pfile); 
        fread(&s.grade, sizeof(float), 1, pfile);
        printf("Name: %s\nCollege: %s\nAge: %d\nGrade: %.2f\n",s.name, s.college, s.age, s.grade);
        tally += (3*sizeof(int))+(s.nameLen*sizeof(char))+(s.collegeLen*sizeof(char))+(1*sizeof(float));
    }
    fclose(pfile); 
    return 0;
}

long int findSize(char file_name[]){
    // opening the file in read mode
    FILE* fp = fopen(file_name, "r");
  
    // checking if the file exist or not
    if (fp == NULL) {
        printf("File Not Found!\n");
        return -1;
    }
  
    fseek(fp, 0L, SEEK_END);
  
    // calculating the size of the file
    long int res = ftell(fp);
  
    // closing the file
    fclose(fp);

    return res;

}


