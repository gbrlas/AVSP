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

int m, n; 
string arr[10];
int server[10];
const int mod = 1000 * 1000 * 1000 + 7;

int calcNodes(int id) {
    //E("======================="); Eo(id);
    vector<string> s;
    for (int i = 0; i < m; ++i) if (server[i] == id) {
        s << arr[i];
        //Eo(arr[i]);
    }
    if (!Sz(s)) return -1;
    sort(All(s));
    int res = 1 + Sz(s[0]);
    for (int i = 1; i < Sz(s); ++i) {
        int t = 0;
        for (; t < Sz(s[i]) && t < Sz(s[i-1]) && s[i][t] == s[i-1][t]; ++t) { }
        --t;
        res += Sz(s[i]) - t - 1;
    }
    //Eo(res);
    return res;
}

int resval, rescnt;
void go(int id) {
    if (id == m) {
        int t = 0;
        for (int i = 0; i < n; ++i) {
            int q = calcNodes(i);
            if (q == -1) return ;
            t += q;
        }
        if (t > resval) {
            rescnt = 1;
            resval = t;
        } else if(t == resval) {
            ++rescnt;
        }
        rescnt %= mod;
        return ;
    }

    for (server[id] = 0; server[id] < n; ++server[id]) go(id + 1);
}

int main() {
	ios_base::sync_with_stdio(false);

    int TS; cin >> TS;
    for (int T = 1; T <= TS; ++T) {
        cin >> m >> n;
        for (int i = 0; i < m; ++i) {
            cin >> arr[i];
        }

        resval = rescnt = 0;
        go(0);
        cout << "Case #" << T << ": " << resval << ' ' << rescnt << endl;
    }

	return 0;
}
