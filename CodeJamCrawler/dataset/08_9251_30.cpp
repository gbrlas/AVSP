// test
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef unsigned long UL;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;

#define foreach(it,c) for (it=(c).begin(); it!=(c).end(); it++)

VI v1[104], v2[104];
int num[11], m, n;

bool dfs(int p)
{
	int i, j, k;
	for (i = 0;i < m;i++)
	{
		if (v1[i].size() == 0)
			continue;
		for (k = 0;k < n;k++)
		{
			int h = p & num[k];
			if (h) h = 1;
			else h = 0;
			for (j = 0;j < v1[i].size();j++)
			{
				if (v1[i][j] == k && v2[i][j] == h)
					break;
			}
			if (j < v1[i].size())
				break;
		}
		if (k == n) 
			return 0;
	}
	return 1;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

	int t, i, k = 1, j;
	num[0] = 1;
	for (i = 1;i <= 10;i++)
		num[i] = num[i - 1] * 2;

	scanf("%d", &t);
	while (t --)
	{
		scanf("%d%d", &n, &m);
		for (i = 0;i < m;i++)
		{
			v1[i].clear();
			v2[i].clear();
			int s = 0;
			scanf("%d", &s);
			for (j = 0;j < s;j++)
			{
				int a, b;
				scanf("%d%d", &a, &b);
				a--;
				v1[i].push_back(a);
				v2[i].push_back(b);
			}
		}

		int h = 1 << n;
		for (i = 0;i < h;i++)
			if (dfs(i))break;

		printf("Case #%d: ", k++);
		if (i < h)
		{
			for (j = 0;j < n;j++)
			{
				printf("%d", (i&num[j]) > 0 ? 1 : 0);
				if (j == n - 1)printf("\n");
				else printf(" ");
			}
		}
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}