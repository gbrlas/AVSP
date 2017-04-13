#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <set>
#include <bitset>
#include <map>
#include <queue>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
typedef long double LD;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
//#define DEBUG
#ifdef DEBUG
#define printd(args...) printf(args)
#else
#define printd(args...)
#endif
#define scand(args...) if(scanf(args) == EOF) { \
   fprintf(stderr, "FATAL ERROR: unexpected end of file\n"); \
   exit(1); \
}
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(),(c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second
#define PF push_front
#define MP make_pair
const int INF = 1000000001;
const double EPS = 10e-9;

int main() {
    int t,n,x,s,m,ss;
    scanf("%d", &t);
    REP(i,t) {
        scanf("%d", &n);
        s = ss = 0;
        m = INF;
        REP(j,n) {
            scanf("%d", &x);
            m = min(x, m);
            s ^= x;
            ss += x;
        }
        if (s == 0)
            printf("Case #%d: %d\n", i+1, ss-m);
        else
            printf("Case #%d: NO\n", i+1);
    }
    return 0;
}
