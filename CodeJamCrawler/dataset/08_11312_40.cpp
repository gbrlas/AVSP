#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN=2000;

int way1[MaxN][MaxN], way2[MaxN][MaxN], p1[MaxN], p2[MaxN], rc[MaxN], list[MaxN], N, M;
bool used[MaxN];

void readin()
{
	memset(p1, 0, sizeof(p1));
	memset(p2, 0, sizeof(p2));
	memset(list, -1, sizeof(list));
	memset(rc, 0, sizeof(rc));
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++)
	{
		int p; scanf("%d", &p);
		for (int j=0; j<p; j++)
		{
			int x, y; scanf("%d%d", &x, &y);
			x--;
			if (y==0)
			{
				rc[i]++;
				way1[x][p1[x]++]=i;
			}
			else
			{
				list[i]=x;
				way2[x][p2[x]++]=i;
			}
		}
	}
}

void solve()
{
	memset(used, false, sizeof(used));
	while (true)
	{
		bool t=false;
		for (int i=0; i<M; i++) if (rc[i]==0)
		{
			if (list[i]==-1 || used[list[i]])
			{
				printf(" IMPOSSIBLE\n");
				return;
			}
			used[list[i]]=true;
			for (int j=0; j<p1[list[i]]; j++)
				rc[way1[list[i]][j]]--;
			for (int j=0; j<p2[list[i]]; j++)
				rc[way2[list[i]][j]]++;
			t=true;
		}
		if (!t) break;
	}
	for (int i=0; i<N; i++)
		if (used[i]) printf(" 1");
		else printf(" 0");
	printf("\n");
}

int main()
{
	freopen("b-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int t; scanf("%d", &t);
	for (int step=1; step<=t; step++)
	{
		readin();
		printf("Case #%d:", step);
		solve();
	}
	return 0;
}
