#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

typedef long long LL;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define MAXN 1005
LL n, p;
int main()
{
	int T, cases = 0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++cases);
		scanf("%lld%lld", &n, &p);
		LL tmp = 1LL << n, ans1;
		if (tmp == LL(p)) {
			ans1 = tmp - 1;
		} else {
			ans1 = 0;
			tmp = 1LL << (n - 1);
			for (int i = n - 1; i >= 0; --i) {
				if (tmp >= p) {
					break;
				}
				ans1 += 1LL << (n - i);
				tmp += 1LL << (i - 1);
			}
		}
		LL ans2 = 0;
		tmp = 1;
		for (int i = n - 1; i >= 0; --i) {
			if (tmp * 2 > p) {
				break;
			} else {
				ans2 += 1LL << i;
				tmp *= 2;
			}
		}
		printf("%lld %lld\n", ans1, ans2);
	}
	return 0;
}

