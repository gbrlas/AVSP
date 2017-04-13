#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <fstream>
#include <ext/hash_map>
// C++ Big Integer Library
// http://mattmccutchen.net/bigint/
//#include "BigIntegerLibrary.hh"


using namespace std;
using namespace __gnu_cxx;

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

typedef pair<int, int> PII;
typedef long long LL;
typedef vector<vector<int> > VII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef vector<vector<double> > VVD;

int D, I, M, N;

const int INF = (1 << 23);

int dp[200][1000];
int val[200];

int solve(int at, int v) {
	if (at >= N)
		return 0;
	int &ret = dp[at][v];

	if (ret >= 0)
		return ret;
	ret = INF;

	ret = min(ret, D + solve(at + 1, v));
	if (abs(val[at] - v) <= M)
		ret = min(ret, solve(at + 1, val[at]));
	for (int i = max(v - M, 0); i <= min(255, v + M); ++i) {
		int c = abs(val[at] - i);
		ret = min(ret, c + solve(at + 1, i));
		ret = min(ret, I + solve(at, i));
	}
//	cout << at << " " << v << ": " << ret << endl;
	return ret;
}


void runCase(int caseNum) {
	cin >> D >> I >> M >> N;
	memset(dp, 0xff, sizeof(dp));
	memset(val, 0, sizeof(val));
	for (int i = 0; i < N; ++i) {
		int v;
		cin >> v;
		val[i] = v;
	}

	int res = INF;
	for (int i = 0; i <= 255; ++i) {
		res = min(res, solve(0, i));
	}

	cout << "Case #" << caseNum << ": " << res << endl;
}

int main(int argc, char* argv[])
{
#ifdef __TSUN
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
		runCase(i + 1);

//	runCase(0);

#ifdef __TSUN
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}

