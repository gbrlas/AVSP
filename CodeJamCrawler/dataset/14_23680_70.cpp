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

const int maxb = 1010;

int distrow (int al, int ar, int bl, int br) {
    if (al > bl)
        return distrow(bl, br, al, ar);
    else {
        return max(0, bl - ar - 1);
    }
}

struct Rect {
    int x0, y0, x1, y1;

    int dist (const Rect& o) const {
        return max(distrow(x0, x1, o.x0, o.x1), distrow(y0, y1, o.y0, o.y1));
    }
} rs[maxb];

vector<pii> g[maxb];

int dist[maxb];

struct dcmp {
    bool operator()(int a, int b) const {
        if (dist[a] != dist[b]) return dist[a] < dist[b];
        return a < b;
    }
};

void dijk(int start) {
    memset(dist, 0x3f, sizeof(dist));
    dist[start] = 0;
    set<int, dcmp> que;
    que.insert(start);
    while (Sz(que)) {
        int v = *que.begin();
        que.erase(que.begin());
        for (pii e : g[v]) {
            int u = e.first;
            int nd = dist[v] + e.second;
            if (nd < dist[u]) {
                que.erase(u);
                dist[u] = nd;
                que.insert(u);
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);

    int TS; cin >> TS;
    for (int T = 1; T <= TS; ++T) {
        int w, h, b; cin >> w >> h >> b;
        for (int i = 0; i < b; ++i) {
            cin >> rs[i].x0 >> rs[i].y0 >> rs[i].x1 >> rs[i].y1;
        }
        for (int i = 0; i < maxb; ++i) g[i].clear();
        for (int i = 0; i < b; ++i) {
            for (int j = i + 1; j < b; ++j) {
                int d = rs[i].dist(rs[j]);
                g[i] << pii(j, d);
                g[j] << pii(i, d);
            }

            g[i] << pii(b, rs[i].x0);
            g[b] << pii(i, rs[i].x0);

            g[i] << pii(b+1, w - 1 - rs[i].x1);
            g[b+1] << pii(i, w - 1 - rs[i].x1);
        }
        g[b] << pii(b+1, w);
        g[b+1] << pii(b, w);
        dijk(b);
        cout << "Case #" << T << ": " << dist[b+1] << endl;
    }

	return 0;
}
