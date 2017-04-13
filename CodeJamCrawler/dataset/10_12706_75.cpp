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

map<PII, LL> dp;

int solve(int A, int B) {
	if (A == B)
		return 0;
	if (A > B)
		swap(A, B);
	if (B >= A + A)
		return 1;
	PII cur = pair<int, int>(A, B);
	if (dp.count(cur))
		return dp[cur];
	int ret = 0;
	if (!solve(B - A, A)) {
		ret = 1;
	}
	dp[cur] = ret;
	//cout << A << ", " << B << " : " << ret << endl;
	return ret;
}


void runCase(int caseNum) {
	int A1, A2, B1, B2;
	cin >> A1 >> A2 >> B1 >> B2;
	if (A2 > B2) {
		swap(A1, B1);
		swap(A2, B2);
	}
	LL ret = 0;
	for (int i = A1; i <= A2; ++i) {
		for (int j = B1; j <= B2; ++j) {
			if (solve(i, j))
				++ret;
		}
	}
	cout << "Case #" << caseNum << ": " << ret << endl;
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

