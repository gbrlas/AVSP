#include <iostream>
#include <string>
using namespace std;

struct node
{
	int len;
	int id[20];
}num[300];
string s;
char str[550];
int dp[550];

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w+", stdout);
	int i, j, tt = 1, t;
	s = "welcome to code jam";
	memset (num, 0, sizeof(num));
	for (i = 0; i < s.length(); i++)
	{
		num[s[i]].id[num[s[i]].len++] = i + 1;
	}
	scanf("%d", &t);
	gets(str);
	while (t--)
	{
		gets(str);
		memset (dp, 0, sizeof(dp));
		dp[0] = 1;
		for (i = 0; str[i] != '\0'; i++)
		{
			if (num[str[i]].len)
			{
				for (j = 0; j < num[str[i]].len; j++)
				{
					if (dp[num[str[i]].id[j] - 1])
					{
						dp[num[str[i]].id[j]] = (dp[num[str[i]].id[j] - 1] + dp[num[str[i]].id[j]]) % 10000;
					}
				}
			}
		}
		printf("Case #%d: %04d\n", tt++, dp[s.length()]);
	}
	return 0;
}
