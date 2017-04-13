#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;

#define MAXN 1000010
#define LL long long

int T, tt = 0;
int n, p, q, r, s;
LL a[MAXN], f[MAXN];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--){
		printf("Case #%d: ", (++tt));
		scanf("%d%d%d%d%d", &n, &p, &q, &r, &s);
		for (LL i = 1; i <= n; ++i) a[i] = ((i-1) * p + q) % r + s;
		f[0] = 0;
		for (int i = 1; i <= n; ++i) f[i] = f[i-1] + a[i];
		LL ans = (LL)1e12;
		for (int i = 1; i <= n; ++i){
			int l = i, r = n;
			while (l < r){
				int mid = (l + r) / 2;
				if (f[mid] - f[i-1] < f[n] - f[mid]) l = mid + 1;
				else r = mid;
				}
			LL m = max(max(f[i-1], f[l]-f[i-1]), f[n]-f[l]);
			ans = min(ans, m);
			m = max(max(f[i-1], f[l-1]-f[i-1]), f[n]-f[l-1]);
			ans = min(ans, m);
			}
		//cout << ans << " " << f[n] << endl;
		printf("%.10lf\n", 1.0*(f[n]-ans)/f[n]);
		}
	
	
	
	return 0;
	}
