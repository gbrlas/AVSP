#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <map>
#include <string>
#include <vector>
#include <set>
using namespace std;
int n,a[1020],l[1020],r[1020];
int main() {
	int T;
	scanf("%d" ,&T);
	for (int q = 1; q <= T; q++) {
		printf("Case #%d: ",q);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d",&a[i]);
		}
		memset(l, 0, sizeof l);
		memset(r, 0, sizeof r);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				if (a[j] > a[i]) {
					l[i]++;
				}
			}
			for (int j = i; j <=n; j++) {
				if (a[i] < a[j]) {
					r[i]++;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i<= n; i++) {
			ans += min(l[i], r[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

