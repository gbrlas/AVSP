#include <bits/stdc++.h>
using namespace std;

#ifdef ILIKEGENTOO
#   define Eo(x) { cerr << #x << " = " << (x) << endl; }
#   define E(x) { cerr << #x << " = " << (x) << "   "; }
#   define FREOPEN(x)
#else
#   define Eo(x)
#   define E(x)
#   define FREOPEN(x) (void)freopen(x ".in", "r", stdin);(void)freopen(x ".out", "w", stdout);
#endif
#define EO(x) Eo(x)
#define Sz(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()

template<class A, class B> ostream &operator<<(ostream &os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

template<class C> void operator<<(vector<C> &v, const C &x){v.push_back(x);}
template<class D> void operator>>(vector<D> &v, D &x){assert(!v.empty()); x=v.back(); v.pop_back();}
template<class E> void operator<<(set<E> &v, const E &x){v.insert(x);}
template<class F> void operator<<(queue<F> &c, const F& v){v.push(v);}
template<class G> void operator>>(queue<G> &c, const G& v){const G r=v.front();v.pop();return r;}

typedef double flt;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const flt eps = 1e-8;
const flt pi = acos(-1.0);
const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

const int maxn = 105;
const int maxh = 202;

int dp[maxn][maxn * maxh];
int h[maxn], g[maxn];

int main() {
    // static_assert(sizeof(long) == 8, "32-bit !!! :'(");
    // FREOPEN("b");
    ios_base::sync_with_stdio(false);

    int TS; cin >> TS;
    for (int T = 1; T <= TS; ++T) {
        int p, q, n;
        cin >> p >> q >> n;
        for (int i = 0; i < n; ++i) cin >> h[i] >> g[i];
        memset(dp, 0xc0, sizeof(dp));

        dp[0][1] = 0;
        int res = 0;
        for (int i = 0; i <= n; ++i) for (int j = 0; j < maxn * maxh; ++j) if (dp[i][j] >= 0) {
            res = max(res, dp[i][j]);
            if (i == n) continue;

            for (int shot_tower = 0; ; ++shot_tower) {
                int hp = h[i] - shot_tower * q;
                if (hp <= 0) {
                    int& t = dp[i + 1][j + shot_tower];
                    t = max(t, dp[i][j]);
                    break;
                }
                
                int req = (hp + p - 1) / p;
                int have = shot_tower + j;
                if (have >= req) {
                    int ost = have - req;
                    int& t = dp[i + 1][ost];
                    t = max(t, dp[i][j] + g[i]);
                }
            }
        }

        cout << "Case #" << T << ": " << res << endl;
    }

    return 0;
}
