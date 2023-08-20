#include<stdio.h>
#include<stdlib.h>

/*Declare a structure of Student */
typedef struct Student Student;

struct Student {
	char name[20];
	char programme[20];
	float grade;
	Student *next;
	Student *prev;
};

/*Functional prototype */
Student* get_students(int argc, char*argv[]); /* You may notice that the function get_students return the type Student*, implying that the function will return a pointer that points to a Student */
void printStudentListInReverse(Student *last); /*to print the student list */

int main(int argc, char*argv[])
{
	Student *start = NULL;
	start = get_students();
	printStudentListInReverse(start);
	return 0;
}

Student* get_students(int argc, char*argv[]) /* This mean that the function will return a pointer that points to the structure Student */
{
	Student *current, *first, *prev; /*declare two pointers */
	int selection; /* to ask if the user keep entering new student data or stop */


	first = (Student*)calloc(1,sizeof(Student)); /*create the first node */
	current = first; /*Now the current node is also the first node */
    for(int i =0; i> argv[1]; ++i){
        first = (Student*)calloc(1,sizeof(Student)); /*create the first node */
	    current = first;
        current->next = (Student*)calloc(1, sizeof(Student));
        prev = current;
        current = current->next;
        current->prev = prev;
    }
    current->next = NULL;
    return current; 

	/*fill data for the first node */
	printf("Student name: \n");
	scanf("%s", current->name);
	printf("Programme: \n");
	scanf("%s", current->programme);
	printf("Grade: \n");
	scanf("%f",  &current->grade);
	current->prev = NULL;

	printf("Add more student? (1=Y, 0 = N): \n");
	scanf("%d", &selection);

	/*create the following nodes until the user select No */
	while(selection) //while selection is 1 (Yes)
	{
		/* allocate the new node */
		current->next = (Student*)calloc(1, sizeof(Student));

		/*get the previous node before move the current pointer to the next */
		prev = current;

		/* move the current pointer to the next node */
		current = current->next;

		/*fill the new node */
		printf("Student name: \n");
		scanf("%s", current->name);
		printf("Programme: \n");
		scanf("%s", current->programme);
		printf("Grade: \n");
		scanf("%f",  &current->grade);
		current->prev = prev;

		printf("Add more student? (1=Y, 0 = N): \n");
		scanf("%d", &selection);
	}

	current->next = NULL; /* in case the last node */
	return current; /* return the address of the last node */
}

void printStudentListInReverse(Student *last)
{
	int count = 0;
	Student* p = NULL;
	for(p = last; p != NULL; p = p->prev)
	{
		++count;
		printf("Student #%d: ", count);
		printf("%s, %s, %.2f\n", p->name, p->programme, p->grade);
	}
}