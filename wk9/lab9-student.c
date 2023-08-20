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
void printing(Students *pointer, int length);

int main(int argc, char *argv[])
{
    Students *students;
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
    printing(students, length);
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

void printing(Students *pointer, int length)
{
    for (int i=0; i < length; ++i)
    {
        printf("%s, %s, %.2f\n", *(pointer+i)->name, *(pointer+i)->programme, *(pointer+i)->grade);
    }
}
