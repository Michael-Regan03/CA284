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
void addCountries(Country *c, char*argv[]);
void printCountries(Country c);


int main(int argc, char*argv[])
{
	Country country;

	addCountries(&country, argv);
	printCountries(country);

	return 0;
}


void addCountries(Country *c, char*argv[])
{
	strcpy(c->name, argv[1]);
	strcpy(c->capital, argv[2]);
	c->population = atof(argv[3]);
	c->size = atoi(argv[4]);
}

void printCountries(Country c)
{
	printf("%s\n", c.name);
	printf("%s\n", c.capital);
	printf("%.2f million people\n", c.population);
	printf("%lu km2\n", c.size);
}