#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cassert>

#include <iostream>
#include <sstream>
#include <iterator>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <list>
#include <complex>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

const double PI = atan(1.0) * 4;
const int inf = 1000000009;
const double eps = 1e-8;

#define F0(i, n) for (int i = 0; i < (n); ++i)
#define F1(i, n) for (int i = 1; i <= (n); ++i)
#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

using namespace std;

const int M = 10007;

int main() {
    int caseN;
    scanf("%d", &caseN);

    // TODO: check long long carefully.
    for (int cas = 1; cas <= caseN; ++cas) {
	printf("Case #%d: ", cas);

	ll H,W,R;
	cin >> H >> W >> R;
	ll rockr[R], rockc[R];
	bool isrock[H + 1][W + 1];
	ll count[H + 1][W + 1];
	F1(i, H)
	    F1(j, W) {
		isrock[i][j] = false;
		count[i][j] = 0;
	    }
	F0(i, R) {
	    cin >> rockr[i] >> rockc[i];
	    isrock[rockr[i]][rockc[i]] = true;
	}
	

	
	count[1][1] = 1;
	F1(i, H)
	    F1(j ,W) {
		if (isrock[i][j]) continue;
		if (i + 1 <= H && j + 2 <= W) {
		    count[i+1][j+2] += count[i][j];
		    count[i+1][j+2] %= M;
		}
		if (i + 2 <= H && j + 1 <= W) {
		    count[i+2][j+1] += count[i][j];
		    count[i+2][j+1] %= M;
		}
	    }
	cout << count[H][W];
	printf("\n");
    }

    return 0;
}
