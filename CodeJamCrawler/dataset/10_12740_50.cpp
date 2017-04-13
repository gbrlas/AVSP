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

int mp[2][200][200];

void runCase(int caseNum) {
    memset(mp, 0, sizeof(mp));

    int R;
    cin >> R;

    for (int i = 0; i < R; ++i) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x <= x2; ++x){
            for (int y = y1; y <= y2; ++y){
                mp[0][y - 1][x - 1] = 1;
            }
        }
    }

    int res = 0;
    int pre = 0, cur = 1;
    while (1) {
        ++res;
        int cnt = 0;

        memset(mp[cur], 0, sizeof(mp) / 2);
        for (int i = 1; i < 200; ++i) {
            for (int j = 1; j < 200; ++j) {
                if (mp[pre][i][j])
                    continue;
                if (mp[pre][i - 1][j] && mp[pre][i][j - 1]) {
                    mp[cur][i][j] = 1;
                    ++cnt;
                }
            }
        }

        for (int i = 0; i < 200; ++i) {
            for (int j = 0; j < 200; ++j) {
                if (!mp[pre][i][j])
                    continue;
                if ((i > 0 && mp[pre][i - 1][j]) || (j > 0 && (mp[pre][i][j - 1]))) {
                    mp[cur][i][j] = 1;
                    ++cnt;
                }
            }
        }
        if (cnt == 0)
            break;
        swap(cur, pre);
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

	//runCase(0);

#ifdef __TSUN
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
//a
