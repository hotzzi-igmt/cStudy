#include<stdio.h>

#pragma warning(disable:4996)

//이국정 문제 1

int main(void)
{
	int arr[7];

	printf("Input 7 digits: \n");

	for (int i = 0;i < 7; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("compact result: ");

	int count = 1;

	for(int i=0;i<6; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			count++;
		}
		else
		{
			printf("%d(%d)", arr[i], count);

			count = 1;
		}
	}

	printf("%d(%d)", arr[6], count);

	return 0;
}