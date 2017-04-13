#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double EPS = 1e-7;

#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())

const int MAXN = 100;
const int MAXSIZE = 1000000;
int N;
int data[MAXN+5];
int memo[MAXSIZE+5][MAXN+5];
inline int DP(int size, int x) {
	if (memo[size][x] != -1) return memo[size][x];
	int &ret = memo[size][x];
	ret = 0;
	if (x >= N) ret = 0;
	else if (data[x] >= size) {
		ret = 1 + DP(size, x + 1);
		if (size != 1) ret = min(ret, 1 + DP(size+size-1, x));
	}
	else {
		ret = DP(min(size + data[x], MAXSIZE), x+1);
	}
	return ret;
}
inline void solve(int tc) {
	int A;
	scanf("%d %d", &A, &N);
	REP(i, N) scanf("%d", &data[i]);
	sort(data, data + N);
	memset(memo, -1, sizeof memo);
	printf("Case #%d: %d\n", tc, DP(A, 0));
}

int main() {
	int T;
	scanf("%d", &T);
	REP(i, T) solve(i+1);
	return 0;
}
