#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{

	int width = atoi(argv[1]);

	for(int j = 0; j < width; ++j)
		printf("*");
	printf("\n");

	for(int i = 1; i < width - 1; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			if((j == 0) || (j == width - 1))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	for(int j = 0; j < width; ++j)
		printf("*");
	printf("\n");

	return 0;
}