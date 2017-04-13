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

int dia[110][110];

void runCase(int caseNum) {
    int k;
    cin >> k;
    memset(dia, 0xff, sizeof(dia));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= i; ++j)
            cin >> dia[i][k - 1 - i + 2 * j];
    }
    for (int i = k; i < 2 * k - 1; ++i) {
        for (int j = 0; j < 2 * k - i - 1; ++j) {
            cin >> dia[i][i - k + 1  + 2 * j];
        }
    }

//  for (int i = 0; i < 2 * k ; ++i) {
//      for (int j = 0; j < 2 * k; ++j) {
//          cout << dia[i][j] << " ";
//      }
//      cout << endl;
//  }
//  cout << endl;

    int res = 100;

    for (int cx = 0; cx < 2 * k - 1; ++cx) {
        for (int cy = 0; cy < 2 * k - 1; ++cy) {
            //cout << cx << " " << cy << endl;
            bool OK = true;
            for (int y = 0; y < 2 * k - 1; ++y) {
                int lim = 0;
                if (cx < k - 1) {
                    lim = cx - abs(k - 1 - y);
                } else
                    lim = (2 * k - 2 - abs(k - 1 - y)) - cx;
                for (int i = 1; i <= lim ; ++i) {
                    //cout << "x check: " << cx + i << " " << cx - i << " " << y << endl;
                    if (dia[y][cx + i] != dia[y][cx - i]) {
                        //cout << "x bad: " << cx + i << " " << cx - i << " y: " << y << endl;
                        OK = false;
                        break;
                    }
                }
                if (!OK)
                    break;
            }
            for (int x = 0; x < 2 * k - 1; ++x) {
                int lim = 0;
                if (cy < k - 1) {
                    lim = cy - abs(k - 1 - x);
                } else
                    lim = (2 * k - 2 - abs(k - 1 - x)) - cy;
                for (int i = 1; i <= lim; ++i) {
                    if (dia[cy + i][x] != dia[cy - i][x]) {
                        //cout << "y bad";
                        OK = false;
                        break;
                    }
                }
                if (!OK)
                    break;
            }
            if (OK) {
                //cout << cx << " " << cy << endl;
                res = min(res, abs(k - 1 - cx) + abs(k - 1 - cy));
            }
        }
    }

    int r = (k + res) * (k + res + 1) / 2 + (k + res) * (k + res - 1) / 2
        - k * (k + 1) / 2 - k * (k - 1) / 2;

        cout << "Case #" << caseNum << ": " << r << endl;
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
