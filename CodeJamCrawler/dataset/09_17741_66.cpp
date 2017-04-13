#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void int2str(int ans)
{
	char ret[5];
	memset(ret, 0, sizeof(0));
	int p[3] = {1000,100,10};
	for (int i = 0; i < 3; i++)
	{
		ret[i] = (ans/p[i] + '0');
		ans %= p[i];
	}
	ret[3] = ans + '0';
	for (int i = 0; i < 4; i++) putchar(ret[i]);
	putchar('\n');
}

int main()
{
	//freopen("C:\\in.txt","r", stdin);
	//freopen("C:\\out.txt","w", stdout);
	int n;
	int cnt[20];
	char line[505];
	char *str = "welcome to code jam";
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		memset(cnt, 0, sizeof(cnt));
		gets(line);
		for (int j = 0; j < strlen(line); j++)
		{
			if (line[j] == 'w') cnt[0]++;
			else
			{
				for (int k = 1; k < 19; k++)
				{
					if (line[j] == str[k])
					{
						cnt[k] = (cnt[k] + cnt[k-1]) % 10000;
					}
				}
			}
		}
		printf("Case #%d: ", i+1);
		int2str(cnt[18]);
	}
	return 0;
}