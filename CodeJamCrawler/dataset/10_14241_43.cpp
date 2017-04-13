#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <complex>
#include <cassert>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include <string.h>
#include <limits.h>
#include <ctime>

using namespace std;

const int MAX_N = 110000;
#define int64 long long

int64 L, B[200];
int N;
int64 sum[MAX_N], cnt[MAX_N];
bool v[MAX_N];

int64 gcd(int64 a, int64 b) {
	if (a > b)
		swap(a, b);
	if (a == 0)
		return b;
	else
		return gcd(b % a, a);
}

priority_queue< pair<int64, int64> > q;
int64 solve() {
	sort(B, B + N);
	int64 g0 = B[0];
	for (int i = 1; i < N; ++i)
		g0 = gcd(g0, B[i]);
//	if (L % g0 != 0)
//		return -1;
	int64 length = B[N - 1];
	fill(v, v + length, 0);
	fill(cnt, cnt + length, INT_MAX);
	sum[0] = 0; cnt[0] = 0;
	while (!q.empty())
		q.pop();
	q.push(make_pair(0, 0));
	int pos = L % length;
	while (!q.empty() && !v[pos]) {
		pair<int64, int64> top;
		do {
			top = q.top(); q.pop();
		} while (v[top.second]);
		// cerr << top.first << " " << top.second << endl;
		int x = top.second;
		v[x] = true;
		for (int i = 0; i < N - 1; ++i) {
			int64 y = (x + B[i]) % length;
			if (sum[x] + B[i] > L)
				continue;
			int64 newCnt = cnt[x] + 1 - (sum[x] + B[i]) / length;
			if (!v[y] && (cnt[y] == INT_MAX || cnt[y] - (sum[y] / length) < newCnt)) {
				sum[y] = sum[x] + B[i];
				cnt[y] = cnt[x] + 1;
				q.push(make_pair(-newCnt, y));
			}
		}
	}
	if (v[pos])
		return cnt[pos] + (L - sum[pos]) / length;
	else
		return -1;
}

int main() {
//	freopen("B.in","r",stdin);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);  freopen("B-small-attempt1.bak.out","w",stdout);
	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin); freopen("B-large.out","w",stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> L >> N;
		for (int i = 0; i < N; ++i)
			cin >> B[i];
		int64 ans = solve();
		cout << "Case #" << t << ": ";
		if (ans == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}


