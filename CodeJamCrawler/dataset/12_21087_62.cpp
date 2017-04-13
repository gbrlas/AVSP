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
int d[MAXN], l[MAXN];
void solve(int tcase) {
    printf("Case #%d: ", tcase);
    int n;
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d", &d[i], &l[i]);
    }
    scanf("%d", &d[n]);
    priority_queue<PII> Q;
    int best = d[n];
    FORD(i, n-1, 0) {
        while (!Q.empty() && Q.top().FI >= d[i]) {
            best = min(best, d[Q.top().SE]);
            Q.pop();
        }
        int x = best - d[i];
        if (x <= l[i]) {
            Q.push(MP(d[i]-x, i));
            if (i == 0 && d[i]>=x) {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
    return;

}

int main() {
    int t;
    scanf("%d", &t);
    REP(i, t) solve(i+1);
    return 0;
}
