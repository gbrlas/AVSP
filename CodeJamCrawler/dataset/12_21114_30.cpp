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
int dx[6] = {1, 0, -1, -1,  0, 1}, dy[6] = {1, 1, 0, -1, -1, 0};
int ng(PII p, PII q) {
    int ddx = p.FI - q.FI;
    int ddy = p.SE - q.SE;
    REP(i, 6) if(ddx == dx[i] && ddy == dy[i]) return i;
    return -1;
}
int s;

int corner(int i, int j) {
    if (i == 2*s-1) {
        if (j == 2*s-1) return 0;
        else if (j == s) return 5;
    }
    else if (i == s) {
        if (j == 2*s-1) return 1;
        else if (j == 1) return 4;
    } else if (i == 1) {
        if (j == s) return 2;
        else if (j == 1) return 3;
    }
    return -1;
}
int edge(int i, int j) {
    if (i == 2*s-1) return 5;
    else if (j == 2*s-1) return 0;
    else if (j-i == s-1) return 1;
    else if (i == 1) return 2;
    else if (j == 1) return 3;
    else if (i-j == s-1) return 4;
    return -1;
}
const int MN = 101;
int cmp[MN][MN];
const int MAXN = MN * MN;
vector<PII> C[MAXN];
int crn[MAXN];
int edg[MAXN][6];
int c;
int comp(int x, int y) {
    cmp[x][y] = c;
    REP(i, 6) edg[c][i] = 0;
    crn[c] = 0; 
    C[c]= vector<PII>();
    C[c].PB(MP(x,y));
    int cr = corner(x,y);
    if (cr != -1) crn[c] = 1;
    else {
        int e = edge(x, y);
        if (e != -1) edg[c][e] = 1; 
    }
    return c++;
}

bool bridge, ffork, ring;
int merge(int c1, int c2) {
    if (c1 == c2) return c1;
    if (SZ(C[c1]) < SZ(C[c2])) swap(c1, c2);
    FORE(it, C[c2]) {
        cmp[it->FI][it->SE] = c1;
        C[c1].PB(*it);
    }
    crn[c1] += crn[c2];
    int e = 0;
    REP(i, 6) {
        edg[c1][i] |= edg[c2][i];
        e += edg[c1][i];
        assert(edg[c1][i] == 0 || edg[c1][i] == 1);
    }
    if (e >= 3) ffork = true;
    if (crn[c1]>=2) bridge = true;
    return c1;
}

void solve(int tcase) {
    int m;
    scanf("%d%d", &s, &m);
    //printf("%d %d\n", s,m);
    c = 0;
    REP(i, 2*s+1) REP(j, 2*s+1) {
        cmp[i][j] = -1;
    }
    REP(i, MAXN) {
        crn[i] = 0;
        REP(t, 6) edg[i][t] = 0;
        C[i].clear();
    }
    printf("Case #%d: ", tcase);
    bool d = false;
    bridge = ffork = ring = false;
    REP(i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (!d) {
            int n[12];
            int cm = comp(x, y);
            REP(t, 6) {
                n[t] = cmp[x+dx[t]][y+dy[t]];
                n[t+6] = n[t];
            }
            REP(t, 6) {
                if (n[t] != -1) {
                    cm = merge(cm, cmp[x+dx[t]][y+dy[t]]);
                }
            }

            REP(t, 6) {
                FOR(j,1, 5) {
                    if (n[t] != -1 && n[t+1] == -1 && n[t] == n[t+j] && n[t+j+1] == -1) ring = true;
                }
            }
            if (bridge) {
                printf("bridge");
                if (ffork || ring) printf("-");
            }
            if (ffork) {
                printf("fork");
                if (ring) printf("-");
            }
            if (ring) printf("ring");
            if (bridge || ffork || ring) {
                printf(" in move %d\n", i+1);
                d = true;
            }
        }
    }
    if (!d) printf("none\n");

}

int main() {
    int t;
    scanf("%d", &t);
    s = 3;
   /* FOR(i,1, 5) FOR(j,1, 5) {
        int cr = corner(i,j);
        int e = edge(i,j);
        if (i-j >= 3 || j-i >= 3) continue;
        if (cr != -1) printf("%d %d: C %d\n", i,j,cr);
        else if (e != -1) printf("%d %d E %d\n", i,j,e);
    }*/
    REP(i, t) solve(i+1);
    return 0;
}
