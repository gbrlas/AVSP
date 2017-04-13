#include <stdlib.h>
#include <fstream>
#include <stdio.h>

int non_surprising_max[31] = {0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10};
//int start_p[10] = {0,2,5,8,11,14,17,20,23,26};

struct dataset{
	int number;
	int surprising_num;
	int p;
	int scores[100];
	int result;
};

int main()
{
	int counts = 0;
	freopen("D:\\1.in","r",stdin);
	freopen("D:\\1.out","w",stdout);
	scanf("%d\n",&counts);

	dataset groups[2024];
	int i = 0;
	while (i < counts)
	{
		scanf("%d %d %d ",&groups[i].number,&groups[i].surprising_num,&groups[i].p);
		int j = 0;
		while (j < groups[i].number)
		{
			scanf("%d",&groups[i].scores[j]);
			j++;
		}
		groups[i].result = 0;
		i++;
	}

	i = 0;
	while (i < counts)
	{
		int j = 0;
		while (j < groups[i].number)
		{
			if (groups[i].p <= non_surprising_max[groups[i].scores[j]])
			{
				groups[i].result++;
			}
			else if(groups[i].scores[j] == 0||
					groups[i].scores[j] == 1||
					groups[i].scores[j] == 29||
					groups[i].scores[j] == 30||
					(groups[i].scores[j] -1)%3 == 0)
			{ /* do nothing */}
			else if(non_surprising_max[groups[i].scores[j]]+1 == groups[i].p)
			{
				if(groups[i].surprising_num > 0)
				{
					groups[i].result++;
					groups[i].surprising_num--;
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < counts)
	{
		printf("Case #%d: %d\n",i+1,groups[i].result);
		i++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}