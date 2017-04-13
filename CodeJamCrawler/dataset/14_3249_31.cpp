#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

int n,x;
int a[10005];

int main() {
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int Ts;
	scanf("%d",&Ts);
	for(int cs=1;cs<=Ts;++cs) {
		printf("Case #%d: ", cs);

		scanf("%d%d",&n,&x);
		for(int i=0;i<n;++i) scanf("%d",a+i);
		sort(a,a+n);
		if(n == 1) {
			printf("1\n");
			continue;
		}

		int s=0, e=n-1;
		int ans = 0;
		while(s <= e) {
			if(s < e && a[s] + a[e] <= x) {
				ans++, s++, e--;
				continue;
			}
			ans++, e--;
		} printf("%d\n", ans);
	}
}