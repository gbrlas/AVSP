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

string w[5010];
int p[16][256];
int l, d, n, c=0;

#define conv(x) ((int(x)+256)%256)

int play(string s) {
   bool naw = 0;
   int v = 0, m = s.length();
   c++;
   REP(x, m) {
      if (s[x] == '(') naw = 1;
      else if (s[x] == ')') naw = 0;
      else p[v][conv(s[x])] = c;
      if (!naw) v++;
   }
   int res = 0, ok = 0;;
   REP(x, d) {
      ok = 1;
      REP(y, l) if (p[y][conv(w[x][y])] != c) {
         ok = 0;
         break;
      }
      if (ok) res++;
   }
   return res;
}  

int main() {
   string s;
   ios_base::sync_with_stdio(0);
   cin >> l >> d >> n;
   REP(x, d) cin >> w[x];
   REP(x, n) {
      cin >> s;
      cout << "Case #" << x+1 << ": " << play(s) << endl;
   }
   return 0;
}
