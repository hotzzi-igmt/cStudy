#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

//김찬휘 문제 1

int main(void)
{
	int n;
	int x = 0;

	printf("Input a number greater than 1: ");
	scanf("%d", &n);

	if (n <= 0)
	{
		printf("Input error\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int temp = i;
		int isValid = 1;

		while (temp > 0)
		{
			int digit = temp % 10;

			if (digit == 0 || i % digit != 0)
			{
				isValid = 0;
				break;
			}
			temp /= 10;
		}
		if (isValid)
		{
			x = i;
			printf("%d \n", x);
		}
	}
	return 0;
}
