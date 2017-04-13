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
using namespace tr1;
#define int64 long long
const int MAX_N = 1000000;
bool notP[MAX_N];
int prime[MAX_N], primeCnt;
int K, D, num[10];


int mod_inverse(int A, int p)
{
	int a, b, q, t, x, y;
	a = p;
	b = A;
	x = 1;
	y = 0;
	while (b != 0)
	{
		t = b;
		q = a/t;
		b = a - q*t;
		a = t;
		t = x;
		x = y - q*t;
		y = t;
	}
	return (y < 0) ? y+p : y;
}

int solve() {
	if (K == 1)
		return -1;
	if (num[0] == num[1])
		return num[0];
	if (K == 2)
		return -1;
	int max_num = 0;
	for (int i = 0; i < K; ++i)
		max_num = max(max_num, num[i]);
	int ans_cnt = 0, ans = 0, limit = (int)floor(pow(10.0, D) + 1e-9);
	for (int i = 0; i < primeCnt && ans_cnt != 2; ++i) {
		if (prime[i] > max_num && prime[i] <= limit) {
			int cur = prime[i];
			int prod = (num[2] - num[1] + cur) % cur;
			int left = (num[1] - num[0] + cur) % cur;
			int a = ((int64)mod_inverse(left, cur) * prod) % cur;
			int b = ((((int64)num[1] - (int64)num[0] * a) % cur) + cur) % cur;
			bool fail = false;
			for (int j = 0; j + 1 < K; ++j) {
				if (((int64)a * num[j] + b) % cur != num[j + 1]) {
					fail = true;
					break;
				}
			}
			if (!fail) {
				int go = ((int64)a * num[K - 1] + b) % cur;
				if (ans_cnt == 0)
					ans_cnt = 1, ans = go;
				else if (ans != go) {
					ans_cnt = 2;
					break;
				}
			}
		}
	}
	return ans_cnt >= 2 ? -1 : ans;
}

int main() {
	primeCnt = 0;
	memset(notP, 0, sizeof(notP));
	for (int i = 2; i < MAX_N; ++i)
		if (!notP[i]) {
			prime[primeCnt++] = i;
			for (int j = i + i; j < MAX_N; j += i)
				notP[j] = true;
		}
//	freopen("A.in","r",stdin);
	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d %d", &D, &K);
		for (int i = 0; i < K; ++i)
			scanf("%d", &num[i]);
		printf("Case #%d: ", t);
		int ans = solve();
		if (ans == -1)
			printf("I don't know.\n");
		else
			printf("%d\n", ans);
	//	cerr << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}

