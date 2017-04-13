#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i, n) for (int (i)=0; (i)<(n); (i)++)
#define DFOR(i, n) for (int (i)=(n)-1; (i)>=0; (i)--)
#define ALL(x) (x).begin(), (x).end()
#define SZ(s) (s).size()
#define SQR(x) ((x)*(x))
#define CLR(a) memset(a,0,sizeof(a))
#define OO 1000000000

long T;
long X, Y, R;
long dp[128][128];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);
	FOR(a, T)
	{
		CLR(dp);
		scanf("%d%d%d", &X, &Y, &R);
		long xxx, yyy;
		dp[0][0]=1;
		FOR(b, R)
		{
			scanf("%d%d", &xxx, &yyy);
			if (!(xxx==X && yyy==Y)) dp[xxx-1][yyy-1]=-1;
		}
		FOR(b, X) FOR(c, Y)
			if (dp[b][c]!=-1)
			{
				if (b-1>=0 && c-2>=0)
					if (dp[b-1][c-2]!=-1) dp[b][c] += dp[b-1][c-2];
				if (b-2>=0 && c-1>=0)
					if (dp[b-2][c-1]!=-1) dp[b][c] += dp[b-2][c-1];
				if (dp[b][c] > 10007) dp[b][c] -= 10007;
			}
		printf("Case #%d: %d\n", a+1, dp[X-1][Y-1]%10007);
	}

	return 0;
}