#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 1003;
double naomi[maxn];
double ken[maxn];

int main()
{
	int t, n;

	freopen("D-large.in", "r", stdin);
	freopen("outD-large.txt", "w", stdout);

	scanf("%d", &t);
	for(int cas = 1; cas <= t; ++cas) {

		scanf("%d", &n);

		for(int i = 0; i < n; ++i)
			scanf("%lf", &naomi[i]);

		for(int i = 0; i < n; ++i)
			scanf("%lf", &ken[i]);

		sort(naomi, naomi + n);
		sort(ken, ken + n);

		int xa = 0, xb = 0, yb = n - 1;
		int cheat_ans = 0;

		for(int i = 0; i < n; ++i) {
			if(naomi[xa]  > ken[xb]) {
				cheat_ans++;
				xa++; xb++;
			}
			else {
				xa++;
				yb--;
			}
		}


		int ha = 0, ta = n - 1, hb = 0, tb = n - 1;
		int ans = 0;

		for(int i = 0; i < n; ++i) {
			if (ken[ha] > naomi[hb]) {
				ans++;
				ha++;hb++;
			}
			else if (ken[ta] > naomi[tb]) {
				ans++;
				ta--;tb--;
			}
			else {
				ha++;
				tb--;
			}
		}

		printf("Case #%d: %d %d\n", cas, cheat_ans, n - ans);
	}

	return 0;
}