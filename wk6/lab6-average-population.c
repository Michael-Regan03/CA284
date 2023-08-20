#include<string.h>
#include<stdlib.h>
#include<stdio.h>


typedef struct Country Country;


struct Country
{
	char name[20];
	char capital[20];
	float population;
	unsigned long int size;
};


void addCountries(Country c[], char*argv[], int argc);
float findAverage(Country c[], int numberOfCountries);
void printCountries(Country c[], int numberOfCountries);

int main(int argc, char*argv[])
{
    Country country[50];
    int length = ((argc-1)/4);
    
    addCountries(country, argv, argc);
    printCountries(country, length);
	printf("Population average: %.2f\n" ,findAverage(country, length));
    
    return 0;
}

void addCountries(Country c[], char*argv[], int argc)
{
   
    int length = ((argc-1)/4);
    int index = 0;
    for(int i=0; i<length; ++i)
    {
        strcpy(c[i].name, argv[index+1]);
        strcpy(c[i].capital, argv[index+2]);
        c[i].population = atof(argv[index+3]);
        c[i].size = atoi(argv[index+4]);
        index = index + 4;
    }
}

void printCountries(Country c[], int numberOfCountries)
{
	printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
	for(int i = 0; i < numberOfCountries; ++i)
	{
		printf("%s\t\t\t%s\t\t\t%lu\t\t\t%.2f\n", c[i].name, c[i].capital, c[i].size, c[i].population);
	}
}

float findAverage(Country c[], int numberOfCountries){
    float average = 0;
    for(int i=0; i<numberOfCountries; ++i){
        average += c[i].population;
    }
    return (float)average/numberOfCountries;
}