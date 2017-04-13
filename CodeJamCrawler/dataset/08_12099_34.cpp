#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <complex>
#include <ext/hash_map>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;
using namespace __gnu_cxx;

typedef complex<double> Point;

const int MAX_N = 5000 + 10;

int cases, caseNo, n, f[MAX_N][3];

int ptCnt, cnt[10001];
pair<int, int> pt[MAX_N];

bool ptComp(const pair<int, int> & a, const pair<int, int> & b)
{
	return a.first == b.first ? a.second > b.second : a.first < b.first;
}

int solve()
{
	int ans = 0;
	for (int a = 0; a <= 10000; ++a)
	{
		ptCnt = 0;
		int left = 10000 - a, ptr = 0, c = left, cur_ans = 0;
		for (int i = 0; i < n; ++i)
			if (f[i][0] <= a && f[i][1] <= left && f[i][2] <= left)
				pt[ptCnt++] = make_pair(f[i][1], f[i][2]);
		if (ptCnt <= ans)
			continue;
		sort(pt, pt + ptCnt, ptComp);
		memset(cnt, 0, sizeof(cnt));
		for (int b = 0; b <= left; ++b)
		{
			while (ptr < ptCnt && pt[ptr].first == b) {
				if (pt[ptr].second <= c) {
					++cnt[pt[ptr].second];
					cur_ans += 1;
				}
				++ptr;
			}
			if ( b + c > left) {
				cur_ans -= cnt[c];
				--c;
			}
			ans >?= cur_ans;
		}
		//printf("left = %d (%d, %d)\n", left, ptr, ptCnt);
	}
	return ans;
}

int main()
{
	freopen("A0.in", "r", stdin);
	freopen("A0.out", "w", stdout);

	scanf("%d", &cases);

	for (int caseNo = 1; caseNo <= cases; ++caseNo)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d %d %d", &f[i][0], &f[i][1], &f[i][2]);
		printf("Case #%d: %d\n", caseNo, solve());
	}
	return 0;
}

