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
typedef pair<int, int> pip;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const flt eps = 1e-8;
const flt pi = acos(-1.0);
const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };



int main() {
	ios_base::sync_with_stdio(false);

    int T; cin >> T;
    for (int test = 1; test <= T; ++test) {
        int n; cin >> n;
        int x; cin >> x;
        multiset<int> s;
        for (int i = 0; i < n; ++i) {
            int t; cin >> t;
            s.insert(t);
        }
        int res = 0;
        while (s.size() > 1) {
            auto it = s.end(); --it;
            int a = *it;
            s.erase(it);
            int have = x - a;

            it = s.upper_bound(have);
            if (it != s.begin()) --it;
            int give = *it;
            if (give <= have) {
                s.erase(it);
            }
            ++res;
        }
        res += s.size() % 2;
        cout << "Case #" << test << ": " << res << endl;
    }

	return 0;
}
