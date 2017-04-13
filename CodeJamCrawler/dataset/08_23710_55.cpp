#include <iostream>

using namespace std;
#define CLR(a) memset(a,0,sizeof(a))
#define OO 1000000000

long t, s, q;
char ch[128][128], que[128], c;
long dp[128][1024];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &t);
	for (long a = 0; a < t; a ++)
	{
		CLR(dp);
		CLR(ch);
		scanf("%d", &s);
		cin.get(c);
		for (long b = 0; b < s; b ++)
			gets(ch[b]);
		scanf("%d", &q);
		cin.get(c);
		for (long b = 0; b < q; b ++)
		{
			gets(que);
			long k=-1;
			for (long c = 0; c < s; c ++)
				if (strcmp(ch[c], que)==0)
				{ k = c; break; }
			if (k >= 0)
				for (long c = 0; c < s; c ++)
					if (c != k) dp[c][b+1] = min(dp[c][b], dp[k][b]+1);
					else dp[c][b+1] = OO;
		}
		long mn = OO;
		for (long b = 0; b < s; b ++)
			mn = min(mn, dp[b][q]);
		printf("Case #%d: %d\n", a+1, mn);
	}

	return 0;
}