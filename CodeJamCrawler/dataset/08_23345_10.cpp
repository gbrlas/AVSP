#include <iostream>
using namespace std;

int node[20000][2]; // 0 is v, 1 is gate
int change[20000];
int ans[20000];
int a[20000];
int m, v;
int best;

void dfs(int index, int tot);

int main()
{
	int cases;
	cin >> cases;
	for(int c = 1; c <= cases; c++)
	{
		cin >> m >> v;
		for(int i = 1; i <= (m - 1) / 2; i++)
			cin >> node[i][1] >> change[i];
		for(int i = (m - 1) / 2 + 1; i <= m; i++)
			cin >> node[i][0];
		for(int i = (m - 1) / 2; i >= 1; i--)
			if (node[i][1] == 1)
				node[i][0] = node[2 * i][0] & node[2 * i + 1][0];
			else
				node[i][0] = node[2 * i][0] | node[2 * i + 1][0];
		cout << "Case #" << c << ": ";
		if (v == node[1][0])
			cout << 0 << endl;
		else
		{
			best = 1 << 30;
			dfs(1, 0);
			if (best == 1 << 30)
				cout << "IMPOSSIBLE" << endl;
			else
				cout << best << endl;
		}
	}
	return 0;
}

void dfs(int index, int tot)
{
	if (index > (m - 1) / 2)
	{
		for(int i = (m - 1) / 2; i >= 1; i--)
		{
			int gate;
			if (a[i])
				gate = 1 - node[i][1];
			else
				gate = node[i][1];
			if (gate == 1)
				node[i][0] = node[2 * i][0] & node[2 * i + 1][0];
			else
				node[i][0] = node[2 * i][0] | node[2 * i + 1][0];
		}
		if (v == node[1][0] && best > tot)
			best = tot;
		return;
	}
	if (change[index])
		for(int i = 0; i < 2; i++)
		{
			a[index] = i;
			if (i == 1)
				dfs(index + 1, tot + 1);
			else
				dfs(index + 1, tot);
		}
	else
	{
		a[index] = 0;
		dfs(index + 1, tot);
	}
}
