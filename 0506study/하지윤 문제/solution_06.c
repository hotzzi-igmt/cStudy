#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#pragma warning(disable:4996)

//김민철 문제

void splitNumber(int num, int* arr);
int isDuplicate(int* arr);
void checkResult(int comArr[], int userArr[], int* strike, int* ball, int* out);

int main(void)
{
	int com, user;
	int comArr[3];
	int userArr[3];

	srand((unsigned int)time(NULL));

	while (1)
	{
		com = rand() % 900 + 100;
		splitNumber(com, comArr);

		if (!isDuplicate(comArr))
		{
			break;
		}
	}
	printf("%d\n", com);


	while (1)
	{
		int strike = 0;
		int ball = 0;
		int out = 0;

		printf("Input number: \n");
		scanf("%d", &user);

		if (user < 100 || user > 999)
		{
			printf("Out of range. Please input valid number.\n");
			continue;
		}

		splitNumber(user, userArr);

		if (isDuplicate(userArr))
		{
			printf("Duplicated!\n");
			continue;
		}

		checkResult(comArr, userArr, &strike, &ball, &out);

		printf("%d Strike %d Ball %d Out\n", strike, ball, out);

		if (strike == 3)
		{
			printf("You win!\n");
			break;
		}
	}
	return 0;
}
void splitNumber(int num, int* arr)
{
	arr[0] = num / 100;
	arr[1] = (num / 10) % 10;
	arr[2] = num % 10;
}

int isDuplicate(int* arr)
{
	if (arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2])
	{
		return 1;
	}
	return 0;
}

void checkResult(int comArr[], int userArr[], int* strike, int* ball, int* out)
{
	for (int i = 0;i < 3;i++)
	{
		int isOut = 1;

		for (int j = 0;j < 3;j++)
		{
			if (userArr[i] == comArr[j])
			{
				if (i == j)
				{
					(*strike)++;
				}
				else
				{
					(*ball)++;
				}
				isOut = 0;
				break;
			}
		}
		if (isOut)
		{
			(*out)++;
		}
	}
}