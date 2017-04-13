#include <iostream>
#include <vector>
#include <string>
using namespace std;
int l, d, n;
vector<string> vt;
vector<string> lis;
char inp[55000];
int hash[5500];
int code[5500];

void Do(int t)
{
	string temp;
	lis.clear();
	int i, j, k;
	i = 0;
	while (inp[i] != '(' && inp[i] != '\0')
	{
		temp = inp[i++];
		lis.push_back(temp);
	}
	for (i = 0; inp[i] != '\0'; i++)
	{
		if (inp[i] == '(')
		{	
			temp.erase();
		}
		else if (inp[i] == ')')
		{
			lis.push_back(temp);
			temp.erase();
			i++;
			while (inp[i] != '(' && inp[i] != '\0')
			{
				temp = inp[i++];
				lis.push_back(temp);
			}
			i--;
		}
		else
		{
			temp += inp[i];
		}
	}
	for (i = 0; i < d; i++)
	{
		hash[i] = 1;
	}
	for (i = 0; i < l; i++)
	{
		for (j = 0; j < d; j++)
		{
			code[j] = 0;
		}
		for (j = 0; j < d; j++)
		{
			if (hash[j])
			{
				for (k = 0; k < lis[i].size(); k++)
				{
					if (vt[j][i] == lis[i][k])
					{
						code[j]++;
					}
				}
			}
		}
		for (j = 0; j < d; j++)
		{
			hash[j] *= code[j];
		}
	}

	int ans = 0;
	for (i = 0; i < d; i++)
	{
		ans += hash[i];
	}
	printf("Case #%d: %d\n", t, ans);
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w+", stdout);
	int i;
	char str[20];
	while (scanf("%d %d %d", &l, &d, &n) == 3)
	{
		vt.clear();
		for (i = 0; i < d; i++)
		{
			scanf("%s", str);
			vt.push_back(str);
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%s", inp);
			Do(i);
		}
	}
	return 0;
}
