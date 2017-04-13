#include <stdio.h>
#include <string.h>

int a[105];
int r[50][50];
int f[50][50];
char s[1000];
int cur;

void check()
{
	for (int i = cur - 2; i >= 0; i--)
	{
		int x = a[cur - 1], y = a[i];
		if (r[x][y] || r[y][x])
		{
			cur = 0;
			break;
		}
	}
}
int main ()
{
//	freopen("B-small-attempt1.in", "r", stdin);
//	freopen("B-small-attempt1.out", "w", stdout);
	int cas;
	scanf("%d", &cas);
	int c, d, n;
	for (int ca = 1; ca <= cas; ca++)
	{
		memset(f, -1, sizeof(f));
		scanf("%d", &c);		
		for (int i = 0; i < c; i++)
		{
			scanf("%s", s);
			f[s[0] - 'A'][s[1] - 'A'] = f[s[1] - 'A'][s[0] - 'A'] = s[2] - 'A';			
		}
		memset(r, 0, sizeof(r));
		scanf("%d", &d);
		for (int i = 0; i < d; i++)
		{
			scanf("%s", s);
			r[s[0] - 'A'][s[1] - 'A'] = r[s[1] - 'A'][s[0] - 'A'] = 1;
		}
		scanf("%d", &n);
		scanf("%s", s);
		cur = 0;
		a[cur++] = s[0] - 'A';
		for (int i = 1; i < n; i++)
		{
			a[cur++] = s[i] - 'A';
			int ss = -1;
			if (f[a[cur - 1]][a[cur - 2]] != -1) ss = f[a[cur - 1]][a[cur - 2]];
			else if (f[a[cur - 2]][a[cur - 1]] != -1) ss = f[a[cur - 2]][a[cur - 1]];
			if (ss != -1)
			{
				cur -= 2;
				a[cur++] = ss;
				check();
				continue;
			}
			check();
		}
		printf("Case #%d: [", ca);
		for (int i = 0; i < cur; i++)
		{
			printf("%c", 'A' + a[i]);
			if (i != cur - 1) printf(", ");
		}
		printf("]\n");
	}
	return 0;
}
