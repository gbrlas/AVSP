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
//	freopen("C-small-attempt0.in","r",stdin);  freopen("C-small-attempt0.out2","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int A0, A1, B0, B1;
		scanf("%d %d %d %d", &A0, &A1, &B0, &B1);
		long long ans = 0;
		while (A0 != B0 && B0 <= B1 && A0 <= A1) {
		//	long long olf = ans;
			if (B0 < A0) {
				if (A0 > B0 + lim[B0] || A1 < B0 - lim[B0])
					ans += A1 - A0 + 1;
				else if (A0 < B0 - lim[B0] && A1 > B0 + lim[B0])
					ans += A1 - A0 + 1 - lim[B0] * 2 - 1;
				else if (A1 > B0 + lim[B0])
					ans += A1 - B0 - lim[B0];
				else if (A0 < B0 - lim[B0])
					ans += B0 - lim[B0] - A0;
				++B0;
			} else {
				if (B0 > A0 + lim[A0] || B1 < A0 - lim[A0])
					ans += B1 - B0 + 1;
				else if (B0 < A0 - lim[A0] && B1 > A0 + lim[A0])
					ans += B1 - B0 + 1 - lim[A0] * 2 - 1;
				else if (B1 > A0 + lim[A0])
					ans += B1 - A0 - lim[A0];
				else if (B0 < A0 - lim[A0])
					ans += A0 - lim[A0] - B0;
				++A0;
			}
		//	printf("diff = %lld\n", ans - olf);
		}
		while (B0 <= B1 && A0 <= A1) {
			ans += max(0, B1 - B0 - lim[B0]) + max(0, A1 - A0 - lim[A0]);
			++B0; ++A0;
		}
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}


