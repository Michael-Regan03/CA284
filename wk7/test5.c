#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* define a new type */
typedef struct Country Country;

/* Define the new struct */
struct Country
{
	char name[20];
	char capital[20];
	float population;
	unsigned long int size;
};

/* function prototypes */
void addCountries(Country c[], int argc, char*argv[]);
void printCountries(Country c[], int numberOfCountries);
void swapCountries(Country *p1, Country *p2);
void sortCountries(Country c[], int numberOfCountries);


int main(int argc, char*argv[])
{
	Country country[50];
	int numberOfCountries = (argc - 1)/4;

	addCountries(country, argc, argv);
	sortCountries(country, numberOfCountries);
	printCountries(country, numberOfCountries);


	return 0;
}

void addCountries(Country c[], int argc, char*argv[])
{
	int numberOfCountries = (argc - 1)/4;

	int index = 1;
	for(int i = 0; i < numberOfCountries; ++i)
	{
		strcpy(c[i].name, argv[index]);
		strcpy(c[i].capital, argv[index + 1]);
		c[i].population = atof(argv[index + 2]);
		c[i].size = atoi(argv[index + 3]);
		index = index + 4;
	}
}

void printCountries(Country c[], int numberOfCountries)
{

	printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
	for(int i = 0; i < numberOfCountries; ++i)
	{
		printf("%s\t\t\t%s\t\t\t%lu\t\t\t%.2f\n", c[i].name, c[i].capital, c[i].size,  c[i].population);
	}
}

double averageCal(Country c[], int numberOfCountries)
{
	float sum = 0;
	for(int i = 0; i < numberOfCountries; ++i)
	{
		sum += c[i].population;
	}
	return (double)sum/numberOfCountries;
}

void sortCountries(Country c[], int numberOfCountries)
{
	for(int i = 0; i < numberOfCountries; ++i)
	{
		for(int j = i; j < numberOfCountries; ++j)
		{
			if(c[i].population < c[j].population)
			{
				swapCountries(&c[i], &c[j]);
			}
		}
	}
}

void swapCountries(Country *p1, Country *p2)
{
	Country temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}