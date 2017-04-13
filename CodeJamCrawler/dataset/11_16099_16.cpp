#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char inp[33];
vector<string> d;
vector<string> l;

int getLost(string list, int index)
{
	int hash[110][30] = {0};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < d[i].length(); j++)
		{
			hash[i][d[i][j] - 'a'] = 1;
		}
	}
	int out = 0;
	int table[110] = {0};
	for (int i = 0; i < n; i++)
	{
		if (d[i].length() != d[index].length())
		{
			out++;
			table[i] = 1;
		}
	}
	int lost = 0;
	
	if (out < n - 1)
	{
		for (int i = 0; i < list.length(); i++)
		{
			char c = list[i];
			bool tag = false;
			for (int j = 0; j < n; j++)
			{
				if (table[j] == 0 && hash[j][c - 'a'] == 1)
				{
					tag = true;
					break;
				}
			}
			if (tag == false)
			{
				continue;
			}
			if (hash[index][c - 'a'] == 1)
			{
				for (int j = 0; j < n; j++)
				{
					if (table[j] == 0)
					{
						int f = true;
						for (int k = 0; k < d[index].length(); k++)
						{
							if ((d[j][k] == c && d[index][k] != c)
								|| (d[j][k] != c && d[index][k] == c))
							{
								f = false;
								break;
							}
						}
						if (f == false)
						{
							out++;
							table[j] = 1;
						}
					}
				}
			}
			else
			{
				lost++;
				for (int j = 0; j < n; j++)
				{
					if (table[j] == 0 && hash[j][c - 'a'] == 1)
					{
						out++;
						table[j] = 1;
					}
				}
			}
			if (out == n - 1)
			{
				break;
			}
		}
	}
	return lost;
}

string getAns(string list)
{
	int minlost = -1;
	string ans;
	for (int i = 0; i < n; i++)
	{
		int lost = getLost(list, i);
		if (lost > minlost)
		{
			ans = d[i];
			minlost = lost;
		}
	}
	return ans;
}

int main()
{
	freopen("B-small-attempt0.in", "r+", stdin);
	freopen("B-small-attempt0.out", "w+", stdout);

	int t, tt = 0;
	scanf("%d", &t);
	while (t--)
	{
		d.clear();
		l.clear();
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", inp);
			d.push_back(inp);
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%s", inp);
			l.push_back(inp);
		}
	
		printf("Case #%d: ", ++tt);
		for (int i = 0; i < m; i++)
		{
			if (i == 0)
			{
				printf("%s", getAns(l[i]).data());
			}
			else
			{
				printf(" %s", getAns(l[i]).data());
			}
		}
		puts("");
	}
	return 0;
}