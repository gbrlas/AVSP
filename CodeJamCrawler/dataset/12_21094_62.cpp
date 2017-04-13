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
const int MAXN = 100100;
pair<int, int> R[MAXN];
pair<int, int> pos[MAXN];
void solve(int tcase) {
    printf("Case #%d: ", tcase);
    int n, w, l;
    scanf("%d%d%d", &n, &w, &l);
    bool rev = false;
    if (w > l) {
        rev  =true;
        swap(w,l);
    }
    REP(i, n) {
        int r;
        scanf("%d",&r);
        R[i] = MP(r, i);
    }
    sort(R, R+n);
    reverse(R, R+n);
    int curX = -R[0].FI;
    int nextX = 0;
    int curY = -R[0].FI;
    REP(i,n) {
        int r = R[i].FI;
        if (curY +r > w) {
            curX = nextX;
            curY = -r;
        }
        pos[R[i].SE] = MP(max(0,curX+r), curY+r);
        curY += 2*r;
        nextX = max(nextX, curX + 2*r);
        assert(curX+r <= l);
    }
    REP(i, n) {
        assert(pos[i].FI <= l && pos[i].SE <= w);
        if (!rev) swap(pos[i].FI, pos[i].SE);
        printf("%d %d ", pos[i].FI, pos[i].SE);
    }
    printf("\n"); 
    return;

}

int main() {
    int t;
    scanf("%d", &t);
    REP(i, t) solve(i+1);
    return 0;
}
