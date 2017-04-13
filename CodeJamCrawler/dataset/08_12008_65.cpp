#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int MAX_N = 2000 + 100;

int n, m;
int deg[MAX_N], stat[MAX_N];
pair<int, int> adj[MAX_N][MAX_N];

bool comp(const pair<int, int> & a, const pair<int, int> & b) { return a.second > b.second; }

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int caseNo = 0; caseNo < cases; ++caseNo)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", &deg[i]);
			for (int j = 0; j < deg[i]; ++j)
			{
				scanf("%d %d", &adj[i][j].first, &adj[i][j].second);
				--adj[i][j].first;
			}
			if (deg[i] > 0)
				sort(adj[i], adj[i] + deg[i], comp);
		}
		fill(stat, stat + n, 0);
		bool fail = false;
		while (!fail)
		{
			static int seq[MAX_N];
			int seqCnt = 0;
			for (int i = 0; i < m; ++i)
			{
				bool succ = false;
				for (int j = 0; j < deg[i]; ++j)
					if (stat[adj[i][j].first] == adj[i][j].second)
					{
						succ = true;
						break;
					}
				if (!succ)
					seq[seqCnt++] = i;
			}
			if (seqCnt == 0)
				break;
			else
			{
				bool changes = false;
				for (int i = 0; i < seqCnt; ++i)
				{
					int x = seq[i];
					if (deg[x] == 0 || adj[x][0].second != 1)
					{
						fail = true;
						break;
					}
					if (stat[adj[x][0].first] != adj[x][0].second)
						changes = true;
					stat[adj[x][0].first] = adj[x][0].second;
				}
				if (!changes)
				{
					fail = true;
					break;
				}
			}
		}
		printf("Case #%d:", caseNo + 1);
		if (fail)
			printf(" IMPOSSIBLE\n");
		else
		{
			for (int i = 0; i < n; ++i)
				printf(" %d", stat[i]);
			printf("\n");
		}
	}
	return 0;
}

