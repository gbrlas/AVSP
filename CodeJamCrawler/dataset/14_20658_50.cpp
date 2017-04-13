#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;

#define MAXN 1010
#define INF 2100000000

int T, tt = 0;
int n, a[MAXN];

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while (T--){
		printf("Case #%d: ", (++tt));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		int last = 0;
		int ans = 0;
		for (int i = 0; i < n; ++i){
			int m = INF, index, p;
			int s = 0;
			for (int j = 0; j < n; ++j)
				if (a[j] > last){
					if (m > a[j]) { m = a[j]; index = j; p = s;}
					s++;
					}
			//cout << m << " " << index << " " << p << " " << n-1-i-p << endl;
			ans += min(p, n-1-i-p);
			last = a[index];
			}
		printf("%d\n", ans);
		}
	return 0;
	}
