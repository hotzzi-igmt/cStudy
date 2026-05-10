#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

//김찬휘 문제 2

int countValid(int* arr, int n);

int main(void)
{
	int n;
	int arr[1000];
	int count = 0;

	printf("Input length of array: ");
	scanf("%d", &n);


	if (n < 1 || n > 1000)
	{
		printf("Input error");
		return 1;
	}

	for (int i = 0;i < n;i++)
	{
		printf("Input value of array: ");
		scanf("%d", &arr[i]);
	}

	int result = countValid(arr, n);

	printf("count=%d\n", result);

	return 0;
}

int countValid(int* arr, int n)
{
	int count = 0;

	for (int i = 0;i < n;i++)
	{
		int sum = 0;
		int max = arr[i];
		int	min = arr[i];

		for (int j = i;j < n;j++)
		{
			sum += arr[j];

			if (arr[j] > max)
				max = arr[j];

			if (arr[j] < min)
				min = arr[j];

			int len = j - i + 1;

			if (sum % len == 0)
			{
				int k = sum / len;

				if (max - min <= k)
				{
					count++;
					printf("[");
					for (int t = i; t <= j; t++)
					{
						printf("%d", arr[t]);

						if (t < j)
							printf(", ");
					}
					printf("] K=%d\n", k);
				}
			}
		}
	}
	return count;
}
