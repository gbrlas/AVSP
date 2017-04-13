#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iterator>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define FOREACH(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALL(c) (c).begin(), (c).end()
#define FILL(a, b) memset(a, b, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define SZ(c) ((int)(c).size())
#define X(p) (p).first
#define Y(p) (p).second
#define debug(x) cerr << #x << " = " << x << "\n";
#define debugv(v) cerr << #v << " = "; FOREACH(it, v) cerr << *it << ",\n";

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef pair<string, string> PSS;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;

const double eps = 1e-6;
const int inf = 1000000001;
const LL infll = LL(inf) * LL(inf);
const double PI = 4 * atan(1.0);
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> string i2s(T x) { ostringstream ss; ss << x; return ss.str(); }
int s2i(string s) { istringstream ss(s); int x; ss >> x; return x;}
LL s2ll(string s) { istringstream ss(s); LL x; ss >> x; return x;}
inline double dist(double x1, double y1, double x2, double y2) { return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); }

int a[111][111];

bool check(int n, int m, int x, int y) {
    bool flag = true;
    REP(i, n) flag &= a[x][y] >= a[i][y];
    if (flag) return true;

    flag = true;
    REP(i, m) flag &= a[x][y] >= a[x][i];

    return flag;
}

int main() {
    int T;
    cin >> T;

    FOR(t, 1, T) {
        int n, m;
        cin >> n >> m;

        FILL(a, 0);

        set<int> S;
        REP(i, n) REP(j, m) {
            cin >> a[i][j];
            S.insert(a[i][j]);
        }

        for (auto it = S.begin(); it != S.end(); ++it) {
            REP(i, n) REP(j, m) if (a[i][j] == *it) {
                if (!check(n, m, i, j)) {
                    printf("Case #%d: NO\n", t);
                    goto Next;
                }
            }
        }

        printf("Case #%d: YES\n", t);

    Next:
        ;
    }

    return 0;
}

