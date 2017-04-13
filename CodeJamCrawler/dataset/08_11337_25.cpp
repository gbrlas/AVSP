#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char tmp[2000], line[2000];
int list[20], k, len, Min;
bool used[20];

void dfs(int n)
{
	if (n==0)
	{
		for (int i=0; i<len/k; i++)
			for (int j=1; j<=k; j++)
				tmp[i*k+j-1]=line[i*k+list[j]-1];
		int num=1;
		for (int i=1; i<len; i++)
			if (tmp[i]!=tmp[i-1]) num++;
		if (num<Min) Min=num;
	}
	for (int i=1; i<=k; i++) if (!used[i])
	{
		used[i]=true;
		list[n]=i;
		dfs(n-1);
		used[i]=false;
	}
}

int main()
{
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	int t; scanf("%d", &t);
	for (int step=1; step<=t; step++)
	{
		scanf("%d%s", &k, line);
		Min=len=strlen(line);
		memset(used, false, sizeof(used));
		dfs(k);
		printf("Case #%d: %d\n", step, Min);
	}
	return 0;
}
