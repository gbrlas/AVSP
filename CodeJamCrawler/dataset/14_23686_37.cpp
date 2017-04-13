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

const int maxn = 100500 * 10;

int64 arr[maxn];
int64 sum[maxn];

int main() {
    // static_assert(sizeof(long) == 8, "32-bit !!! :'(");
    // FREOPEN("a");
    ios_base::sync_with_stdio(false);

    int TS; cin >> TS;
    for (int T = 1; T <= TS; ++T) {
        int n; cin >> n;
        int64 p, q, r, s; cin >> p >> q >> r >> s;
        for (int i = 0; i < n; ++i) arr[i] = (p * i + q) % r + s;

        sum[0] = arr[0];
        sum[n] = arr[n] = 0;
        for (int i = 1; i < n; ++i) sum[i] = sum[i-1] + arr[i];
        //Eo(sum[n-1]);

        int64 res = 0;
        int64 cumsum = 0;
        for (int i = n; i >= 0; --i) {
            cumsum += arr[i];
            if (i) {
                auto it = lower_bound(sum, sum + i, sum[i-1]/2);
                int id = it - sum;
                for (int j = max(0, id - 2); j < min(i, id + 3); ++j) {
                    int64 c = cumsum;
                    int64 a = sum[j];
                    int64 b = sum[i-1] - a;
                    int64 cres = max(a, max(b, c));
                    //E(i); E(a); E(b); E(c); E(cres); Eo(sum[n-1] - cres);
                    res = max(res, sum[n-1] - cres);
                }
            }
        }

        printf("Case #%d: %.20lf\n", T, double(res) / sum[n-1]);
    }

    return 0;
}
