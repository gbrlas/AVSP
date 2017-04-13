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

const int MAX_N = 10000;
int data[MAX_N + 5];
int tc;
void solve() {
	int N, X;
	scanf("%d %d", &N, &X);
	REP(i, N) scanf("%d", &data[i]);
	
	sort(data, data + N);
	int ak = N-1;
	int ans = 0;
	//printf("ak = %d\n", ak);
	for (int aw = 0; aw <= ak; aw++) {
		while(ak >= aw && data[aw] + data[ak] > X) {
			ak--;
			ans++;
		}
		if (ak < aw) break;
		ans++;
		ak--;
		
		//printf("Aw = %d ak = %d\n", aw, ak);
	}
	printf("Case #%d: %d\n", tc, ans);
}

int main() {
	int T;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) solve();
	return 0;
}
