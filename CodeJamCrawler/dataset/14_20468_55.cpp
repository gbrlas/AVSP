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

const int MAX_N = 1000;

double p1[MAX_N + 5];
double p2[MAX_N + 5];

bool used[MAX_N + 5];
void solve(int tc) {
	int N;
	scanf("%d", &N);
	REP(i, N) scanf("%lf", &p1[i]);
	REP(i, N) scanf("%lf", &p2[i]);
	
	sort(p1, p1 + N);
	sort(p2, p2 + N);
	
	//REP(i, N) printf("%lf, ", p1[i]); puts("");
	//REP(i, N) printf("%lf, ", p2[i]); puts("");
	
	int warWin = 0;
	memset(used, 0, sizeof used);
	REP(i, N) {
		int j = 0;
		while( j < N && (used[j] || p2[j] < p1[i]) ) j++;
		if (j >= N) warWin++;
		else used[j] = true;
	}
	
	int decWin = 0;
	int p2idx = 0;
	REP(i, N) if (p1[i] > p2[p2idx]) decWin++, p2idx++;
	
	printf("Case #%d: %d %d\n", tc, decWin, warWin);
}

int main() {
	int T;
	scanf("%d", &T);
	REP(i, T) solve(i+1);
	return 0;
}
