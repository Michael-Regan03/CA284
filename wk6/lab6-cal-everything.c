#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int sum(int, int);
int product(int, int);
int difference(int, int);
int division(int x, int y);
int powers(int x, int y);
int logs(int x, int y);

int main(int argc, char* argv[])
{
	int a = atoi(argv[1]);                
	int b = atoi(argv[2]);                       
	float result = 0;                     
	int (*pfunction)(int, int);          

	pfunction = sum;                    
	result = pfunction(a, b);               
	printf("%.2f\n", result);

	pfunction = difference;           
	result = pfunction(a, b);               
	printf("%.2f\n", result);
    
    
    pfunction = product;             
	result = pfunction(a, b);        
	printf("%.2f\n", result);

    pfunction = division;     
	result = pfunction(a, b);           
	printf("%.2f\n", result);

    pfunction = powers;
	result = pfunction(a, b);      
	printf("%.2f\n", result);

    pfunction = logs;         
	result = pfunction(a, b);       
	printf("%.2f\n", result);


	return 0;
}

int sum(int x, int y)
{
    return  (float)(x+y);;
}
int product(int x, int y)
{
    return (float)(x * y);
}
int difference(int x, int y)
{
    return (float)(x-y);
}
int division(int x, int y)
{
    return (float)(x/y);     
}
int powers(int x, int y){
    return (float)(pow(x,y));
}
int logs(int x, int y){
    return (float)(log(x) + log(y));
}