
#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 1000007
const int MN = 50;
int dmax[MN][MN];
struct edge{
    int x,y,a;
};
vector<edge> E;
int stck[50];
int dist[50];
int route[MN];
int n,m;

bool go(int i, bool ok) {
    REP(j, i) {
        if (dist[i] - dist[j] > dmax[stck[j]][stck[i]]) {
            return false;
        }
    }
    if (stck[i] == 1) {
        if(ok){ if (i == n-1) cout << "Looks Good To Me" << endl;
        else cout << route[i]+1 << endl;}
        return true;
    }
    bool res = false;
    if (ok) res = go(i+1, true);
    if (res) return true;
    REP(e,m) {
        if (E[e].x != stck[i]) continue;
        stck[i+1] = E[e].y;
        dist[i+1] = dist[i]+E[e].a;
        bool g = go(i+1, false);
        if (g) {
            if (ok) cout << route[i]+1 << endl;
            return true;
        }
    }
    return false;

}

int solve() {
    int p;
    cin >> n >> m >> p;
    REP(i, n) REP(j, n) dmax[i][j] = INF;
    REP(i, n) dmax[i][i] = 0;
    E.clear();
    REP(i, m) {
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        --x;--y;
        edge e;
        e.x = x; e.y = y;e.a = a;
        E.PB(e);
        mini(dmax[x][y], b);
    }
    REP(k, n) REP(i, n) REP(j, n) {
        mini(dmax[i][j], dmax[i][k] + dmax[k][j]);
    }
    //   REP(i, n) {
    //        REP(j, n) cout <<  dmax[i][j] << " ";
    //       cout << endl;
    //   }
    dist[0] = stck[0] = 0;
    int d = 0;
    REP(i, p) {
        int j;
        cin >> j;
        --j;
        route[i] = j;
        stck[i+1] = E[j].y;
        d += E[j].a;
        dist[i+1] = d;
    }
    go(0, true);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(i,t) {
        cout << "Case #" << (i+1) << ": ";
        solve();
    }
    return 0;
}

