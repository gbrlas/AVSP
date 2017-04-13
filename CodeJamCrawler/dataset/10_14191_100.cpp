#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

const int L = 1000000;
//int t[L + 1][L + 1];
int lim[L + 1];
queue< pair<int, int> > q;

int main() {
	for (int i = 1; i <= L; ++i)
		lim[i] = i - 1;
	for (int i = 1; i <= L; ++i) {
		while (q.front().first < i)
			q.pop();
		if (!q.empty())
			lim[i] <?= q.front().second;
		q.push(make_pair(i + lim[i], i - 1));
	}
//	freopen("C.in","r",stdin);
	freopen("C-small-attempt0.in","r",stdin);  freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int A0, A1, B0, B1;
		scanf("%d %d %d %d", &A0, &A1, &B0, &B1);
		long long ans = 0;
		for (int i = A0; i <= A1; ++i)
			for (int j = B0; j <= B1; ++j) {
				int p = i, q = j;
				if (p > q)
					swap(p, q);
				if (q > p + lim[p])
					++ans;
			}
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}


