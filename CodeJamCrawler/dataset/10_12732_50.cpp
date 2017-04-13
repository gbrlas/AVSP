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

const int INF = (1 << 28);
int dp[11][1100][11];
int P;

    vector<int> M;
    VII price;



int solve(int level, int node, int miss) {
    int &ret = dp[level][node][miss];
    if (ret >= 0)
        return ret;
    if (level == P - 1) {
        if (M[node * 2] >= miss + 1 && M[node * 2 + 1] >= miss + 1) {
            //cout << level << " " << node << " " << miss << ": 0!" << endl;
            return ret = 0;
        } else if (M[node * 2] >= miss && M[node * 2 + 1] >= miss) {
            ret = price[level][node];
            //cout << level << " " << node << " " << miss << ": !" << ret << endl;
            return ret;
        }
        return INF;
    }
    int a = solve(level + 1, node * 2, miss + 1);
    int b = solve(level + 1, node * 2 + 1, miss + 1);
    ret = a + b;
    if (ret >= INF)
        ret = INF;
    a = solve(level + 1, node * 2, miss);
    b = solve(level + 1, node * 2 + 1, miss);
    ret = min(ret, price[level][node] + a + b);
    if (ret > INF)
        ret = INF;
    //cout << level << " " << node << " " << miss << ": " << ret << endl;
    return ret;
}

void runCase(int caseNum) {
    cin >> P;
    M.clear();
    for (int i = 0; i < (1 << P); ++i) {
        int a;
        cin >> a;
        M.push_back(a);
    }

    price = VII(P, VI());
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < (1 << (P - 1 - i)); ++j) {
            int a;
            cin >> a;
            price[P - 1 - i].push_back(a);
        }
    }

    memset(dp, 0xff, sizeof(dp));

    int res = solve(0, 0, 0);
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

	//runCase(0);

#ifdef __TSUN
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
//a
