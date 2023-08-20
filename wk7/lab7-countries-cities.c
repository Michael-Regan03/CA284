#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct Country Country;
typedef struct City City;

struct City
{
    char name[20];
    int population;
};

struct Country
{
	char name[20];
	City city[20];
};

City FindCity(Country c);
void addCountries(Country c[], char*argv[], int argc);


int main(int argc, char*argv[])
{
    Country country[50]; 

    int length = ((argc-1)/7);
    addCountries(country, argv, argc);    
    
    for(int i=0; i<length;++i){
        City x = FindCity(country[i]);
        printf("%s: %s\n",country[i].name, x.name);
    }
    
    return 0;
}

void addCountries(Country c[], char*argv[], int argc)
{
   
    int length = ((argc-1)/7);
    int index = 1;
    for(int i=0; i<length; ++i)
    {
        strcpy(c[i].name, argv[index]);
        int indexCity = index + 1;
        for(int j=0; j<3; ++j)
        {
            strcpy(c[i].city[j].name, argv[indexCity]);
            c[i].city[j].population = atof(argv[indexCity+1]);
            indexCity += 2;
        }
        index = index + 7;
    }
}

City FindCity(Country c)
{
    City largestCity = c.city[0];
    int maxsize = c.city[0].population;
    for(int i=0; i<3; ++i)
    {
        if(maxsize < c.city[i].population)
        {
            maxsize = c.city[i].population;
            largestCity = c.city[i];
        }
    }
    return largestCity;

}

