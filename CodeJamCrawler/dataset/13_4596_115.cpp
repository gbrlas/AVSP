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

bool check(LL x) {
    string s = i2s(x);
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[n-i-1]) return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;

    unordered_map<LL, bool> S;
    for (LL i = 1; i <= 1e7; ++i) {
        LL j = i * i;
        if (check(i) && check(j)) {
            S[j] = true;
        }
    }

    FOR(t, 1, T) {
        LL A, B;
        cin >> A >> B;

        int ret = 0;

        for (auto it = S.begin(); it != S.end(); ++it) {
            if (it->second && A <= it->first && it->first <= B) {
                ++ret;
            }
        }

        printf("Case #%d: %d\n", t, ret);
    }

    return 0;
}
