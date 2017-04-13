#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int select_[20];

void func()
{
	int i, j, choice;
	int card[4][4];

	scanf("%d", &choice);
	for(i = 0 ; i < 4 ; i++)
	{
		for(j = 0 ; j < 4 ; j++)
		{
			scanf("%d", &card[i][j]);
		}
	}

	for(i = 0 ; i < 4 ; i++)
	{
		select_[card[choice-1][i]]++;
	}
}

int output()
{
	int i, cnt=0, res;
	for(i = 1 ; i <= 16 ; i++)
	{
		if(select_[i] == 2)
		{
			cnt++;
			res = i;
		}
	}
	if(cnt == 1) return res;
	else if(cnt == 0) return -2;
	else return -1;
}

int main(void)
{
	int n, res;
	scanf("%d", &n);

	int i;
	for(i = 0 ; i < n ; i++)
	{
		memset(select_, 0, sizeof(select_));
		func();
		func();
		res = output();
		printf("Case #%d: ", i+1);
		if(res == -1) printf("Bad magician!\n");
		else if(res == -2) printf("Volunteer cheated!\n");
		else printf("%d\n", res);
	}
	return 0;
}