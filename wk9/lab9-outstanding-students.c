#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Students Students;

struct Students
{
    char* name[200];
    char* programme[200];
    double grade[4];
    Students *next;
};

void appendToList(Students *pointer, int length, char *argv[],int argc);
float averageGrade(Students* pointer,int length, int flag);
void outstandingStudents(Students* outstandingStudents, Students* pointer,int length, int average);

int main(int argc, char *argv[])
{
    Students *students;
    Students *outstandingStudent;
    
    int length = 2;
    students = (Students *)calloc(6, sizeof(Students));
    if ((argc - 1) > 6)
    {
       length += (((argc - 1) / 3) - 2);
       Students *temp = (Students *)realloc(students, length * sizeof(Students));
       if (!temp)
       {
            printf("Memory reallocation failed");
            free(students);
            students = NULL;
            exit(0);
        }
        students = temp;
    }
    appendToList(students, length, argv, argc);
    float average = averageGrade(students, length, 0);
    
    outstandingStudents(outstandingStudent, students, length, average);



    printf("Average grade: %.2f\n", average);
    return 0;
}

void appendToList(Students *pointer, int length, char *argv[],int argc)
{
    for (int i=0; i < length; ++i)
    {
        *(pointer + i)->name = argv[1+(3*i)];
        *(pointer + i)->programme = argv[2+(3*i)];
        *(pointer + i)->grade = atof(argv[3+(3*i)]);
    }
}

float averageGrade(Students* pointer,int length, int flag)
{
    float average = 0;
    for (int i=0; i < length; ++i)
    {
        double sum = (*(pointer + i)->grade);
            average += sum;
    }
    float output = average/length;
    return output;
}


void outstandingStudents(Students* outstandingStudents, Students* pointer,int length, int average){
    int averageLength = 0;
    outstandingStudents = (Students *)calloc(averageLength, sizeof(Students));
    char str[200] = "CSCE";
    for (int i=0; i < length; ++i)
    {
       float sum = (*(pointer + i)->grade);
        if(sum > average){
            int x = strcmp(*(pointer + i)->programme,str);
            if(x == 0){
                Students *temp = (Students *)realloc(outstandingStudents, averageLength+1 * sizeof(Students));
                outstandingStudents = temp;
                *(outstandingStudents + averageLength)->name = *(pointer + i)->name;
                *(outstandingStudents + averageLength)->programme = *(pointer + i)->programme;
                *(outstandingStudents + averageLength)->grade = *(pointer + i)->grade;
                printf("%s, %.2f\n",*(outstandingStudents + averageLength)->name,*(outstandingStudents + averageLength)->grade);
                ++ averageLength;
            }
       }
    }
}
