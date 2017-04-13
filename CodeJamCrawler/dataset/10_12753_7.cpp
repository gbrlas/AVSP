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
#include "BigIntegerLibrary.hh"


using namespace std;
//using namespace __gnu_cxx;

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

typedef pair<int, int> PII;
typedef long long LL;
typedef vector<vector<int> > VII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef vector<vector<double> > VVD;

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);

    while (a % b) {
        a %= b;
        swap(a, b);
    }
    return b;
}

int dp[2100000];


void runCase(int caseNum) {
    BigInteger L;
    string s;
    int N;
    cin >> s >> N;
    L = stringToBigInteger(s);

    vector<int> b;
    int mx = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        b.push_back(a);
        mx = max(a, mx);
    }

    int g = b[0];
    for (int i = 1; i < N; ++i) {
        g = gcd(g, b[i]);
    }

//  int c = g;
//  for (int i = 0; i < N; ++i) {
//      c *= b[i] / g;
//      cout << b[i] / g << endl;
//  }

    //sort(ALL(b), greater<int>());

    int lim = 100000;

    memset(dp, 0xff, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < SZ(b); ++i) {
        for (int j = 0; j <= lim; ++j) {
            if (dp[j] >= 0) {
                if (dp[j + b[i]] < 0)
                    dp[j + b[i]] = dp[j] + 1;
                else
                    dp[j + b[i]] = min(dp[j + b[i]], dp[j] + 1);
            }
         }
    }

    BigInteger res = L * BigInteger(2);

    for (int i = 1; i <= lim; ++i) {
        if (dp[i] < 0)
            continue;
        BigInteger m = L % BigInteger(i);
        if (dp[m.toInt()] < 0)
            continue;
        BigInteger r = (L / BigInteger(i)) * BigInteger(dp[i]) + dp[m.toInt()];
        if (r < res) {
            res = r;
            //cout << res << " i: " << i << " m: " << m << endl;
        }
    }




    cout << "Case #" << caseNum << ": ";
    if (res > L)
        cout << "IMPOSSIBLE";
    else {
        cout << res;
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
#ifdef __TSUN
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    //preProcess();

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        runCase(i + 1);

//  runCase(0);

#ifdef __TSUN
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
//a

