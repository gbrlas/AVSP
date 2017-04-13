#include <stdlib.h>
#include <stdio.h>
#include <fstream>


char code[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main()
{
	int counts = 0;
	char groups[30][101];
	freopen("D:\\1.in","r",stdin);
	freopen("D:\\1.out","w",stdout);
	scanf("%d\n",&counts);
	int i = 0;
	for (; i < counts; i++)
	{
		gets(groups[i]);
		groups[i][101] = '\0';
	}
	int j = 0;
	while(j < counts)
	{
		int k = 0;
		while(groups[j][k] != '\0')
		{
			if(groups[j][k] == ' ')
			{
				k++;
				continue;
			}
			else 
				groups[j][k] = code[groups[j][k] - 97];
			k++;
		}
		j++;
	}
	j = 0;
	while(j < counts)
	{
		printf("Case #%d: %s\n",j+1,groups[j]);
		j++;
	}
	fclose(stdin);
	fclose(stdout);
}