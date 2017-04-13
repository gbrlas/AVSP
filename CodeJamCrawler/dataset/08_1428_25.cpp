#include <stdio.h>
#include <string.h>

char s[50001];
int res, k, l;
int p[20];
int used[20];

int min(int a, int b) { return a<b?a:b; }

void track(int d)
{
	if (d >= k)
	{
		int i, r;
		int cnt = 0;
		char prev = 0;
		for (r=i=0; i<l; i++, r = (r+1)%k) if (s[(i/k)*k + p[r]] != prev) { cnt++; prev = s[(i/k)*k + p[r]]; }
		res = min(cnt, res);
		return;
	} 
	for (int i=0; i<k; i++) if (!used[i])
	{
		p[d] = i;
		used[i] = 1;
		track(d+1);
		used[i] = 0;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int c=1; c<=n; c++)
	{
		scanf("%d", &k);
		scanf("%s", s);
		l = strlen(s);
		res = l;
		track(0);
		printf("Case #%d: %d\n", c, res);
	}
	return 0;
}
