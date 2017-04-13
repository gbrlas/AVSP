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
#define siz SIZE
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
const int MAXN = 3000;
int best[MAXN];
int H[MAXN];

int height(int c, int x, int hx, int y, int hy) {
    if (x > y) {
        swap(x, y);
        swap(hx, hy);
    }
  //  printf("%d (%d), %d (%d) : %d",x,hx,y,hy,c);
    c -= x;
    y -= x;
    x -= x;
    int delta = hx;
    hx -= delta;
    hy -= delta;
    double hc = (double) hy/y * c;
    hc += delta;
   // printf("(%lf)\n", hc);
    return ceil(hc-1);

}

bool proc(int b, int e, int hb, int he) {
    if (b+1>=e) return true;
    //printf("%d (%d) %d (%d) :\n", b,hb, e, he);
    int c = b+1;
    stack<int> S;
    while(c != e) {
        S.push(c);
        if (c > e) return false;
        c = best[c];
        
    }
    int x = b, hx = hb;
    int y = e, hy = he;
    while(!S.empty()) {
        c = S.top();
        int hc = height(c, x,hx,y,hy);
        x = y;
        hx = hy;
        y = c;
        hy = hc;
        H[c] = hc;
        //printf("%d -> %d\n", c, hc);
        if(!proc(y, x, hy, hx)) return false; 
        S.pop();
    }
    return true;

}

void solve(int tcase) {
    printf("Case #%d: ", tcase);
    int n;
    scanf("%d", &n);
    REP(i, n-1) {
        scanf("%d", &best[i]);
        --best[i];
    }
    best[n-1] = n;
    bool ok = proc(-1, n, inf, inf-1);
    if (!ok) {
        printf("Impossible\n");
    } else {
        int m = H[0];
        REP(i, n) m = min(m, H[i]);
        REP(i, n) printf("%d ", H[i]-m+1);
        printf("\n");
    }


}

int main() {
    int t;
    scanf("%d", &t);
    REP(i, t) solve(i+1);
    return 0;
}
