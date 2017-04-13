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

const int RC = 4;

int grid[RC + 5][RC + 5];
int possible[20];

void solve(int tc) {
	memset(possible, 0, sizeof possible);
	
	int ans;
	scanf("%d", &ans);
	REP(i, RC) REP(j, RC) scanf("%d", &grid[i][j]);
	
	REP(j, RC) possible[grid[ans-1][j]]++;
	
	scanf("%d", &ans);
	REP(i, RC) REP(j, RC) scanf("%d", &grid[i][j]);
	
	REP(j, RC) possible[grid[ans-1][j]]++;
	
	vector<int> twice;
	FOR(i, 1, 16) if (possible[i] == 2) twice.PB(i);
	
	printf("Case #%d: ", tc);
	if (SZ(twice) == 1) printf("%d\n", twice[0]);
	else if (SZ(twice) == 0) puts("Volunteer cheated!");
	else puts("Bad magician!");
}

int main() {
	int T;
	scanf("%d", &T);
	REP(i, T) solve(i+1);
	return 0;
}
