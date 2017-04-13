#include<algorithm>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define fup FOR
#define fdo FORD
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x).size())
#define SZ SIZE
#define CLR memset((x),0,sizeof (x))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SQR(a) ((a)*(a))

#define DEBUG 1
#define debug(x) {if(DEBUG) cerr << #x << " = " << x << endl;}
#define debugv(x) {if(DEBUG) {cerr << #x << " = "; FORE(it,(x)) cerr << *it << " . "; cerr  <<endl;}}

using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef VI vi;
typedef LL lli;

const int inf = 1000000000;

struct game {
    game(): t(0), p(0) {}
    int t, p, i;
    bool operator < (game const& g) const {
        if (p == 0 && g.p == 0) return i < g.i;
        if (p == 0) return false;
        if (g.p == 0) return true;
        int d = (100-g.p)*t - (100-p)*g.t;
        if (d < 0) return false;
        if (d > 0) return true;
        return i < g.i;
    }
};
game G[1010];
void solve(int tcase) {
    int n;
    scanf("%d", &n);
    REP(i, n) {
        int t;
        scanf("%d", &t);
        G[i].i = i;
        G[i].t = t;
    }
    REP(i, n) {
        int p;
        scanf("%d", &p);
        G[i].p = p;
    }
    sort(G, G+n);
    printf("Case #%d:", tcase);
    REP(i, n) {
        printf(" %d", G[i].i);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    REP(i, t) solve(i+1);
    return 0;
}
