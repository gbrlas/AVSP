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

const int MAX = 110;

int vals[MAX], signs[MAX];
int n;

char getob() {
    char c;
    do {
        c = getchar();
    } while(c != 'O' && c != 'B');
    if (c=='O') c='A';
    return c;
}

void getnext(char c, int& x) {
    do {
        x++;
    } while(x < n && signs[x] != c);
}

void play(int nr) {
    int x;
    scanf("%d", &n);

    REP(i,n) {
        signs[i] = getob();
        scanf("%d", &vals[i]);
    }

    int ia, ib, s, pa, pb;
    ia=ib=s=0;
    pa=pb=1;
    if (signs[0] == 'A') getnext('B', ib);
    else getnext('A', ia);

    while (ia<n || ib<n) {
        if (ia<n && pa == vals[ia] && ia<ib) {
            printd("1. pa=%d pb=%d ia=%d ib=%d\n", pa, pb, ia, ib);
            s++;
            getnext('A', ia);
            if (ib<n) {
                if (vals[ib] > pb) pb++;
                else if (vals[ib] < pb) pb--;
            }
        }
        else if (ib<n && pb == vals[ib] && ib<ia) {
            printd("2. pa=%d pb=%d ia=%d ib=%d\n", pa, pb, ia, ib);
            s++;
            getnext('B', ib);
            if (ia<n) {
                if (vals[ia] > pa) pa++;
                else if (vals[ia] < pa) pa--;
            }
        }
        else {
            printd("3. pa=%d pb=%d ia=%d ib=%d\n", pa, pb, ia, ib);
            int ta = (ia<n && abs(vals[ia]-pa)>0) ? abs(vals[ia]-pa) : INF;
            int tb = (ib<n && abs(vals[ib]-pb)>0) ? abs(vals[ib]-pb) : INF;
            int t = min(ta, tb);
            s += t;
            if (ia<n) {
                if (vals[ia] > pa) pa += t;
                else if (vals[ia] < pa) pa -= t;
            }
            if (ib<n) {
                if (vals[ib] > pb) pb += t;
                else if (vals[ib] < pb) pb -= t;
            }
        }
    }
    printf("Case #%d: %d\n", nr, s);
}

int main() {
    int t;
    scanf("%d", &t);
    REP(i, t) play(i+1);
    return 0;
}
