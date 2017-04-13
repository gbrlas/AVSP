#include <stdlib.h>
#include <stdio.h>
#include <fstream>

struct pair{
	int A;
	int B;
	int result;
};

struct info{
	int source_number;
	char first;
	int length;
	char str[8];
};

info get_info(int number)
{
	info infomation;
	infomation.source_number = number;
	itoa(number,infomation.str,10);
	infomation.first = infomation.str[0];
	infomation.length = strlen(infomation.str);
	infomation.str[infomation.length] = '\0';
	return infomation;
}

int cycle(char* source, int start, int length)
{
	char *p;
	p = new char[length];
	for(int i = 0; i < length; i++)
	{
		p[i] = source[start];
		start++;
		if (start == length)
			start = 0;
	}
	return atoi(p);
}

int main()
{
	int counts = 0;
	freopen("D:\\1.in","r",stdin);
	freopen("D:\\1.out","w",stdout);
	scanf("%d\n",&counts);

	pair groups[50];
	int i = 0;
	while (i < counts)
	{
		scanf("%d %d",&groups[i].A,&groups[i].B);
		groups[i].result = 0;
		i++;
	}

	i = 0;
	while(i < counts)
	{
		int B_first = get_info(groups[i].B).first;
		int j = groups[i].A;
		for(j;j<=groups[i].B;j++)
		{
			info t_info = get_info(j);
			for(int k = 1; k < t_info.length;k++)
			{
				if(t_info.str[k]>B_first || t_info.str[k] == '0' ||t_info.str[k]<t_info.first)
					continue;
				int r = cycle(t_info.str,k,t_info.length);
				if (r > groups[i].B || r <= t_info.source_number)
					continue;
				else
				{
					//printf("%d\t%d\n",t_info.source_number,r);
					groups[i].result++;
				}
			}
		}
		i++;
	}

	i = 0;
	while(i < counts)
	{
		printf("Case #%d: %d\n", i+1, groups[i].result);
		i++;
	}

	fclose(stdin);
	fclose(stdout);
}