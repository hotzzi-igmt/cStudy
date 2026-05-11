#include<stdio.h>

#pragma warning(disable:4996)

//도상우 문제

int main(void)
{
	int n;
	int score[100];

	int up = 0;
	int down = 0;
	int same = 0;

	printf("Input number: \n");
	scanf("%d", &n);

	printf("Input scores: \n");

	for (int i = 0;i < n;i++)
	{
		scanf("%d", &score[i]);
	}

	for(int i=0;i<n - 1;i++)
	{

		if (score[i] < score[i + 1])
		{
			up++;
		}
		else if (score[i] > score[i + 1])
		{
			down++;
		}
		else
		{
			same++;
		}
	}
	printf("up: %d down: %d same: %d", up, down, same);

	return 0;
}
