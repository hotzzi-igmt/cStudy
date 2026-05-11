#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)

//이국정 문제 2

int main(void)
{
	int com;
	int user;
	int count = 0;

	int history[7];
	int historyCount = 0;

	srand((unsigned int)time(NULL));
	com = rand() % 100 + 1;

	printf("Input 7 digits: \n");

	while(count < 7)
	{
		scanf("%d", &user);

		if(user < 1 || user > 100)
		{
			printf("Out of range. Input again\n");
			continue;
		}

		int isDuplicate = 0;

		for (int i = 0; i < historyCount;i++)
		{
			if (history[i] == user)
			{
				isDuplicate = 1;
				break;
			}
		}
		if (isDuplicate)
		{
			printf("Already input digit\n");
			continue;
		}

		history[historyCount] = user;
		historyCount++;
		count++;

		if (user < com)
		{
			printf("UP\n");
		}
		else if (user > com)
		{
			printf("DOWN\n");
		}
		else
		{
			printf("You are correct in %d attempts!\n", count);
		}
	}
	if (count == 7 && user != com)
	{
		printf("You failed! The answer is %d", com);
	}
	return 0;
}