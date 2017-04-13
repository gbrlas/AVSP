#include <iostream>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10001
#define sqr(x) ((x) * (x))

struct node 
{
	int pos, len;
};

struct edges
{
	int st, ed;
};

node a[MAXN];
int from[MAXN];
int n;

void work()
{
	memset(from , 0 , sizeof(from)); 
	if (a[0].len >= a[0].pos) from[0] = a[0].pos; 
	bool ok = false;
	for (int i = 0; i < n; ++i)
	{
		if (a[n].pos - a[i].pos <= from[i])
		{
			ok = true;
			break;
		}
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j].pos - a[i].pos > from[i])
				break;
			if (a[j].len < a[j].pos - a[i].pos)
				from[j] = max(from[j], a[j].len);
			else
				from[j] = max(from[j], a[j].pos - a[i].pos);
		}
	}
	if (ok)
		puts("YES");
	else puts("NO");

}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, cases = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &a[i].pos, &a[i].len);
		scanf("%d", &a[n].pos);
		a[n].len = 1000000010;
		printf("Case #%d: ", ++cases);
		work();
		//printf("Case #%d:\n", ++cases);
	}
	return 0;
}