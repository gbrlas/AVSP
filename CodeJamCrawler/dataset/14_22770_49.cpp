#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}
const int MX = 110;
LL G[110][210][1100];
LL H[110][210][1100];
const LL INF = 1e18;

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int p,q,n;
    cin >> p >> q >> n;
    VI h(n+1), g(n+1);
    int kmax = 1;
    REP(i,n) cin >> h[i] >> g[i];
    REP(i, n) kmax += 1+h[i]/p;
    REP(i,n+1) REP(j, 201) REP(k, kmax+1) G[i][j][k] = H[i][j][k] = -INF;
    G[0][h[0]][0] = 0;
   /* if (tc == 74) {
        debugv(h);debugv(g);debug(MP(p,q));
    }*/
    REP(i, n) FORD(j, h[i], 1) REP(k, kmax) {
        // use
        LL gv = G[i][j][k];
        maxi(H[i][j][k], gv);
        LL hv = H[i][j][k];
        if (k > 0) {
           int jj = j-p;
           if (jj > 0) {
               maxi(G[i][jj][k-1], gv);
               maxi(H[i][jj][k-1], hv);
            } else {
               maxi(G[i+1][h[i+1]][k-1], gv+g[i]);
               maxi(H[i+1][h[i+1]][k-1], hv+g[i]);
            }
        }
        // shoot
        if (k < kmax) maxi(H[i][j][k+1], gv);
        int jj = j-q;
        if (jj > 0) maxi(G[i][jj][k], hv);
        else maxi(G[i+1][h[i+1]][k], hv); 
    }
    LL res = max(G[n][0][0], H[n][0][0]);
    cout << res << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}

