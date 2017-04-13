#include <iostream>
#include <string>
using namespace std;

int n;
int sum;
int lmax;
int hash[1100];
int value[1100];

void dfs(int id)
{
	if (id == n)
	{
		int xa = 0, xb = 0;
		int sa = 0, sb = 0;
		for (int i = 0; i < n; i++)
		{
			if (hash[i] == 0)
			{
				xa ^= value[i];
				sa += value[i];
			}
			else
			{
				xb ^= value[i];
				sb += value[i];
			}
		}
		if (xa == xb)
		{
			if (sa > lmax && sa < sum)
			{
				lmax = sa;
			}
		}
		return;
	}

	dfs(id + 1);

	hash[id] = 1;
	dfs(id + 1);
	hash[id] = 0;
}

int main()
{
	int i;
	int t, id = 0;
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w+", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		lmax = -1;
		memset (hash, 0, sizeof(hash));
		sum = 0;	
		for (i = 0; i < n; i++)
		{
			scanf("%d", &value[i]);
			sum += value[i];
		}
		dfs(0);
		printf("Case #%d: ", ++id);
		if (lmax == -1)
		{
			printf("NO\n");
		}
		else
		{
			printf("%d\n", lmax);
		}
	}
	return 0;
}
