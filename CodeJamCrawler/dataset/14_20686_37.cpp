#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;

#define MAXN 110
#define MAXM 1010
#define LL long long

int T, tt = 0;
int g[MAXN], h[MAXN], p, q, n;
int f[MAXN][MAXM][MAXM];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--){
		printf("Case #%d: ", (++tt));
		scanf("%d%d%d", &p, &q, &n);
		for (int i = 1; i <= n; ++i) scanf("%d%d", &h[i], &g[i]);
		memset(f, 200, sizeof(f));
		f[0][0][0] = 0;
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			{
				int t = 0, d = 0, u = 0;
				if (h[i]%q) {
					t = h[i] / q;
					u = t + 1;
					h[i] %= q;
					d = (h[i]-1)/p+1;
					}else{
						u = h[i] / q;
						t = u - 1;
						d = (q - 1) / p + 1;
						}
				for (int j = 0; j < MAXM-1; ++j)
					for (int k = 0; k <= j+1; ++k){
						if (j >= t && k >= d)
							f[i][j][k] = max(f[i][j][k], f[i-1][j-t][k-d]+g[i]);
						if (j >= u)
							f[i][j][k] = max(f[i][j][k], f[i-1][j-u][k]);
						if (i == n) ans = max(ans, f[i][j][k]);
				//		if (f[i][j][k] >= 0) cout << i << " " << j << " " << k << " " << f[i][j][k] << endl;
					}
				}
		cout << ans << endl;
		}
	return 0;
	}
